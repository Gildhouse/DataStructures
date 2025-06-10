#include "basicVector.hpp"
#include<iostream>

int main(){
    Vec<int> vec = {1,2,3};
    vec.pop_back();
    vec.pop_back();
    vec.pop_back();

    for(auto item : vec){
        std::cout << item;
    }
}