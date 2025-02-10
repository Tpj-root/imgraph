// imgraph.cpp

#include "imgui.h"
#include "imgui_internal.h"
#include "imgraph.h"

namespace ImGraph {

    void DrawGrid(const ImVec2& origin, float width, float height, float mmSpacing, float cmSpacing, 
                  const ImColor& thinColor, float thinThickness, 
                  const ImColor& boldColor, float boldThickness)
    {
        ImDrawList* draw_list = ImGui::GetWindowDrawList();
        
        for (float x = origin.x; x < origin.x + width; x += mmSpacing) {
            draw_list->AddLine(ImVec2(x, origin.y), ImVec2(x, origin.y + height), thinColor, thinThickness);
        }
        for (float y = origin.y; y < origin.y + height; y += mmSpacing) {
            draw_list->AddLine(ImVec2(origin.x, y), ImVec2(origin.x + width, y), thinColor, thinThickness);
        }
        for (float x = origin.x; x < origin.x + width; x += cmSpacing) {
            draw_list->AddLine(ImVec2(x, origin.y), ImVec2(x, origin.y + height), boldColor, boldThickness);
        }
        for (float y = origin.y; y < origin.y + height; y += cmSpacing) {
            draw_list->AddLine(ImVec2(origin.x, y), ImVec2(origin.x + width, y), boldColor, boldThickness);
        }
    }


        void DrawDotPattern(const ImVec2& origin, float width, float height, float dotSpacingX, float dotSpacingY, 
                        const ImColor& dotColor, float dotRadius)
    {
        ImDrawList* draw_list = ImGui::GetWindowDrawList();

        // Draw dots in the X direction
        for (float x = origin.x; x < origin.x + width; x += dotSpacingX) {
            for (float y = origin.y; y < origin.y + height; y += dotSpacingY) {
                draw_list->AddCircleFilled(ImVec2(x, y), dotRadius, dotColor);
            }
        }
    }




}














void RenderUI(const ImVec2& parentWindowPos)
{
    static float width = 400, height = 400;
    static float mmSpacing = 10.0f, cmSpacing = 100.0f;
    static float thinThickness = 1.0f, boldThickness = 2.5f;
    
    static ImVec4 thinColor = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);  // Default Red
    static ImVec4 boldColor = ImVec4(0.0f, 0.0f, 1.0f, 1.0f);  // Default Blue
    static ImVec4 bgColor = ImVec4(0.2f, 0.2f, 0.2f, 1.0f);   // Default Dark Gray (Background)

    // Set grid position relative to the parent window
    static ImVec2 gridOffset = ImVec2(50, 50);
    ImVec2 gridPos = ImVec2(parentWindowPos.x + gridOffset.x, parentWindowPos.y + gridOffset.y);

    ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(bgColor.x, bgColor.y, bgColor.z, bgColor.w));  // Apply color change to this window only

    ImGui::Begin("Grid Controls");

    // Adjust grid offset instead of absolute position
    ImGui::SliderFloat2("Grid Offset", (float*)&gridOffset, 0.0f, 500.0f);
    ImGui::SliderFloat("Width", &width, 100.0f, 800.0f);
    ImGui::SliderFloat("Height", &height, 100.0f, 800.0f);
    ImGui::SliderFloat("mm Spacing", &mmSpacing, 1.0f, 50.0f);
    ImGui::SliderFloat("cm Spacing", &cmSpacing, 10.0f, 200.0f);
    ImGui::SliderFloat("Thin Line Thickness", &thinThickness, 0.5f, 5.0f);
    ImGui::SliderFloat("Bold Line Thickness", &boldThickness, 1.0f, 10.0f);

    // Add color pickers for thin, bold, and background colors
    ImGui::ColorEdit4("Thin Line Color", (float*)&thinColor);
    ImGui::ColorEdit4("Bold Line Color", (float*)&boldColor);
    ImGui::ColorEdit4("Background Color", (float*)&bgColor);  // New Background Color Option

    ImGui::End();

    ImGui::PopStyleColor();  // Revert the style change to prevent affecting other windows

    // Convert ImVec4 color to ImColor
    ImColor thinImColor = ImColor(thinColor.x, thinColor.y, thinColor.z, thinColor.w);
    ImColor boldImColor = ImColor(boldColor.x, boldColor.y, boldColor.z, boldColor.w);

    // Draw the grid with user-defined colors
    ImGraph::DrawGrid(gridPos, width, height, mmSpacing, cmSpacing, thinImColor, thinThickness, boldImColor, boldThickness);
}


