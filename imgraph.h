#ifndef _IMGRAPH_H_
#define _IMGRAPH_H_

#ifdef __has_include
    #if !__has_include(<imgui.h>)
        #error "Couldn't find imgui.h in the header include path, please add it to the path!"
    #endif
#endif // __has_include

// imgui headers
#include "imgui.h"
#include "imgui_internal.h"

namespace ImGraph {
    static const ImColor white{1.f, 1.f, 1.f, 1.f};
    static const ImColor half_white{1.f, 1.f, 1.f, 0.5f};
    static const ImColor red{1.f, 0.f, 0.f, 1.f};

    //void DrawGrid(const ImVec2& origin, float width, float height, float mmSpacing, float cmSpacing, const ImColor& color, float thinThickness, float boldThickness);
        void DrawGrid(const ImVec2& origin, float width, float height, float mmSpacing, float cmSpacing, 
                  const ImColor& thinColor, float thinThickness, 
                  const ImColor& boldColor, float boldThickness);
        void DrawDotPattern(const ImVec2& origin, float width, float height, float dotSpacingX, float dotSpacingY, 
                        const ImColor& dotColor, float dotRadius);

}

void RenderUI(const ImVec2& parentWindowPos);
void RenderUI_Dot(const ImVec2& parentWindowPos);

// #ifdef IMGRAPH_DEMO
// void Demo_Imgraph() {
//     // Function implementation here
// }
// #endif // IMGRAPH_DEMO

#endif // _IMGRAPH_H_



