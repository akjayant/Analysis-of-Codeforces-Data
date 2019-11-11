#include <bits/stdc++.h>

using namespace std;

const int N=1e6+2,MOD=1e9+7;

typedef long long ll;

int a,b,c,n,m,x,y,u,v,tc,k,ans,l,r,q,dp[100][100][100];

char s[N];

int solve(int idx,int a,int b){
    if (idx>=n)
        return 0;
    int &r=dp[idx][a][b];
    if (~r)
        return r;
    r=0;
    int C=s[idx]=='P',R=s[idx]=='S',P=s[idx]=='R';
    if (a>0)
        r=max(r,R+solve(idx+1,a-1,b));
    if (b>0)
        r=max(r,P+solve(idx+1,a,b-1));
    if (n-idx-a-b>0)
        r=max(r,C+solve(idx+1,a,b));
    return r;
}

void trace(int idx,int a,int b){
    if (idx>=n)
        return ;
    int C=s[idx]=='P',R=s[idx]=='S',P=s[idx]=='R';
    int r=-1,p=-1,c=-1;
    if (a>0)
        r=R+solve(idx+1,a-1,b);
    if (b>0)
        p=P+solve(idx+1,a,b-1);
    if (n-idx-a-b>0)
        c=C+solve(idx+1,a,b);
    int mx=max(r,max(p,c));
    if (mx==r){
        printf("R");
        trace(idx+1,a-1,b);
    }
    else if (mx==p){
        printf("P");
        trace(idx+1,a,b-1);
    }
    else{
        printf("S");
        trace(idx+1,a,b);
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("test.txt","r",stdin);
    #endif
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        scanf("%d%d%d",&a,&b,&c);
        for(int i=0;i<n;i++)
            for(int j=0;j<=a;j++)
                for(int k=0;k<=b;k++)
                    dp[i][j][k]=-1;
        scanf("%s",s);
        int r=solve(0,a,b);
        if (r*2>=n){
            printf("YES\n");
            trace(0,a,b);
            printf("\n");
        }
        else
            printf("NO\n");
    }
}
