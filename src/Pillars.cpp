#include "Pillars.hpp"
#include <raylib.h>

// Pillar states
#define NORMAL 0
#define SORTED 1
#define SELECTED 2

class Pillar{
    public:
        int state, width, height;
        Color color;

        Pillar(){
            width = 0, height = 0, state = NORMAL;
            color = BLACK;
        }

        Color SetColorForPillar(){
        switch (state){
            case NORMAL:
                color = GRAY;
            case SORTED: 
                color = GREEN;
            case SELECTED:
                color = RED;
        }
    }
};


