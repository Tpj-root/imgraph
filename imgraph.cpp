// imgraph.cpp

#include "imgui.h"
#include "imgui_internal.h"
#include "imgraph.h"



namespace ImGraph {

    void DrawGrid(const ImVec2& origin, float width, float height, float mmSpacing, float cmSpacing, const ImColor& color, float thinThickness, float boldThickness)
    {
        ImDrawList* draw_list = ImGui::GetWindowDrawList();
        
        // Loop through the grid lines and draw them
        for (float x = origin.x; x < origin.x + width; x += mmSpacing) {
            draw_list->AddLine(ImVec2(x, origin.y), ImVec2(x, origin.y + height), color, thinThickness);
        }
        for (float y = origin.y; y < origin.y + height; y += mmSpacing) {
            draw_list->AddLine(ImVec2(origin.x, y), ImVec2(origin.x + width, y), color, thinThickness);
        }

        // Bold lines for larger grid spacing
        for (float x = origin.x; x < origin.x + width; x += cmSpacing) {
            draw_list->AddLine(ImVec2(x, origin.y), ImVec2(x, origin.y + height), color, boldThickness);
        }
        for (float y = origin.y; y < origin.y + height; y += cmSpacing) {
            draw_list->AddLine(ImVec2(origin.x, y), ImVec2(origin.x + width, y), color, boldThickness);
        }
    }

}


// imgraph.cpp





