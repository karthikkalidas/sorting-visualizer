#pragma once

#include <vector>
#include <chrono>
#include <thread>
#include <iostream>
#include "raylib.h"

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

void DrawVector(std::vector<Pillar> &Pillars);
void RandomizeVector(std::vector<Pillar> &Pillars);
Color FindColorForPillar(int &state);
void visualize(std::vector<Pillar> &Pillars){};
    