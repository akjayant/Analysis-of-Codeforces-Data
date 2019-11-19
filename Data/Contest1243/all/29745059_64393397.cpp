#include<bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0);\
           cin.tie(0);\
           cout.tie(0);
typedef long long ll;
typedef pair<int,int> pii;
const int mod = 1e9+7;
const int maxn = 1e5 + 5;
const int maxm = 2e6 + 5;

ll n;
ll a[111],tot;
int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in","r",stdin);
#endif
    IO;
    cin>>n;
    if (n==1) { cout<<1<<endl; return 0; }
    
    for (ll i=2;i*i<=n;i++) {
        if (n%i==0) a[tot++]=i;
        while (n%i==0) n/=i;
    }
    if (n!=1) a[tot++]=n; 
    if (tot>=2) cout<<1<<endl;
    if (tot==1) cout<<a[0]<<endl;
    return 0;
}