#include "Movement.hpp"
#include "BNMResolve.hpp"
#include "XRInput.hpp"
#include <Player.hpp>

using namespace std;

void Movement::Longarms(float length) {
    GameObject::Find("GorillaPlayer")->GetTransform()->SetLocalScale(Vector3(length, length, length));
    }

void Movement::Fly() {
    float trigR = XRInput::GetFloatFeature(FloatFeature::Trigger, Controller::Right);
    if (trigR > 0.5f) {
        Transform *handR = Player::handR->GetTransform();
        Rigidbody *rigidbody = (Rigidbody *) GameObject::Find("GorillaPlayer")->GetComponent(
                Rigidbody::GetType());
        Vector3 force = handR->GetForward() * 1.0f;
        rigidbody->SetVelocity(force);
    }
}

void Movement::SlingshotFly() {
    float trigR = XRInput::GetFloatFeature(FloatFeature::Trigger, Controller::Right);
    if (trigR > 0.5f) {
        Transform *handR = Player::handR->GetTransform();
        Rigidbody *rigidbody = (Rigidbody *) GameObject::Find("GorillaPlayer")->GetComponent(
                Rigidbody::GetType());
        Vector3 force = handR->GetForward() * 1.0f;
        rigidbody->AddForce(force, ForceMode::VelocityChange);
    }
}

void Movement::Platforms()
{
    GameObject* platR = nullptr;
    GameObject* platL = nullptr;
    bool gripR = XRInput::GetBoolFeature(BoolFeature::GripButton, Controller::Right);
    bool gripL = XRInput::GetBoolFeature(BoolFeature::GripButton, Controller::Left);

    if(gripR) {
        if(!platR) {
            platR = GameObject::CreatePrimitive(PrimitiveType::Cube);
            Renderer* renderer = (Renderer*)platR->GetComponent(Renderer::GetType());
            if (renderer) {
                Material* mat = renderer->GetMaterial();
                if (mat) mat->SetColor(Color(0.0f, 0.0f, 1.0f));
            }
            platR->GetTransform()->SetLocalScale(Vector3(0.025f, 0.3f, 0.4f));
            platR->GetTransform()->SetLocalRotation(Player::handR->GetTransform()->GetRotation());
            platR->GetTransform()->SetLocalPosition(Player::handR->GetTransform()->GetPosition());
        }
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
