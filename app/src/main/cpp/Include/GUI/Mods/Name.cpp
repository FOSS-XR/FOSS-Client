#include "BNMResolve.hpp"
#include "PhotonResolve.hpp"
#include "BNM/Property.hpp"
#include "Name.hpp"

void Name::SetName() {
  PhotonNetwork::GetLocalPlayer()->SetNickname("FOSS XR - FOSS CLIENT");
}
void Name::BigName() {
  PhotonNetwork::GetLocalPlayer()->SetNickname("<size=4><FOSS XR - FOSS CLIENT></size>");
}
void Name::PingName() {
    PhotonNetwork::GetLocalPlayer()->SetNickname("@everyone");
}
