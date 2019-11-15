#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int x ,y;
        cin>>x>>y;
        if (__gcd(x,y)==1) printf("Finite\n");
        else printf("Infinite\n");
    }
}