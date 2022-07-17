#include "../include/pillars.h"
#include "../include/algorithms.h"
#include<iostream>

// GUI Settings
#define ScreenWidth 1200
#define ScreenHeight 800
#define MinScreenWidth 500
#define MinScreenHeight 500
#define NumberOfPillars 1000
#define BgdColor WHITE
#define FPS 120

class Button{
    int x, y;
    char *text;
    int font;
    Color color;
    bool state;
    Rectangle rect;

    Button(int x, int y, const char *text, Color color){
        x = x;
        y = y;
        text = text;
        color = color;
        font = (2.5 * GetScreenWidth() / 100);
        rect = Rectangle{(float) x,(float) y,(float) MeasureText(text, font),(float) font};
    }

    void UpdateButtonState(){
        if (CheckCollisionPointRec(GetMousePosition(), rect)){
            DrawText(text, x, y, font, RED);

            if (IsMouseButtonPressed(0)){
                state = !state;                     
            } else{
                DrawText(text, x, y, font, color);
            }
        }
    }
};

int main(){
    // Window Configuration
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(ScreenWidth, ScreenHeight, "Sorting Algorithm Visualizer");
    SetWindowMinSize(MinScreenWidth, MinScreenHeight);
    SetTargetFPS(FPS);

    std::vector<Pillar> Pillars(NumberOfPillars); 
    RandomizeVector(Pillars);

    // while(!WindowShouldClose()){
    //     visualize(Pillars);
    //     RunAlgorithm(Pillars, &BubbleSort);
    //     CloseWindow();
    // }
}

