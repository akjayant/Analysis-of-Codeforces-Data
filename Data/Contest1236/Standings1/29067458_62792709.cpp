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
const int N=1e3+9,mod=1e9+7,INF=0x3f3f3f3f;
int n,m;
int a[N][N];
int main(){
    cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(i&1){
            for(int j=1;j<=n;j++)a[j][i]=++cnt;
        }
        else for(int j=n;j>=1;j--)a[j][i]=++cnt;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
