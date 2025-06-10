#include<iostream>

int manByVal(int x){ //stands for manipulate by value
    return x+1;
}

void manByRef(int &x){ //manipulate by reference
    x = x + 1;
}

void manByPtr(int *x){ //manipulate by pointer
    //x  -> address passed in
    //*x  -> value at x with * being what derefences it
    *x = *x + 1;
}

void arrByRef(int *a, int size){
    for(int i = 0; i < size; i++){
        std::cout << a[i] << " ";
        if(i == size-1){
            std::cout << std::endl;
        }
    }
}

int main(){
    int value = 7; //stores value 7 in a variable called a
    int *ptr = &value; //stores the address (&) of 'a' to a pointer (*) called ptr

    int manVal = manByVal(value);

    manByRef(value);
    manByPtr(ptr);

    std::cout << "Manipulated Value: " << manVal << ", Original Value: " << value << std::endl;

    /*
    As shown above:
        - manByVal takes a variable, creates a copy, modifies the copy, and returns the copy. The original variable is unchanged.
        - manByRef takes a variable by reference and modifies it, in this case we just added 1 to our int.
        - manByPtr takes a variable by pointer and modifies it, in this case we just added 1 again.

        Passing by reference and pointer allows direct access an modification, making it cleaner, and using less resources. They help
        avoid unnecessary copies being created, but passing by copy is still needed for the cases where you need to keep the original
        value, yet also make a new one using the original.
     */

     int arr[] = {3,2,1};

     std::cout << arr << std::endl;
     std::cout << arr+1 << std::endl;
     std::cout << arr+2 << std::endl;

     /* The above prints an address similar to that of our pointer earlier 'ptr'. The reason for this that arrays are essentially
      pointers whose addresses are in succession by 4 Bytes. So each array index will be 4 hexadecimals a part. So if you had: 
        
        0x16bcbb2d8
        
      you would then get:

        0x16bcbb2dc
        0x16bcbb2e0
     
      The final examples last two values look different because c + 4 would increment the value before it due to hexadecimal rolling
      over at 0xF. So c + 4 = 10 in hexadecimal due as it would go 0xD, 0xE, 0xF, and finally 0x10.
      */

      arrByRef(arr, 3); //with passing arrays to functions you have to pass their size as well

}