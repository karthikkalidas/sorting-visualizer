#include "pillars.h"

void DrawPillars(std::vector<Pillar> &Pillars){
    float BarWidth = GetScreenWidth() / NumberOfPillars;

    for (int i = 0; i < NumberOfPillars; ++i){
        Color color = FindColorForPillar(Pillars[i].state);
        DrawRectangleV (Vector2{i*BarWidth, (float) GetScreenHeight() - Pillars[i].height},
                        Vector2{BarWidth, (float) Pillars[i].height}  ,
                        color);     
    }
}

void RandomizePillars(std::vector<Pillar> &Pillars){
    for(int i=0; i < NumberOfPillars; ++i){
        Pillars[i].height = {GetRandomValue(40, MinScreenWidth -10)};
    }
} 

Color FindColorForPillar(int &state){
    switch (state){
        case NORMAL:
            return GRAY;
        case SORTED: 
            return GREEN;
        case SELECTED:
            return RED;
    }
}

void visualize(std::vector<Pillar> &Pillars){
    BeginDrawing();
    ClearBackground(BgdColor);
    DrawVector(Pillars);
    EndDrawing();
}