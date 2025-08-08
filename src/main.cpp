#include "backends/imgui_impl_glfw.h"
#include "bap.hpp"
#include "imgui.h"
#include "imgui_impl_opengl3.h"

int main() {
  MGL_makeWindow(800, 600, "My Window");

  GLFWwindow* window = mgl_frame;

  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO();
  (void)io;
  ImGui::StyleColorsDark();

  ImGui_ImplGlfw_InitForOpenGL(window, true);
  ImGui_ImplOpenGL3_Init("#version 330");

  while (!MGL_windowShouldClose()) {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    ImGui::Begin("Hello ImGui");
    ImGui::Text("Running inside my own GLFW window!");
    ImGui::End();

    MGL_beginDrawing();
    MGL_clearBackground(20, 20, 20);

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    MGL_endDrawing();
  }

  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();

  MGL_closeWindow();
  return 0;
}
