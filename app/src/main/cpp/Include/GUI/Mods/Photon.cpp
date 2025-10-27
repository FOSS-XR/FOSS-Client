#include "Photon.hpp"
#include "BNMResolve.hpp"
#include "PhotonResolve.hpp"
#include "BNM/Property.hpp"
#include "XRInput.hpp"

void Photon::CrashAll() {
    Player* player = PhotonNetwork::GetLocalPlayer();
    PhotonNetwork::SetMasterClient(player);
    PhotonNetwork::DestroyPlayerObjects(player);
    PhotonNetwork::DestroyPlayerObjects(player);
    PhotonNetwork::DestroyPlayerObjects(player);
    PhotonNetwork::DestroyPlayerObjects(player);
    PhotonNetwork::DestroyPlayerObjects(player);
    PhotonNetwork::DestroyPlayerObjects(player);
    PhotonNetwork::DestroyPlayerObjects(player);
}
void Photon::LeaveRoom() {
  PhotonNetwork::LeaveLobby();
}