#include "bits/stdc++.h"
using namespace std;
#define int int64_t
#define mp make_pair
#define f first
#define s second
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--)
    {
        int x,y;cin>>x>>y;
        if(__gcd(x,y)==1)
        {
            cout<<"Finite\n";
        }
        else
        {
            cout<<"Infinite\n";
        }
    }
    return 0;
}
