#include <BNMIncludes.hpp>
#include <XRInput.hpp>
#include <BNMResolve.hpp>

class Movement{

public:static void Longarms(bool active) {
        if (active)
        {
            GameObject::Find("GorillaPlayer")->GetTransform()->SetLocalScale(Vector3(1.5f, 1.5f, 1.5f));
        }
        else
        {
            GameObject::Find("GorillaPlayer")->GetTransform()->SetLocalScale(Vector3(1.0f, 1.0f, 1.0f));
        }
    }

public:static void Speedboost(BNM::IL2CPP::Il2CppObject* self, float speed) {
        BNM::Field<float> jumpMultiplier = Class(self).GetField("jumpMultiplier");
        jumpMultiplier.SetInstance(self);

        jumpMultiplier = speed;
    }

public:static void Fly()
    {
        float trigR = XRInput::GetFloatFeature(FloatFeature::Trigger, Controller::Right);
        if (trigR > 0.5f) {
            Transform *handR = GameObject::Find("RightHand Controller")->GetTransform();
            Rigidbody *rigidbody = (Rigidbody *) GameObject::Find("GorillaPlayer")->GetComponent(
                    Rigidbody::GetType());
            Vector3 force = handR->GetForward() * 15.0f;
            rigidbody->SetVelocity(force);
        }
    }

public:static void Car()
    {
        float trigR = XRInput::GetFloatFeature(FloatFeature::Trigger, Controller::Right);
        if (trigR > 0.5f) {
            Transform *Cam = GameObject::Find("Main Camera")->GetTransform();
            Rigidbody *rigidbody = (Rigidbody *) GameObject::Find("GorillaPlayer")->GetComponent(
                    Rigidbody::GetType());
            Vector3 Camforce = Cam->GetForward() * 15.0f;
            Vector3 force = Vector3(Camforce.x, 0.0f, Camforce.z);
            rigidbody->SetVelocity(Camforce);
        }
    }
public:static void SlingshotFly()
    {
        float trigR = XRInput::GetFloatFeature(FloatFeature::Trigger, Controller::Right);
        if (trigR > 0.5f) {
            Transform *handR = GameObject::Find("RightHand Controller")->GetTransform();
            Rigidbody *rigidbody = (Rigidbody *) GameObject::Find("GorillaPlayer")->GetComponent(Rigidbody::GetType());
            Vector3 force = handR->GetForward() * 1.0f;
            rigidbody->AddForce(force, ForceMode::VelocityChange);
        }
    }
public:static void UpAndDown(bool active)
    {

        if (!active)
        {
            return;
        }

        Vector3 Up(Vector3(0, 1, 0));
        Vector3 Down(Vector3(0, -1, 0));

        float trigR = XRInput::GetFloatFeature(FloatFeature::Trigger, Controller::Right);
        float trigL = XRInput::GetFloatFeature(FloatFeature::Trigger, Controller::Left);
        Rigidbody *rigidbody = (Rigidbody *) GameObject::Find("GorillaPlayer")->GetComponent(Rigidbody::GetType());

        if (trigR > 0.5f)
        {
            rigidbody->AddForce(Up, ForceMode::VelocityChange);
        }
        if (trigL > 0.5f)
        {
            rigidbody->AddForce(Down, ForceMode::VelocityChange);
        }
    }
};