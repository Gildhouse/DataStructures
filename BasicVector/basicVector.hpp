#pragma once
#include <initializer_list>
#include<iostream>

template<typename T>
class Vec{
    private:
        T *arr;
        int visibleSize = 0;
        int actualSize = 0;
        void extend();

    public:
        Vec(int actual = 2);
        Vec(std::initializer_list<T> list);
        ~Vec();
        T& operator[](int index);
        const T& operator[](int index) const;
        void push_back(T value);
        void pop_back();
        int size() const{
            return visibleSize;
        }
        const T* begin() const{
            return arr;
        }
        const T* end() const{
            return arr+visibleSize;
        }
        bool isEmpty() const{
            return visibleSize == 0;
        }
};

template<typename T>
Vec<T>::Vec(int actual){
    actualSize = actual;
    visibleSize = 0;
    arr = new T[actualSize]; //arr now points to the first element of an array
}

template<typename T>
Vec<T>::Vec(std::initializer_list<T> list){ //allow a vec to be created using {1,2,3,4,...}
    actualSize = list.size() * 2;
    visibleSize = list.size();
    arr = new T[actualSize];

    int i = 0;
    for(const T& item : list){
        arr[i] = item;
        i++;
    }
}

template<typename T>
Vec<T>::~Vec(){
    delete[] arr;
}

template<typename T>
T& Vec<T>::operator[](int index){
    if(index < 0 || index > visibleSize-1){
        throw std::out_of_range("Index out of bounds.");
    }
    return arr[index];
}

template<typename T>
const T& Vec<T>::operator[](int index) const{
    if(index < 0 || index > visibleSize-1){
        throw std::out_of_range("Index out of bounds.");
    }
    return arr[index];
}

template<typename T>
void Vec<T>::extend(){
    actualSize *= 2;
    T *tempArr = new T[actualSize];
    for(int i = 0; i < visibleSize; i++){
        tempArr[i] = arr[i];
    }
    delete[] arr;
    arr = tempArr;
}

template<typename T>
void Vec<T>::push_back(T value){
    if(visibleSize == actualSize){
        extend();
    }
    arr[visibleSize] = value;
    visibleSize++;
}

template<typename T>
void Vec<T>::pop_back(){
    if(isEmpty()){
        throw std::out_of_range("Cannot pop_back an empty vector");
    }
    visibleSize--;
}