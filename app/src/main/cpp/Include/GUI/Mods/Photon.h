#include <BNMIncludes.hpp>

class Photon
{
public:static void LeaveRoom()
    {
        Class photonClass = Class("Photon.Pun", "PhotonNetwork", Image("PhotonUnityNetworking"));

        Method<void *> disconnect = photonClass.GetMethod("Disconnect");
        if (disconnect.IsValid()) {
            disconnect();
        }
    }
public:static void SpawnPrefab(string PrefabName)
    {
        Transform *handR = GameObject::Find("RightHand Controller")->GetTransform();
        float gripR = XRInput::GetFloatFeature(FloatFeature::Grip, Controller::Right);
        Class photonClass = Class("Photon.Pun", "PhotonNetwork");

        Method<void *> Instantiate = photonClass.GetMethod("Instantiate");
        if (Instantiate.IsValid() && gripR > 0.5f)
        {
            Instantiate(PrefabName, handR->GetPosition(), handR->GetRotation(), 0, nullptr);
        }
    }
};