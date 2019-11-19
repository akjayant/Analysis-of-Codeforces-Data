#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<cmath>
#include<algorithm>
#include <bits/stdc++.h>
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
const int N=5e4+9,mod=1e9+7,INF=0x3f3f3f3f;
int n,m;
int a[N];
int main(){
    int t;
    cin>>t;
    while(t--){
        int x,y,c,d,k;
        cin>>x>>y>>c>>d>>k;
        int ans1=(x)/c+(x%c>0);
        int ans2=k-ans1;
        if(ans2*d<y)printf("-1\n");
        else cout<<ans1<<' '<<ans2<<endl;
    }

    return 0;
}
