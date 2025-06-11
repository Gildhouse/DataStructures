#include "basicVector.hpp"
#include<iostream>

int main(){
    Vec<int> vec = {1,2,3};

    std::cout << vec[4];

    for(auto item : vec){
        std::cout << item;
    }
}