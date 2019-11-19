#include <bits/stdc++.h>

using namespace std;

const int N=1e6+2,MOD=1e9+7;

typedef long long ll;

int a,b,c,n,m,x,y,u,v,tc,k,ans,l,r,q;

ll dp[60][4][4][4][4];

char s[N];

string le,re;

ll solve(int idx, int a, int b, int c, int d) {
    if (idx >= n) 
        return r = 1;
    ll &r = dp[idx][a][b][c][d];
    if (~r) 
        return r;
    r = 0;
    int x=(a ? 0 : le[idx] - '0');
    int y=(b ? 1 : re[idx] - '0');
    int z=(c ? 0 : le[idx] - '0');
    int w=(d ? 1 : re[idx] - '0');
    for(int  i=x;i<=y;i++) {
        for(int j=z;j<= w;j++) {
            if (i != 1 || j != 1) {
                //cout << (int)(a || i > (le[idx]-'0')) << " ";
                //cout << (int)(b || i < (re[idx]-'0')) << " ";
                //cout << (int)(c || j > (le[idx]-'0')) << " ";
                //cout << (int)(d || j < (re[idx]-'0')) << endl;
                r += solve(idx+1, a || i > (le[idx]-'0'), b || i < (re[idx]-'0'), c || j > (le[idx]-'0'), d || j < (re[idx]-'0'));
            }
        }
    }
    return r;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("test.txt","r",stdin);
    #endif
    scanf("%d",&tc);
    while(tc--){
        memset(dp,-1,sizeof dp);
        scanf("%d%d",&l,&r);
        le="",re="";
        while(l){
            le+=(l&1)+'0';
            l/=2;
        }
        while(r){
            re+=(r&1)+'0';
            r/=2;
        }
        while (le.size()<re.size())
            le+='0';
        n=le.size();
        reverse(re.begin(),re.end());
        reverse(le.begin(),le.end());
        printf("%lld\n",solve(0,0,0,0,0));
    }
}
