//#include <bits/stdc++.h>
//using namespace std;
//
//int power(int x, int n)
//{
//    if (n == 0)
//        return 1;
//    if (x == 0)
//        return 0;
//    return x * power(x, n - 1);
//}
//
//int main()
//{
//    int x = 2;
//    int n = 3;
//
//    cout << (power(x, n));
//}

#include <iostream>
using namespace std;

int nCr(int n, int r)
{
    if (r > n)
        return 0;
    if (r == 0 || r == n)
        return 1;
    return nCr(n - 1, r - 1) + nCr(n - 1, r);
}

int main()
{
    cout << nCr(5, 3);
    return 0;
}

