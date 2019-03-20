#include <iostream>

int partition(int arr[], int left, int right){
    int i = left + 1;
    int piv = arr[left];

    for(int j = left + 1; j <= right; j++){
        if (arr[j] < piv){
            std::swap(arr[i], arr[j]);
        i++;
        }
    }

    std::swap(arr[left], arr[i-1]);
    return i - 1;
}

int partition_rn(int arr[], int left, int right){
    int ran = left + rand() % (right-left+1);
    std::swap(arr[ran], arr[left]);
    return partition(arr, left, right);
}

void quicksort(int arr[], int left, int right){
    if (left < right){
        int p = partition_rn(arr, left, right);
        quicksort(arr, left, p-1);
        quicksort(arr, p+1, right);
    }
}

int main(){

    int arr_size;
    std::cout << "Enter the size of the array: ";
    std::cin >> arr_size;
    int arr[arr_size];

    std::cout << "Enter the elements of the array";
    for(int i=0; i < arr_size; i++){
    std::cin >> arr[i];
    }

    quicksort(arr, 0, arr_size-1);

    for(int i=0; i < arr_size; i++){
       std::cout << arr[i] << ",";
   }
}
