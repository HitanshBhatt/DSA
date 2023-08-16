/*
    Author: Hitansh Bhatt
    Date: 16th August, 2023

    Sorting an array using Bubble Sort
    Method: Iterate through the array and swap elements one at a time if preceding element is greater than successing element.
            Note: Add a for loop for multiple passes

    Complexity: O[n^2]
*/

#include <iostream>

void bubblesort(int array[], int size);
void print_array(int array[], int size);

void print_array(int array[], int size){
    std::cout << "{";
    for (int i = 0; i < size; ++i){
        std::cout << array[i];
        if (i < (size - 1)) std::cout << ",";
    }

    std::cout << "} ";

}

void bubblesort(int array[], int size){
    int count = 0;
    int temp;
    for (int pass = 0; pass < size - 1; ++pass){    //repeat the sorting until no more swapping is required
        for (int i = 0; i < size - 1; ++i){
            if (array[i] > array[i+1]){
                print_array(array, size);
                temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;

                std::cout << "=> ";
                print_array(array, size);
                std::cout << std::endl;
            }
        }
    }
}

int main(){
    int size = 10;
    int arr[size] = {29, 11, 45, 32, 37, 98, 101, 1, 88, 56};

    print_array(arr, size);
    std::cout << std::endl;
    std::cout << "Beginning to bubble sort: " << std::endl;
    bubblesort(arr, size);
    print_array(arr, size);
    std::cout << std::endl;

}