# Gamedock SDK v5.0.0

The Gamedock SDK is designed to give developers access to Gamedock Console functions and communicate with the Gamedock backend.

**IMPORTANT! If you are experiencing issues with missing scripts on some of our Editor prefabs, it is caused by Unity not importing properly some of it's components. In order to fix it please download [this](https://splashscreens.cdn.spilcloud.com/files/1574351079_Prefabs.zip) package and overwrite the folder "Assets/Gamedock/Editor/Prefabs".** 

## Installation

### Android

You can add gamedock and it's dependancies to your gradle file:
```
    
    implementation 'io.gamedock.sdk:gamedock-sdk:5.1.0' /* Gamedock Main Module */
    
    implementation 'com.google.firebase:firebase-analytics:18.0.2' /* Gamedock Firebase */
    implementation 'com.google.firebase:firebase-crashlytics:17.4.0' /* Gamedock Firebase */
    implementation 'com.google.firebase:firebase-crashlytics-ndk:17.4.0' /* Gamedock Firebase */
    implementation 'com.google.firebase:firebase-messaging:21.0.1' /* Gamedock Firebase */
    implementation 'com.google.firebase:firebase-dynamic-links:19.1.1' /* Gamedock Firebase */
    implementation 'com.google.firebase:firebase-config:20.0.4' /* Gamedock Firebase */
    
    implementation 'androidx.multidex:multidex:2.0.1' /* Gamedock Dependency */
    implementation 'androidx.appcompat:appcompat:1.2.0' /* Gamedock Dependency */
    implementation 'androidx.recyclerview:recyclerview:1.1.0' /* Gamedock Dependency */
    implementation 'androidx.cardview:cardview:1.0.0' /* Gamedock Dependency */
    implementation 'com.google.android.gms:play-services-analytics:17.0.0' /* Gamedock Dependency */
    implementation 'com.google.android.gms:play-services-basement:17.4.0' /* Gamedock Dependency */
    implementation 'com.google.android.gms:play-services-games:20.0.1' /* Gamedock Dependency */
    implementation 'com.google.android.gms:play-services-auth:18.0.0' /* Gamedock Dependency */
    implementation 'com.google.android.gms:play-services-drive:17.0.0' /* Gamedock Dependency */
    implementation 'com.google.android.gms:play-services-nearby:17.0.0' /* Gamedock Dependency */
    implementation 'io.reactivex.rxjava2:rxandroid:2.1.1' /* Gamedock Dependency */
    implementation 'io.reactivex.rxjava2:rxjava:2.2.19' /* Gamedock Dependency */
```

### Cordova:
```
npm install @gamedock/cordova
```

## Documentation
Documentation can be found <a href="https://azerion.github.io/gamedock-sdk/#/">here</a>

## Change Log
The change log can be found [here](./CHANGELOG.md)
