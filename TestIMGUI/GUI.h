#pragma once
#include "imgui.h"
void draw_gui();
inline void draw_gui() {
  ImGui::Begin(u8"Debug Window");// u8 for chinese,but do not make sense
  ImGui::Text("hu hu");

  ImDrawList *list = ImGui::GetForegroundDrawList();

  list->AddRectFilled(ImVec2(0, 0), ImGui::GetMousePos(), ImColor(60,255,51));

  ImGui::End();
}
