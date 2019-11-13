#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
using namespace std;
int main()
{
    int t, a, b;
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        if(__gcd(a, b) == 1)
            puts("Finite");
        else
            puts("Infinite");
    }
    return 0;
}
