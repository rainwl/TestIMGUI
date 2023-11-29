#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#pragma comment(lib, "../API/GLFW/glfw3.lib")
#pragma comment(lib, "../API/GLEW/glew32s.lib")
#pragma comment(lib, "Opengl32.lib")

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include <iostream>
#include <string>

GLFWwindow *window;

int main() {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  window = glfwCreateWindow(800, 600, "TestImGUI", nullptr, nullptr);
  glfwMakeContextCurrent(window);
  glfwSwapInterval(0);

  IMGUI_CHECKVERSION();
  ImGui::CreateContext(nullptr);
  ImGuiIO &io = ImGui::GetIO();
  (void) io;

  ImGui::StyleColorsDark();
  ImGui_ImplGlfw_InitForOpenGL(window, true);
  ImGui_ImplOpenGL3_Init("#version 330");

  std::string text = "hello world 123";
  char text_box[50]{"Text box"};

  ImVec4 color;

  while (!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT);

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    ImGui::Begin("MyImguiWindow");

    ImGui::Text(text.c_str());
    if (ImGui::Button("MyButton")) {
      std::cout << "\n Button Down \n";
      text = "You click the button";
    }

    ImGui::InputText("Test Text Box", text_box, IM_ARRAYSIZE(text_box));

    ImGui::BeginListBox("xixi");
    for (size_t i = 0; i < 100; ++i) { if (ImGui::Selectable(std::to_string(i).c_str(), std::to_string(i) == text)) { text = std::to_string(i); } }
    ImGui::EndListBox();

    if (ImGui::BeginCombo("aa", text.c_str())) {
      for (int i = 0; i < 100; ++i) { if (ImGui::Selectable(std::to_string(i).c_str())) { text = std::to_string(i); } }
      ImGui::EndCombo();
    }

    ImGui::ColorEdit4("Text Color", (float *) &color,ImGuiColorEditFlags_::ImGuiColorEditFlags_AlphaBar);

    ImGui::End();

    ImGui::ShowDemoWindow();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    glfwSwapBuffers(window);
    glfwPollEvents();
  }
}
