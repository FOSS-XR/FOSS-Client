#include "Movement.hpp"
#include "BNMResolve.hpp"
#include "XRInput.hpp"

using namespace std;

void Movement::Longarms(float length) {
    GameObject::Find("GorillaPlayer")->GetTransform()->SetLocalScale(Vector3(length, length, length));
    }
}
void Movement::Fly() {
        float trigR = XRInput::GetFloatFeature(FloatFeature::Trigger, Controller::Right);
        if (trigR > 0.5f) {
            Transform *handR = GameObject::Find("RightHand Controller")->GetTransform();
            Rigidbody *rigidbody = (Rigidbody *) GameObject::Find("GorillaPlayer")->GetComponent(Rigidbody::GetType());
            Vector3 force = handR->GetForward() * 1.0f;
            rigidbody->AddForce(force, ForceMode::VelocityChange);
    }
}

void Movement::UpAndDown() {
    {
        bool upDownEnabled = false;
        if (!upDownEnabled)
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
