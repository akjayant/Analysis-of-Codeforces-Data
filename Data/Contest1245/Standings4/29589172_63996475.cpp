#include <bits/stdc++.h>
using namespace std;
#define ll long long

int gcd(int a,int b){return b==0?a:gcd(b,a%b);}

int main()
{
    int T;cin>>T;
    while(T--)
    {
        int a,b;
        cin>>a>>b;
        int g=gcd(a,b);
        if(g==1)puts("Finite");
        else puts("Infinite");
    }
    return 0;
}
