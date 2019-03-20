#include <iostream>
#include <cmath>
#include <bits/stdc++.h>

int main()  {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    unsigned long  n, q, l, r;
    std::cin >> n >> q;
    unsigned long arr[n];

    for(unsigned long i=0; i<n; i++)
        std::cin >> arr[i];

    while(q > 0)    {
        std::cin >> l >> r;
        std::cout << arr[((l+r)/2)-1] << "\n";
        q--;
    }
}
