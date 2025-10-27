#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <GUIInclude.hpp>
#include <BNMIncludes.hpp>
#include <GUI/Mods/ModsIncludes.hpp>

//Example for including Mod files
//#include <Mods/ModPage.hpp>

//Only if you have my NotificationLib!
//#include <NotiLib/NotiLib.hpp>

using namespace std;
class Buttons {
private:
    inline static void ChangeCat(int i) {
        GUISettings::categoryIndex = i;
        GUISettings::pageIndex = 0;
        GUISettings::cursorIndex = 0;
    }




public:
    inline static std::vector<std::vector<Button>> buttons = {
            {//Main Page - 1
                Button { .name = "Settings", .method = []() { ChangeCat(1); }, .type = "button",},
                Button { .name = "Movement", .method = []() { ChangeCat(2); }, .type = "button"},
                Button { .name = "Name", .method = []() { ChangeCat(3); }, .type = "button"},
                Button { .name = "Photon", .method = []() { ChangeCat(4); }, .type = "button"},
                Button { .name = "Credits", .method = []() { ChangeCat(5); }, .type = "button"}

            },
            {//Settings Page - 2
                Button { .name = "Back", .method = []() { ChangeCat(0); }, .type = "button"},
                Button { .name = "Menu Theme", .type = "slider", .maxSlide = 6, .slideNames = std::vector<std::string>{ "default", "rainbow", "red", "blue", "lmko", "mre", "jae" }},
            },
            {//Movement - 3 
                Button { .name = "Back", .method = []() { ChangeCat(0); }, .type = "button"},
                Button { .name = "Fly", .enableMethod = Movement::Fly, .type = "toggle", .tooltip = "Head Fly" },
                Button { .name = "Slingshot Fly", .enableMethod = Movement::SlingshotFly, .type = "toggle", .tooltip = "Hand Fly" },
                Button { .name = "Longarms", .enableMethod = []() {Movement::Longarms(true); }, .disableMethod = []() { Movement::Longarms(false); }, .type = "toggle",.tooltip = "Toggles Longarms"},
                Button { .name = "Up & Down", .enableMethod = []() {Movement::UpAndDown(true); }, .disableMethod = []() { Movement::UpAndDown(false); }, .type = "toggle",.tooltip = "Toggles Up & Down"},
                Button { .name = "Car Monke", .type = "toggle", .tooltip = "Driving in my car right after a beer" },
                Button { .name = "Speedboost", .type = "toggle",  .enableMethod = []() {Movement::Speedboost(1.5f); }, .disableMethod = []() {Movement::Speedboost(1.0f); }, .tooltip = "Driving in my car right after a beer" }


            },
            {//Name - 4
                Button { .name = "Back", .method = []() { ChangeCat(0); }, .type = "button"},
                Button { .name = "baggZ Glaze Name", .method = []() {Name::SetName("baggZ On Top");}, .type = "button", .tooltip = "glazer"},
                Button { .name = "Big Name", .method = Name::BigName, .type = "button", .tooltip = "glazer"},
                Button { .name = "No Name", .method = []() {Name::SetName("");}, .type = "button", .tooltip = "no name"},
                Button { .name = ":3 Name", .method = []() {Name::SetName("<color=pink>:3</color >");}, .type = "button", .tooltip = "nya~"}


            },
            {//Photon - 5
                Button { .name = "Back", .method = []() { ChangeCat(0); }, .type = "button"},
                Button { .name = "Leave Room", .method = Photon::LeaveRoom, .type = "button"}

            },
            {//Credits - 6
                    Button { .name = "Back", .method = []() { ChangeCat(0); }, .type = "button"},
                    Button { .name = "Pubert - Made the GUI also helped with mods", .type = "button"}

            }
    };
};




