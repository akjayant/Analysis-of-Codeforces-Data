#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int MAXN = 2e5+50;
const int INF = 0X3f3f3f3f;
const int MOD = 1e9+7;
int main(){
    int T; cin>>T;
    while(T--){
        int a,b; cin>>a>>b;
        if(__gcd(a,b)==1) cout<<"Finite"<<endl;
        else cout<<"Infinite"<<endl;
    }
    return 0;
}
