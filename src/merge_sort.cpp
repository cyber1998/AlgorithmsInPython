#include <iostream>

void merge(int arr[], int l, int m, int r)  {
    int temp[r-l+1];
    int i = l, j = m+1, k = 0;

    // Sorting the array
    while(i <= m && j <= r) {
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
    while (i <= m)   {
            temp[k] = arr[i];
            k++, i++;
        }
    while (j <= r)   {
            temp[k] = arr[j];
            k++, j++;
        }

    for(int i = l; i <= r; i++)  {
        arr[i] = temp[i-l];
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l+r)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

int main()  {
    int arr[] = {3, 2, 111, 56, 24, 97, 20, 7, 61, 9};
    int arr_size = sizeof(arr)/sizeof(*arr);

    mergeSort(arr, 0, arr_size-1);

    for(int i=0; i < arr_size; i++) {
       std::cout << arr[i] << ",";
   }
}
