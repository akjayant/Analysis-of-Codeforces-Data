#include<bits/stdc++.h>
#define mse(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
const int N=1e5+10;
const ll mod=1e9+7;
int main()
{
    int a,b,t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        int gcd=__gcd(a,b);
        if(gcd==1)
            cout<<"Finite"<<endl;
        else
            cout<<"Infinite"<<endl;
    }
}
