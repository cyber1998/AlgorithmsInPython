#include <iostream>

void merge(int arr[], int left, int mid, int right)  {
    int temp[right-left+1];
    int i = left, j = mid+1, k = 0;

    // Sorting the array
    while(i <= mid && j <= right) {
        if (arr[i] <= arr[j])   {
            temp[k] = arr[i];
            k++, i++;
        }
        else {
            temp[k] = arr[j];
            k++, j++;
        }
    }

    // Copying over the remaining elements if any
    while (i <= mid)   {
            temp[k] = arr[i];
            k++, i++;
        }
    while (j <= right)   {
            temp[k] = arr[j];
            k++, j++;
        }

    for(int i = left; i <= right; i++)  {
        arr[i] = temp[i-left];
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left+right)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);

        merge(arr, left, mid, right);
    }
}

int main()  {

    int arr_size;
    std::cout << "Enter the size of the array: ";
    std::cin >> arr_size;
    int arr[arr_size];

    std::cout << "Enter the elements of the array";
    for(int i=0; i < arr_size; i++) {
        std::cin >> arr[i];
    }

    mergeSort(arr, 0, arr_size-1);

    for(int i=0; i < arr_size; i++) {
       std::cout << arr[i] << ",";
   }
}
