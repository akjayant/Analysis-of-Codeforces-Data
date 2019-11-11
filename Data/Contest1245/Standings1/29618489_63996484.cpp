#include <bits/stdc++.h>
#define vi vector<int>
#define pii pair<int, int >
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define LL long long
using namespace std;
const int INF=0x3f3f3f3f,N=2e6+5,MOD=1e9+7;

int Solve(){
    int a,b;
    cin>>a>>b;
    if(__gcd(a,b)==1)cout<<"Finite"<<endl;
    else cout<<"Infinite"<<endl;
    return 0;
}
void Pre(){
}
int main() {
#ifndef ONLINE_JUDGE
//  freopen("in.txt","r",stdin);
//  freopen("o1.txt","w",stdout);
#endif
    ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    Pre();
    int cas;cin>>cas;
    while(cas--)Solve();
    return 0;
}

