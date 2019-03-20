#include <iostream>
#include <cmath>

int main()  {
    int n;
    unsigned long product = 1;
    unsigned int constant = pow(10, 9) + 7;
    std::cin >> n;
    int arr[n];

    for(int i=0; i<n; i++)  {
        std::cin >> arr[i];
    }

    for(int i=0; i<n; i++)  {
        product *= arr[i];
        product = product % constant;
    }

    std::cout << product;
}
