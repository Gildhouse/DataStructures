#pragma once
#include<iostream>

template<typename T>
struct Node{
    T data;
    Node* prev;
    Node* next;
}

class DLL{
    private:
        Node* head;

    public:
        DLL();
        ~DLL();
};