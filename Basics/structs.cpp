#include<iostream>
#include<string>

struct person{
    int height = 0;
    int weight = 0;;
    std::string gender = "";
};

int main(){
    person Joseph;
    Joseph.height = 73;
    Joseph.weight = 180;
    Joseph.gender = "Male";

    std::cout << Joseph.height/12 << " foot " << Joseph.height % 12 << " inches\n";
}