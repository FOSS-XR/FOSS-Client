#include <BNMIncludes.hpp>

class Name {

public:static void SetName(string name) {
        Class photonClass = Class("Photon.Pun", "PhotonNetwork", Image("PhotonUnityNetworking"));


        if (photonClass.IsValid()) {
            Method<void> SetNameBoi = photonClass.GetMethod("set_NickName", 1);
            if (SetNameBoi.IsValid()) {
                Mono::String *emptyName = CreateMonoString(name);
                SetNameBoi(emptyName);
            }
        }
    }

public:static void BigName()
    {
        Class photonClass = Class("Photon.Pun", "PhotonNetwork", Image("PhotonUnityNetworking"));

        if (photonClass.IsValid()) {
            Method<void> SetNameBoi = photonClass.GetMethod("set_NickName", 1);
            if (SetNameBoi.IsValid()) {
                Mono::String *emptyName = CreateMonoString("<size=300%>" + photonClass.GetMethod("get_NickName").str() + "</size>");
                SetNameBoi(emptyName);
            }
        }
    }
};