#include "algorithms.h"
#include "pillars.h"

void RunAlgorithm(std::vector<Pillar> Pillars, void (*algorithm)(std::vector<int>&, int&)){
    std::vector<int> vec; 

    for(int i=0; i<Pillars.size(); ++i)
        vec.push_back(&Pillars[i].height);

    int n = vec.size(); 

    auto start = std::chrono::high_resolution_clock::now();

    algorithm(vec, n);

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cout<<"Algorithm Time: "<<duration.count()<<std::endl;
}

void AlgorithmTemplate(std::vector<int> &vec, int &n){
    // YOUR ALGORITHM HERE
    // INNERMOST LOOP
    visualize(Pillars);
    // 
}

void BubbleSort(std::vector<int> &vec, int &n){
    bool swapped;
    
    for(int i = 0; i < n-1; ++i){
        swapped = false;
        
        for(int j = 0; j < n-i-1; ++j){
            if(vec[j] > vec[j+1]){
                std::swap(vec[j], vec[j+1]);
                swapped = true;
            }
            visualize(Pillars);
        }
        if (!swapped)
            break;
    }
}