// dear imgui: "null" example application
// (compile and link imgui, create context, run headless with NO INPUTS, NO GRAPHICS OUTPUT)
// This is useful to test building, but you cannot interact with anything here!
#include "imgui.h"
#include <stdio.h>

int main(int, char**)
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();

    // Build atlas
    unsigned char* tex_pixels = nullptr;
    int tex_w, tex_h;
    io.Fonts->GetTexDataAsRGBA32(&tex_pixels, &tex_w, &tex_h);
//
//    for (int n = 0; n < 20; n++)
//    {
//        printf("NewFrame() %d\n", n);
//        io.DisplaySize = ImVec2(1920, 1080);
//        io.DeltaTime = 1.0f / 60.0f;
//        ImGui::NewFrame();
//
//        static float f = 0.0f;
//        ImGui::Text("Hello, world!");
//        ImGui::SliderFloat("float", &f, 0.0f, 1.0f);
//        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
//        ImGui::ShowDemoWindow(nullptr);
//
//        ImGui::Render();
//    }
//
   for (int n = 0; n < 2; n++)
   {
       printf("NewFrame() %d\n", n);
       io.DisplaySize = ImVec2(1920, 1080);
       io.DeltaTime = 1.0f / 60.0f;
       ImGui::NewFrame();

      // Get the position and size of the window
       ImVec2 windowPos = ImGui::GetWindowPos();
       ImVec2 windowSize = ImGui::GetWindowSize();

       printf("ImGui::GetWindowPos() x: %f, y: %f\n", windowPos.x, windowPos.y);
       printf("ImGui::GetWindowSize() width: %f, height: %f\n", windowSize.x, windowSize.y);
       

       static float f = 0.0f;
       ImGui::Text("Hello, world!");
       ImGui::SliderFloat("float", &f, 0.0f, 1.0f);
       ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
       ImGui::ShowDemoWindow(nullptr);

       ImGui::Render();
   }

    printf("DestroyContext()\n");
    ImGui::DestroyContext();
    return 0;
}
