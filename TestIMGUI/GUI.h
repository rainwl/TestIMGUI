#pragma once
#include "imgui.h"

#include <iostream>
void draw_gui();
inline void draw_gui() {
  ImGui::Begin(u8"Debug Window");// u8 for chinese,but do not make sense
  ImGui::Text("hu hu");

  //ImDrawList *list = ImGui::GetForegroundDrawList();
  //list->AddRectFilled(ImVec2(0, 0), ImGui::GetMousePos(), ImColor(60,255,51));
  if (ImGui::IsKeyPressed(ImGuiKey_Q)) {
    std::cout << "xixi";
  }
  if (ImGui::IsKeyPressed(static_cast<ImGuiKey>(562))) {
    std::cout << "hhh";
  }

  ImGui::End();
}