void RenderUI_Dot(const ImVec2& parentWindowPos)
{
    static float width = 400, height = 400;
    static float mmSpacing = 10.0f, cmSpacing = 100.0f;
    static float thinThickness = 1.0f, boldThickness = 2.5f;
    static float dotSpacingX = 20.0f, dotSpacingY = 20.0f;  // Dot spacing for X and Y directions
    static float dotRadius = 3.0f;  // Radius of the dots
    
    static ImVec4 thinColor = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);  // Default Red
    static ImVec4 boldColor = ImVec4(0.0f, 0.0f, 1.0f, 1.0f);  // Default Blue
    static ImVec4 bgColor = ImVec4(0.2f, 0.2f, 0.2f, 1.0f);   // Default Dark Gray (Background)

    // Set grid position relative to the parent window
    static ImVec2 gridOffset = ImVec2(50, 50);
    ImVec2 gridPos = ImVec2(parentWindowPos.x + gridOffset.x, parentWindowPos.y + gridOffset.y);

    ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(bgColor.x, bgColor.y, bgColor.z, bgColor.w));  // Apply color change to this window only

    ImGui::Begin("Grid and Dot Controls");

    // Adjust grid offset and properties
    ImGui::SliderFloat2("Grid Offset", (float*)&gridOffset, 0.0f, 500.0f);
    ImGui::SliderFloat("Width", &width, 100.0f, 800.0f);
    ImGui::SliderFloat("Height", &height, 100.0f, 800.0f);
    ImGui::SliderFloat("mm Spacing", &mmSpacing, 1.0f, 50.0f);
    ImGui::SliderFloat("cm Spacing", &cmSpacing, 10.0f, 200.0f);
    ImGui::SliderFloat("Thin Line Thickness", &thinThickness, 0.5f, 5.0f);
    ImGui::SliderFloat("Bold Line Thickness", &boldThickness, 1.0f, 10.0f);
    
    // Dot pattern options
    ImGui::SliderFloat("Dot Spacing X", &dotSpacingX, 5.0f, 50.0f);
    ImGui::SliderFloat("Dot Spacing Y", &dotSpacingY, 5.0f, 50.0f);
    ImGui::SliderFloat("Dot Radius", &dotRadius, 1.0f, 10.0f);

    // Add color pickers for thin, bold, background colors, and dot color
    ImGui::ColorEdit4("Thin Line Color", (float*)&thinColor);
    ImGui::ColorEdit4("Bold Line Color", (float*)&boldColor);
    ImGui::ColorEdit4("Background Color", (float*)&bgColor);  // New Background Color Option

    ImGui::End();

    ImGui::PopStyleColor();  // Revert the style change to prevent affecting other windows

    // Convert ImVec4 color to ImColor
    ImColor thinImColor = ImColor(thinColor.x, thinColor.y, thinColor.z, thinColor.w);
    ImColor boldImColor = ImColor(boldColor.x, boldColor.y, boldColor.z, boldColor.w);

    // Draw the grid with user-defined colors
    ImGraph::DrawGrid(gridPos, width, height, mmSpacing, cmSpacing, thinImColor, thinThickness, boldImColor, boldThickness);
    
    // Draw the dot pattern with the user-defined properties
    ImColor dotColor = ImColor(1.0f, 1.0f, 0.0f, 1.0f);  // Default yellow dots
    ImGraph::DrawDotPattern(gridPos, width, height, dotSpacingX, dotSpacingY, dotColor, dotRadius);
}





// imgraph.cpp





