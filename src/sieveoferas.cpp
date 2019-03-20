#include <iostream>
#include <cstring>

void sieve(unsigned long n)   {
    bool arr[n+1];
    // Setting all elements of the array to true
    std::memset(arr, true, sizeof(arr));

    for(unsigned long i=2; i*i<=n; i++)
        if (arr[i] == true)
            for(unsigned long j=i*i; j<=n; j+=i)
                // Picking the multiples and setting them to false
                arr[j] = false;

    for(unsigned long i=2; i<=n; i++)
        if(arr[i])
            std::cout << i << " ";
}
int main()  {

    unsigned long n;
    std::cin >> n;
    sieve(n);
}


