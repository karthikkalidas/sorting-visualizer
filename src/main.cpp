#include <vector>
#include <string>
#include "raylib.h"

#define ScreenWidth 1200
#define ScreenHeight 800
#define MinScreenWidth 500
#define MinScreenHeight 500
#define NumberOfPillars 50
#define FPS 120

// Pillar states
#define NORMAL 0
#define SORTED 1
#define SELECTED 2

class Pillar{
    public:
        int state, width, height;
        std::string color;

        Pillar(){
            width = 0, height = 0, state = NORMAL;
            color = "BLACK";
        }
};

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

Color FindColorForPillar(int &state){};
void DrawVector(std::vector<Pillar> &Pillars){};
void RandomizeVector(std::vector<Pillar> &Pillars){};
void BubbleSort(std::vector<Pillar> &Pillars){};

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

void DrawVector(std::vector<Pillar> &Pillars){
    float BarWidth = GetScreenWidth() / NumberOfPillars;

    for (int i = 0; i < NumberOfPillars; ++i){
        Color color = FindColorForPillar(Pillars[i].state);
        DrawRectangleV (Vector2{i*BarWidth, (float) GetScreenHeight() - Pillars[i].height},
                        Vector2{BarWidth, (float) Pillars[i].height}  ,
                        color);     

    }
}

void RandomizeVector(std::vector<Pillar> &Pillars){
    for(int i=0; i < NumberOfPillars; ++i){
        Pillars[i].height = {GetRandomValue(40, MinScreenWidth -10)};
    }
}

void BubbleSort(std::vector<Pillar> &Pillars){
    int endingPoint = NumberOfPillars;
    bool swapped = false;
    do{
        swapped = false;
        for (int i=0; i<endingPoint-1; ++i){
            Pillars[i].state = SELECTED;

            if (Pillars[i].height > Pillars[i+1].height){
                std::swap(Pillars[i], Pillars[i+1]);
                swapped = true;
            }
            BeginDrawing();
            ClearBackground(WHITE);

            for(int k=NumberOfPillars-1; k>=NumberOfPillars; k--)
                Pillars[k].state = SORTED;

            DrawVector(Pillars);

            for (int k = i; k >= 0; k--)
                    Pillars[k].state = NORMAL;
                    
            EndDrawing();
        }
        endingPoint--;
    } while(swapped);
    DrawVector(Pillars);
} 

int main(){
    // Window Configuration
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(ScreenWidth, ScreenHeight, "Sorting Algorithm Visualizer");
    SetWindowMinSize(MinScreenWidth, MinScreenHeight);
    SetTargetFPS(FPS);

    std::vector<Pillar> Pillars(NumberOfPillars);  
    RandomizeVector(Pillars);

    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(LIGHTGRAY);
        DrawVector(Pillars);
        EndDrawing();
    }
    
    CloseAudioDevice();
}

