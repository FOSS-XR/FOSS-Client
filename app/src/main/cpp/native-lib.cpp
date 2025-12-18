#include <jni.h>
#include "BNM/Loading.hpp"
#include "BNM/Class.hpp"
#include "BNMResolve.hpp"
#include <httplib.h>
#include <json.hpp>
#include "Include/GUI/ModGUI.hpp"
#include <Player.hpp>

 Il2CppObject playerInstance;

void (*Awake)(void*);
void new_Awake(void* instance) {
    Awake(instance);
    Player::Init();
    ModGUI::Init();
}

void (*LateUpdate)(void*);
void new_LateUpdate(void* instance) {
    LateUpdate(instance);

    ModGUI::Update();
}

void OnLoaded() {
    BNM_LOG_INFO("Loaded Successfully");

    InvokeHook(Class("GorillaLocomotion", "Player", Image(
            "Assembly-CSharp.dll")).GetMethod("LateUpdate"), new_LateUpdate, LateUpdate);

    InvokeHook(Class("GorillaLocomotion", "Player", Image(
            "Assembly-CSharp.dll")).GetMethod("Awake"), new_Awake, Awake);
}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, [[maybe_unused]] void *reserved) {
    JNIEnv *env;
    vm->GetEnv((void **) &env, JNI_VERSION_1_6);

    BNM::Loading::AddOnLoadedEvent(OnLoaded);

    BNM::Loading::TryLoadByJNI(env);

    return JNI_VERSION_1_6;
}
