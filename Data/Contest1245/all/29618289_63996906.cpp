#include <bits/stdc++.h>
#define DIM 100007
#define INF 1000000007
using namespace std;

long long t,a,b;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        if(__gcd(a,b)>1) cout<<"Infinite"<<endl;
        else cout<<"Finite"<<endl;
    }

    return 0;
}
