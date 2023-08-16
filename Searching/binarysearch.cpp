/*
    Author: Hitansh Bhatt
    Date: 15th August, 2023

    Searching an array using binary search
    Method: Compare desired value with the value in the middle index. If less, repeat searching again on the left side. Same on the right side
        To repeat searching: Use recursion

    Complexity: Worst case: O[log n] (Element that we are looking for is at the end of the n-size array); Best case: O[1] (middle element is the value we are looking for)
*/

#include <iostream>

int BinarySearch(int search_key, int array[], int size);
int binarysearch(int search_key, int l_idx, int r_idx, int array[], int size);

int binarysearch(int search_key, int l_idx, int r_idx, int array[], int size){
    int middle;
    
    if (l_idx > r_idx){
        return -1;
    }

    // Note: even or odd number of elements doesn't matter. The point is to approximately divide the array in half
    middle = (l_idx + r_idx)/2;     //the decimal point will be lost if there are odd number of elements

    if (search_key == array[middle]) return middle;
    else if (search_key < array[middle]) return binarysearch(search_key, l_idx, middle-1, array, size);
    else return binarysearch(search_key, middle + 1, r_idx, array, size);

}
    
    

int BinarySearch(int search_key, int array[], int size){
    return binarysearch(search_key, 0, size - 1, array, size);
}

int main(){
    int size = 10;
    int temp;
    int arr[size] = {100, 20, 19, 15, 65, 83, 1, 22, 98, 14};

    //simple and not-so-efficient linear sort. Most efficient to use Bubble Sort. Array needs to be sorted so this works for now
    for (int i = 0; i < size - 1; ++i) {
    for (int j = 0; j < size - i - 1; ++j) {
        if (arr[j] > arr[j + 1]) {
            temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
        }
    }

    //print sorted array:
    std::cout << "Sorted array: " << std::endl;
    for (int j = 0; j < size; j++){
        std::cout << arr[j] << std::endl;
    }
}

    std::cout << "Index of searched element is: " << BinarySearch(19, arr, size) << std::endl;
    std::cout << "Index of searched element is: " << BinarySearch(1, arr, size) << std::endl;
    std::cout << "Index of searched element is: " << BinarySearch(98, arr, size) << std::endl;
}