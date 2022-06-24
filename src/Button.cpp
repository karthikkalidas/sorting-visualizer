#include <raylib.h>
#include "Button.hpp"

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