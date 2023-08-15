/*
    Author: Hitansh Bhatt
    Date: 15th August, 2023

    Searching an array using linear search
    Method: Iterate through the array in a sequential order and return the number of times an element (value) occurs in the array.
            If the value is not found, return a suitable message to the user

    Complexity: Worst case: O[n] (Element that we are looking for is at the end of the n-size array); Best case: O[1] (first element is the value we are looking for)
*/


#include <iostream>

void LinearSearch(int value, int array[], int size);

void LinearSearch(int value, int array[], int size){
    int count=0;
    for (int i = 0; i < size; ++i){
        if (array[i] == value){
            count++;
        }
        else{
            continue;
        }
    }

    if (count > 0) {
        std::cout << value << " was found " << count << " time(s)" << std::endl;
    }
    else{
        std::cout << value << " was not found" << std::endl;
    }
}

int main(){
    int size;
    std::cout << "Enter the size of the array" << std::endl;
    std::cin >> size;
    std::cout << "Enter numbers into the array" << std::endl;
    int input_array[size];
    //populating the array
    for (int i = 0; i < size; i++){
        std::cin >> input_array[i];
    }

    LinearSearch(1, input_array, size); //should output "1 was found 3 time(s)"
    LinearSearch(100, input_array, size); //should output "100 was found 1 time"
    LinearSearch(30, input_array, size); //should output "30 was not found"
}
