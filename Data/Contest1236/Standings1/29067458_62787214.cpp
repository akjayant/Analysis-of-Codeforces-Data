#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<cmath>
#include<algorithm>
//#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define POP pop_back()
#define LL long long
#define POP pop_back()
#define endl '\n'
#define ls x<<1
#define rs x<<1|1
#define m(x) a[x].l+a[x].r>>1
#define PII pair<int,int>
#define FI first
#define SE second
#define VI vector<int>
#define QI queue<int>
#define SI stack<int>
#define debug cout<<"debug"<<endl;
#define PLL pair<LL,LL>
#define PDD pair<double,double>
#define ULL unsigned long long
#define fo(i,a,b) for (int i=a;i<=b;++i)
#define fd(i,a,b) for (int i=a;i>=b;--i)
#define mem(x,a) memset(x,a,sizeof(x));
const int N=3e6+9,mod=1e9+7,INF=0x3f3f3f3f;
LL n,m;
LL POW(LL x,LL y){
    LL re=1;
    while(y){
        if(y&1)re=re*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return re;
}
int main(){
    cin>>n>>m;
    LL ans=POW(2,m)-1;
    ans=POW(ans,n);
    cout<<ans<<endl;
    return 0;
}
