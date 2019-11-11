#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
const int MAXN = 3e5+5;
const int MOD = 1e9+7;

int main()
{
    int t,a,b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        if(__gcd(a,b)==1)puts("Finite");
        else puts("Infinite");
    }
    return 0;
}
