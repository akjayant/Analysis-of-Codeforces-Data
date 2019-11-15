#include <bits/stdc++.h>
#define ll long long

using namespace std;
char Bob[110],Alice[110];
int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int i,j;
    int t,a,b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        int g=gcd(a,b);
        if(g!=1)
            puts("Infinite");
        else
            puts("Finite");
    }
    return 0;
}
