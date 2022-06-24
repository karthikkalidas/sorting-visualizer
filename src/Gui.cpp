#include <raylib.h>
#include <vector>
#include <iostream>
#include "Gui.hpp"
#include "Button.hpp"
#include "Pillars.hpp"

#define ScreenWidth 1200
#define ScreenHeight 800
#define MinScreenWidth 500
#define MinScreenHeight 500
#define FPS 120
#define NumberOfPillars 1000

void Initialize(){
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(ScreenWidth, ScreenHeight, "Sorting Algorithm Visualizer");
    SetWindowMinSize(MinScreenWidth, MinScreenHeight);
    SetTargetFPS(FPS);
}

void DrawPillars(std::vector<Pillar> &Pillars){
    float BarWidth = GetScreenWidth() / NumberOfPillars;

    for (int i = 0; i < NumberOfPillars; ++i){
        Pillars[i].SetColorForPillar();
        DrawRectangleV (Vector2{i*BarWidth, (float) GetScreenHeight() - Pillars[i].height},
                        Vector2{BarWidth, (float) Pillars[i].height}, Pillars[i].color);     
    }
}

void RandomizePillars(std::vector<Pillar> &Pillars){
    for(int i=0; i < NumberOfPillars; ++i){
        Pillars[i].height = {GetRandomValue(40, GetScreenWidth() - 10)};
    }
} 

void VisualizeSorting(std::vector<Pillar> &Pillars){
    std::cout<<""<<std::endl;
}

void LaunchGui(){
    Initialize();
    std::vector<Pillar> Pillars(NumberOfPillars);  
    DrawPillars(&Pillars);
    RandomizePillars(&Pillars);

    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(LIGHTGRAY);
        
        // Sorting Algorithm

        EndDrawing();
        CloseWindow();
    }
}