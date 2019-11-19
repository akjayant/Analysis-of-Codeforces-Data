#include<bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define LL long long
#define SZ(X) X.size()
#define pii pair<int,int>
#define ALL(X) X.begin(),X.end()

using namespace std;

LL gcd(LL a, LL b) {return b ? gcd(b, a % b) : a;}
LL lcm(LL a, LL b) {return a / gcd(a, b) * b;}
LL powmod(LL a, LL b, LL MOD) {LL ans = 1; while (b) {if (b % 2)ans = ans * a % MOD; a = a * a % MOD; b /= 2;} return ans;}
const int N = 1e6 + 11;
int n,a[N],l[N],r[N];
LL k;
int main() {
    scanf("%d%lld",&n,&k);
    LL sum=1ll*(1ll+n)*n/2;
    if(k<sum)puts("-1");
    else{
        set<int>st;
        for(int i=1;i<=n;i++)l[i]=r[i]=i;
        for(int i=1;i<=n;i++)st.insert(i);
        for(int i=1;i<=n;i++){
            int now=min(1ll*n,k-sum+l[i]);
            auto pos=st.upper_bound(now);
            if(pos==st.begin())continue;
            pos--;
            if(*pos<=l[i])continue;
            sum+=*pos-l[i];
            swap(r[i],r[*pos]);
            st.erase(r[i]);
            st.erase(*pos);
        }
        printf("%lld\n",sum);
        for(int i=1;i<=n;i++)printf("%d ",l[i]);
        puts("");
        for(int i=1;i<=n;i++)printf("%d ",r[i]);
    }
    return 0;
}
