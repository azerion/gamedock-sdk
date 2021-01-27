//
//  NotificationService.swift
//  NService
//
//  Created by Andrey Ildyakov on 09/12/2020.
//  Copyright © 2020 Frank Slofstra. All rights reserved.
//

import UserNotifications

@available(iOS 10.0, *)
class NotificationService: UNNotificationServiceExtension {

    var contentHandler: ((UNNotificationContent) -> Void)?
    var bestAttemptContent: UNMutableNotificationContent?

    override func didReceive(_ request: UNNotificationRequest, withContentHandler contentHandler: @escaping (UNNotificationContent) -> Void) {
        self.contentHandler = contentHandler
        bestAttemptContent = (request.content.mutableCopy() as? UNMutableNotificationContent)
        print("HANDLE PUSH, didReceiveNotificationRequest")
        
        let userInfo = request.content.userInfo
        guard !userInfo.isEmpty else {contentComplete();return}
        guard let userInfoValue = userInfo["userInfo"] as? [AnyHashable : Any], let mediaUrl = userInfoValue["imageUrl"] as? String else {contentComplete();return}
        // load the attachment
        loadAttachmentForUrlString(urlString: mediaUrl, type: "jpg") { (attachment) in
                self.bestAttemptContent?.attachments = [attachment]
            self.contentComplete()
        }
    }
    
    override func serviceExtensionTimeWillExpire() {
        // Called just before the extension will be terminated by the system.
        // Use this as an opportunity to deliver your "best attempt" at modified content, otherwise the original push payload will be used.
        if let contentHandler = contentHandler, let bestAttemptContent =  bestAttemptContent {
            contentHandler(bestAttemptContent)
        }
    }
    func contentComplete() {
        guard let bestAttemptContent = bestAttemptContent else {return}
        self.contentHandler?(bestAttemptContent)
    }
    func fileExtensionForMediaType(type: String) -> String {
        var ext = type
        if type == "image" {
            ext = "jpg"
        }
        if type == "video" {
            ext = "mp4"
        }
        if type == "audio" {
            ext = "mp3"
        }
        return "."+ext
    }
    func loadAttachmentForUrlString(urlString: String, type: String, completionHandler:@escaping(UNNotificationAttachment)->()) {
        
        var attachment: UNNotificationAttachment?
        guard let attachmentURL = URL(string:urlString) else {return}
        let fileExt = fileExtensionForMediaType(type: type)
        
        
        let session = URLSession.init(configuration: .default)
        session.downloadTask(with: attachmentURL) { (temporaryFileLocation, response, error) in
            if let error = error {print("[NotificationService]",error.localizedDescription)} else
            {
                let fileManager = FileManager.default
                guard let temporaryFileLocation = temporaryFileLocation else {return}
                let localUrl = URL.init(fileURLWithPath: temporaryFileLocation.path+fileExt)
                do {
                try fileManager.moveItem(at: temporaryFileLocation, to: localUrl)
                    do {
                        try attachment = UNNotificationAttachment.init(identifier: "", url: localUrl, options: nil)
                        if let attachment = attachment {
                        completionHandler(attachment)
                        } else {
                            print("[NotificationService] Error")
                        }
                    } catch let error {
                        print("[NotificationService]",error.localizedDescription)
                    }
                } catch let error {
                    print("[NotificationService]",error.localizedDescription)
                }
            }
        }.resume()
    }
}
