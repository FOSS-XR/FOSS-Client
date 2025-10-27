#include "Movement.hpp"
#include "BNMResolve.hpp"
#include "XRInput.hpp"

using namespace std;

void Movement::Longarms(bool active) {
        if (active)
        {
            GameObject::Find("GorillaPlayer")->GetTransform()->SetLocalScale(Vector3(1.5f, 1.5f, 1.5f));
        }
        else
        {
            GameObject::Find("GorillaPlayer")->GetTransform()->SetLocalScale(Vector3(1.0f, 1.0f, 1.0f));
        }
    }
}
void Movement::Fly() {
    float trig = XRInput::GetFloatFeature(FloatFeature::Trigger, Controller::Right);
    if (trig > 0.5f) {
        Transform* mainCam = GameObject::Find("Main Camera")->GetTransform();
        Rigidbody* rb = (Rigidbody*)GameObject::Find("GorillaPlayer")
                ->GetComponent(Rigidbody::GetType());
        Vector3 force = mainCam->GetForward() * 1.0f; // adjust force multiplier as needed
        rb->AddForce(force, ForceMode::VelocityChange);
    }
}
void Movement::SlingShotFly
        float trigR = XRInput::GetFloatFeature(FloatFeature::Trigger, Controller::Right);
        if (trigR > 0.5f) {
            Transform *Cam = GameObject::Find("Main Camera")->GetTransform();
            Rigidbody *rigidbody = (Rigidbody *) GameObject::Find("GorillaPlayer")->GetComponent(
                    Rigidbody::GetType());
            Vector3 Camforce = Cam->GetForward() * 15.0f;
            Vector3 force = Vector3(Camforce.x, 0.0f, Camforce.z);
            rigidbody->SetVelocity(Camforce);
