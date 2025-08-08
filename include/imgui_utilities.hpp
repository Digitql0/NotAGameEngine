#ifndef IMGUI_UTILITIES_HPP
#define IMGUI_UTILITIES_HPP

#include "imgui.h"
#include "imgui_impl_opengl3.h"
#include "backends/imgui_impl_glfw.h"
#include "bap.hpp"

inline void initImgui() {
    GLFWwindow* window = mgl_frame;  // Get your GLFW window from your lib

  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO();
  (void)io;
  ImGui::StyleColorsDark();

  ImGui_ImplGlfw_InitForOpenGL(window, true);
  ImGui_ImplOpenGL3_Init("#version 330");
}

#endif
