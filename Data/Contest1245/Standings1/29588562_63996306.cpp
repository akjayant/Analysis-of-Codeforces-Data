#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+10;
#define fi first
#define se second
#define pb push_back
int t;
int main() {
    ios::sync_with_stdio(false);
    for(cin>>t;t;t--){
        int a,b;
        cin>>a>>b;
        if(__gcd(a,b)>1)cout<<"Infinite\n";
        else cout<<"Finite\n";
    }
    return 0;
}