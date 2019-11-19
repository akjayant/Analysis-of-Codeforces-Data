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
const int N=1e6+9,mod=1e9+7,INF=0x3f3f3f3f;
int n;
vector<int>v[N];
int s[4][N];
int d[N];
LL ans[7];
int flag;
void dfs(int x,int fa,int cnt){
    d[x]=cnt;
    if(cnt%3==1){
        ans[1]+=s[1][x];
        ans[2]+=s[1][x];
        ans[3]+=s[2][x];
        ans[4]+=s[2][x];
        ans[5]+=s[3][x];
        ans[6]+=s[3][x];
    }
    else if(cnt%3==2){
        ans[1]+=s[2][x];
        ans[2]+=s[3][x];
        ans[3]+=s[1][x];
        ans[4]+=s[3][x];
        ans[5]+=s[1][x];
        ans[6]+=s[2][x];
    }else{
        ans[1]+=s[3][x];
        ans[2]+=s[2][x];
        ans[3]+=s[3][x];
        ans[4]+=s[1][x];
        ans[5]+=s[2][x];
        ans[6]+=s[1][x];
    }
    if(v[x].size()>2){
        flag=1;return;
    }
    for(int i=0;i<v[x].size();i++){
        if(v[x][i]!=fa){
            dfs(v[x][i],x,cnt+1);
        }
    }
}
int main(){
    cin>>n;

    for(int j=1;j<=3;j++){
        for(int i=1;i<=n;i++){
            scanf("%d",&s[j][i]);
        }
    }
    int x,y;
    for(int i=1;i<n;i++){
        scanf("%d%d",&x,&y);
        v[x].PB(y);
        v[y].PB(x);
    }
    for(int i=1;i<=n;i++){
        if(v[i].size()==1){
            dfs(i,0,0);break;
        }
    }
    if(flag)cout<<-1;
    else{
        LL k=1;
        for(int i=2;i<=6;i++){
            if(ans[i]<ans[k])k=i;
        }
        cout<<ans[k]<<endl;
        int sx[4];
        if(k==1){
            sx[1]=1;sx[2]=2;sx[3]=3;
        }if(k==2){
            sx[1]=1;sx[2]=3;sx[3]=2;
        }if(k==3){
            sx[1]=2;sx[2]=1;sx[3]=3;
        }if(k==4){
            sx[1]=2;sx[2]=3;sx[3]=1;
        }if(k==5){
            sx[1]=3;sx[2]=1;sx[3]=2;
        }if(k==6){
            sx[1]=3;sx[2]=2;sx[3]=1;
        }
        for(int i=1;i<=n;i++){
            if(d[i]%3==1)printf("%d ",sx[1]);
            else if(d[i]%3==2)printf("%d ",sx[2]);
            else printf("%d ",sx[3]);
        }
    }
    return 0;
}
