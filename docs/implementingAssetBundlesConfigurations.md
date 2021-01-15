# Implementing Asset Bundles Configurations

* **[Configuration in Console](#configuration-in-console)**
* **[Using Asset Bundles in the SDK](#using-asset-bundles-in-the-sdk)**

---

> [!NOTE]
> This feature is only supported if your game is using Unity.

Asset Bundles are files created in the Unity editor during edit-time, which can be used later by a build of a project at run-time. Asset Bundles can contain asset files such as models, materials, textures, and scenes. Asset Bundles cannot contain scripts. Asset Bundles allow on-demand streaming and loading of Assets from a local or remote location. With Asset Bundles, Assets can be stored remotely and accessed as needed, increasing the flexibility of the project and reducing the initial application size. Asset Bundles configurations can be done through the Gamedock Console, and as so please ask your Product Manager to configure this before starting the implementation of this feature.

More information on what you can do with Asset Bundles can be found here:

[https://docs.unity3d.com/Manual/AssetBundlesIntro.html](https://docs.unity3d.com/Manual/AssetBundlesIntro.html)
[https://learn.unity.com/tutorial/assets-resources-and-assetbundles](https://learn.unity.com/tutorial/assets-resources-and-assetbundles)

### Configuration in Console

**To Be Added Soon**

### Using Asset Bundles in the SDK

The Asset Bundles configuration is automatically retrieved when the Gamedock SDK is first initialized. The configurations are then stored locally so that they can be used by the game, even when offline if they were cached. When the Gamedock SDK is initialized and the request has been done, the following callbacks are fired:

~~~csharp
// Available
// Fired also offline if a previous configuration was stored (list was not empty)
Gamedock.Instance.AssetBundlesCallbacks.OnAssetBundlesAvailable -= OnAssetBundlesAvailable;
Gamedock.Instance.AssetBundlesCallbacks.OnAssetBundlesAvailable += OnAssetBundlesAvailable;
void OnAssetBundlesAvailable(){}

// Not available
Gamedock.Instance.AssetBundlesCallbacks.OnAssetBundlesNotAvailable -= OnAssetBundlesNotAvailable;
Gamedock.Instance.AssetBundlesCallbacks.OnAssetBundlesNotAvailable += OnAssetBundlesNotAvailable;
void OnAssetBundlesNotAvailable(){}
~~~

Once the Asset Bundles are available you can get a dedicated helper class using the following method:

~~~csharp
//List of all asset bundles
Gamedock.Instance.AssetBundles.AssetBundles

//Get Asset Bundle with name
AssetBundle assetBundle = Gamedock.Instance.AssetBundles.GetAssetBundle("goldplane");

//Get Asset Bundles of Type
List<AssetBundle> assetBundles = Gamedock.Instance.AssetBundles.GetAssetBundlesOfType("level");

//Check if asset bundle is valid
bool valid = assetBundle.IsValid();
~~~

The following functionalities are available in the AssetBundleHelper:
* Get a full list of AssetBundle objects
* Get an AssetBundle object by name
* Get a list of AssetBundles by a specific type (“level”, “event”, “cards”)
* Check if an AssetBundle is in the list and it is valid (end date has not expired)

For each AssetBundle object you have the following configurations that can be done in the Console:
* A name based on which it can be retrieved/identify
* A type which can be applied to several other AssetBundles (“level”, “event”, “cards”)
* An end date specifying until what time the AssetBundle should be used; It can also be checked with the IsValid method
* A hash and a version values that can be used in the AssetBundle system of Unity to cache the downloaded AssetBundle