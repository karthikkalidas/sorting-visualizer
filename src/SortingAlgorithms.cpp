#include <vector>
#include <raylib.h>
#include "SortingAlgorithms.hpp"
#include "Pillars.hpp"

void BubbleSort(std::vector<int> &Vec){
   bool swapped {};
   int n = Vec.size();
   for (int i = 0; i < n-1; ++i){
     swapped = false;
     for (int j = 0; j < n-i-1; ++j){
        if (Vec[j] > Vec[j+1]){
           std::swap(Vec[j], Vec[j+1]);
           swapped = true;
        }
     }
     // IF no two elements were swapped 
     // by inner loop, then break
     if (swapped == false)
        break;
   }
}

// void BubbleSort(std::vector<Pillar> &Pillars){
//     for(int i=0; i<NumberOfPillars-1; ++i){
//         for(int j=0; j<NumberOfPillars-i-1; ++j){
//             Pillars[j].state = SELECTED;

//             if (Pillars[j].height > Pillars[j+1].height){
//                 std::swap(Pillars[j], Pillars[j+1]);
//             }
//             BeginDrawing();
//             ClearBackground(WHITE);

//             for(int k=NumberOfPillars-1; k>=NumberOfPillars-i; --k)
//                 Pillars[k].state = SORTED;

//             DrawVector(Pillars);

//             for (int k = j; k >= 0; --k)
//                 Pillars[k].state = NORMAL;
                    
//             EndDrawing();
//         }
//     }
// }

// void QuickSort(std::vector<Pillar> &Pillars, int low=0, int high=NumberOfPillars-1){
//     if (low < high){
//         int i = (low - 1);
//         for (int j = low; j <= high - 1; j++)
//         {
//             if (Pillars[j].height < Pillars[high].height)
//             {
//                 i++;
//                 std::swap(Pillars[i], Pillars[j]);
//             }
//         }
//         std::swap(Pillars[i + 1], Pillars[high]);

//         BeginDrawing();
//         ClearBackground(WHITE);

//         DrawVector(Pillars);
//         // std::this_thread::sleep_for(std::chrono::milliseconds(100));

//         EndDrawing();

//         QuickSort(Pillars, low, i);
//         QuickSort(Pillars, i+2, high);
//     }
// }