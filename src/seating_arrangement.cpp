#include <iostream>

int difference(int x, int y)   {
    if(x > y)
        return x -y;
    return y-x;
}

char *label(int difference){
    switch(difference){
        case 1: return " WS";
        case 3: return " MS";
        case 5: return " AS";
        case 7: return " AS";
        case 9: return " MS";
        case 11: return " WS";
    }
}

int get_block(int n)    {
    if(n % 12 == 0) {
        return n/12;
    }
    return (n / 12) + 1;
}

void get_front_seat(int n)   {
    int block = get_block(n);
    int temp1 = ((block * 12)+((block * 12) - 11))/2;
    int temp2 = temp1 + 1;
    int k = 0;
    int arr1[6];
    int arr2[6];
    int index = 0;
    for(int i=temp1; i > temp1-6; i--)  {
        arr1[k] = i;
        if(n == i){
            index = k;
            break;
        }
        k++;

    }
    k = 0;
    for(int i=temp2; i <= temp1+6; i++)  {
        arr2[k] = i;
        if(n == i)  {
            index = k;
            break;
        }
        k++;
    }

    if(n<temp2) {
        std::cout << arr2[index] << label(difference(arr1[index], arr2[index]));
    }
    else {
        std::cout << arr1[index] << label(difference(arr1[index], arr2[index]));
    }
}

int main()  {
    int t;
    std::cin >> t;
    int n[t];
    for(int i=0; i<t; i++)
        std::cin >> n[i];

    for(int i=0; i<t; i++) {
        get_front_seat(n[i]);
        std::cout << "\n";
    }
}
