#include<bits/stdc++.h>
using namespace std;
#define mx 32
#define mod 1000000007ll

typedef long long ll;
int lbit[mx], rbit[mx];

ll dp[mx][2][2][2][2];
ll func(int i, bool la, bool lb, bool ra, bool rb)
{
    if(i<0)
        return 1ll;
    ll &ret  = dp[i][la][lb][ra][rb];
    if(~ret)
        return ret;
    int p0 = 0, p1 =1;
    int q0 = 0, q1 = 1;
    if(la) p0 = lbit[i];
    if(lb) q0 = lbit[i];
    if(ra) p1= rbit[i];
    if(rb) q1 = rbit[i];
    ret  = 0;
    for(int j=p0;j<=p1;j++){
        for(int k=q0; k<=q1; k++){
            if(j && k) continue;
            ll rr = func(i-1, (la && j==lbit[i]), (lb && k==lbit[i]), (ra && j==rbit[i]),  (rb && k == rbit[i]));
            ret += rr;
        }
    }
    //ret %= mod;
    return ret;
}

void gooo()
{

    int l, i, a, b;
    int cl=0;
    for(l=0;l<0100;l++){
        int cnt  = 0;
        for(a=0;a<=l;a++){
            for(b=0;b<=l;b++){
                if((a^b)==a+b) cnt++;
            }
        }
        printf("%d: %d[%d]\n",l,cnt,cnt-cl);
        cl=cnt;
    }

}
int main()
{
    int t, l, r;
    int i;
    scanf("%d",&t);
    bool extra;
    while(t--){
        scanf("%d %d",&l, &r);
        for(i=0; r >= (1<<i);i++){
            if((l&(1<<i)))
                lbit[i] = 1;
            else lbit[i] = 0;
            if((r&(1<<i)))
                rbit[i]= 1;
            else rbit[i] =0;
            //printf("%d [%d %d]\n",i,lbit[i], rbit[i]);
        }
        memset(dp,-1,sizeof(dp));
        ll ret = func(i-1, true, true, true, true);
        printf("%lld\n",ret);
    }

    return 0;
}
