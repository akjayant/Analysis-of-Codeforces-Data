#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N; scanf("%d", &N);
    while(N--)
    {
        int a, b; scanf("%d%d", &a, &b);
        if(gcd(a,b)==1)
        puts("Finite");
        else puts("Infinite");
    }   
}