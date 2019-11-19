#include<bits/stdc++.h>
using namespace std;
#define int long long
#define si signed
#define sc(x) scanf("%I64d",&x);
#define rd(A) for(int i=1;i<=n;i++)scanf("%I64d",&A[i]);
#define pb push_back
#define se second
#define fi first
#define P pair<int,int>
#define endl '\n'
#define forn(i,n) for(int i=1;i<=n;i++)
struct Nod{
  int a,b,i;
};
#define maxn 100000+10
#define debug cout<<"No Pro"<<'\n';
int A[100][100];
int n,m;
const int mod=1e9+7;
bool check()
{
    int a=0,x;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            a=0;
            x=A[i][j];
            if(i>1){
                a+=(A[i-1][j]==x);
            }
            if(i<n)a+=(A[i+1][j]==x);
            if(j>1)a+=A[i][j-1]==x;
            if(j<m)a+=A[i][j+1]==x;

            if(a>=2)return false;
        }
    }
    return true;
}
int ans=0;
void dfs(int x,int y)
{
    if(y==m+1)x=x+1,y=1;
    if(x==n+1&&y==1){
        if(check()){
            ans++;
           // cout<<A[1][1]<<endl;
            //cout<<x<<endl;
        }
        return ;
    }
    A[x][y]=1;
    dfs(x,y+1);
    A[x][y]=0;
    dfs(x,y+1);
}
int B[100000+5];
int C[100000+5];
void init()
{
    B[1]=2;
    B[2]=2;
    for(int i=3;i<=100000;i++){
        B[i]=(B[i-1]+B[i-2])%mod;
    }
    for(int i=1;i<=100000;i++){
        C[i]=(B[i-1]+B[i])%mod;
    }
    for(int i=1;i<=100000;i++){
        B[i]=(B[i-1]+B[i])%mod;
    }
}
si main()
{
    init();
    sc(n)sc(m);
    cout<<(C[m]+B[n-1])%mod<<'\n';
}

