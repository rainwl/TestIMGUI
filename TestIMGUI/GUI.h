#pragma once
#include "imgui.h"
void draw_gui();
inline void draw_gui() {
  ImGui::Begin(u8"Debug Window");// u8 for chinese,but do not make sense
  ImGui::Text("hu hu");



  ImGui::End();
}
