#include<bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define REP(i,a,b) for(int i = a; i <= b; ++i)
#define PER(i,a,b) for(int i = a; i >= b; --i)
#define PB push_back
#define MP make_pair
#define fi first
#define se second
typedef long long LL;
typedef double DB;

const int maxn = 1e5;

int n, ai[maxn+5];
LL S[maxn+5];
LL kk;

bool Chk(LL del) {
    for(int i = 1; i <= n; ++i) {
        int r = upper_bound(ai+1, ai+1+n, ai[i]+del) - ai;
        LL tmp = (ai[i]*LL(i) - S[i]) + (S[n]-S[r-1] - (ai[i]+del)*LL(n-r+1));
        if(tmp <= kk) return true;
    }
    for(int i = n; i >= 1; --i) {
        int l = lower_bound(ai+1, ai+1+n, ai[i]-del) - ai - 1;
        LL tmp = (S[n]-S[i-1] - ai[i]*LL(n-i+1)) + ((ai[i]-del)*LL(l) - S[l]);
        if(tmp <= kk) return true;
    }
    return false;
}

int main() {
    scanf("%d%I64d", &n, &kk);
    REP(i,1,n) scanf("%d", ai+i);
    sort(ai+1, ai+1+n);
    REP(i,1,n) S[i] = S[i-1] + ai[i];
    int l = 0, r = 1e9, ans = 1e9 + 7;
    while(l <= r) {
        int mid = (l+r)>>1;
        if(Chk(mid)) ans = mid, r = mid-1;
        else l = mid+1;
    }
    printf("%d\n", ans);
    return 0;
}
