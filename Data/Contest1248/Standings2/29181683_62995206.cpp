#include <iostream>
#include <vector>
#include <algorithm>
#include<cstring>
#include <cmath>

using namespace std;
#define  fr(i,x,y) for(int i=x;i<=y;i++)

typedef  long  long ll;
#define  N 100005

#define ms(x,y) memset(x,y,sizeof(x));
vector<int > aa;
int m,n;
int dp0[N][2];
const int mod=1000000007;

int l[N],r[N],sl[N],sr[N],a[N],t[N];
void doit(){
    scanf("%d%d",&n,&m);
    int nm=max(n,m);

    ms(dp0,0);
    dp0[1][0]=1;

    fr(i,2,nm) {

        dp0[i][1] += dp0[i - 1][0];
        if (dp0[i][1] >= mod)dp0[i][1] -= mod;
        dp0[i][0] += dp0[i - 1][0];

        if (dp0[i][0] >= mod)dp0[i][0] -= mod;
        dp0[i][0] += dp0[i - 1][1];

        if (dp0[i][0] >= mod)dp0[i][0] -= mod;


    }
    int ans1=(dp0[n][0]+dp0[n][1])%mod*2%mod;
    int ans2=(dp0[m][0]+dp0[m][1])%mod*2%mod;;

    printf("%d\n",((ans1+ans2-2)%mod+mod)%mod);
}
int main(){
//    int cas;
//    scanf("%d",&cas);
//    while (cas--)
        doit();
}