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
int n,m;
int main(){
    int t;
    cin>>t;
    while(t--){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        int ans=0;
        ans+=min(y*3,z/2*3);
        y-=min(y,z/2);
        ans+=min(x*3,y/2*3);
        y-=min(x*2,y/2*2);

        printf("%d\n",ans);
    }
    return 0;
}
