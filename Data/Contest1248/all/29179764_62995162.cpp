#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+100,delta=1e9+7;
int x,y;
int g[maxn];
void pre_calc(){
    g[0]=1;
    g[1]=1;
    g[2]=2;
    for(int i=3;i<maxn;i++)g[i]=(g[i-1]+g[i-2])%delta;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    pre_calc();
    cin>>y>>x;
    long long ans=0;
    ans=g[y];
    ans%=delta;
    for(int i=2;i<=x;i++){
        ans+=g[x-i];
        ans%=delta;
    }
    ans*=2;
    ans%=delta;
    cout<<ans;

}
