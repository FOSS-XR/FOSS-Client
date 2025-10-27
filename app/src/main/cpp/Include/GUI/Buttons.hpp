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
                Button { .name = "Longarms", .enableMethod = []() {Movement::Longarms(true); }, .disableMethod = []() { Movement::Longarms(false); }, .type = "toggle",.tooltip = "Toggles Longarms"},
                Button { .name = "Up & Down", .enableMethod = []() {Movement::UpAndDown(true); }, .disableMethod = []() { Movement::UpAndDown(false); }, .type = "toggle",.tooltip = "Toggles Up & Down"},
            },
            {//Name - 4
                Button { .name = "Back", .method = []() { ChangeCat(0); }, .type = "button"},
                Button { .name = "Foss XR Name", .method = Name::SetName, .type = "button"}
                Button { .name = "Big Name", .method = Name::BigName, .type = "button", .tooltip = "glazer"},


            },
            {//Photon - 5
                Button { .name = "Back", .method = []() { ChangeCat(0); }, .type = "button"},
                Button { .name = "Leave Room", .method = Photon::LeaveRoom, .type = "button"}

            },
            {//Credits - 6
                    Button { .name = "Back", .method = []() { ChangeCat(0); }, .type = "button"},
                    Button { .name = "Pubert - Made the GUI also helped with mods", .type = "button"}
                    Button { .name = "Fish - helped with mods and fixed every mod", .type = "button"}
                    Button { .name = "Basic - contributer and fixed some mods", .type = "button"}
            }
    };
};




