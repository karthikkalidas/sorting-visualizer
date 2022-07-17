#pragma once
#include "pillars.h"

void RunAlgorithm(std::vector<Pillar> Pillars, void (*algorithm)(std::vector<int>&, int&)){};
void AlgorithmTemplate(std::vector<int> &vec, int &n){};
void BubbleSort(std::vector<int> &vec, int &n){};


