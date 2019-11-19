#include<bits/stdc++.h>
using namespace std;
#define For(a,b,c) for(int a=b;a<=c;++a)
#define Ford(a,b,c) for(int a=b;a>=c;--a)
#define Fv(a,b) for(auto &a:b)
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define vt vector<int>
#define vpi vector<pair<int,int>>
#define sz(x) (int)(x.size())
#define all(a) a.begin(),a.end()
#define reset(f,x) memset(f,x,sizeof(f))
#define bit(x,i) (x>>i&1ll)
#define on(x,i) (x|(1ll<<i))
#define off(x,i) (x&~(1ll<<i))
#define task "1243c"
#define int long long
const int N=2e6+5;
int e[N],p[N];
int np, x[N],y[N],k,n;
int ans;
void pt(int n){
    k=0; int i=1;
    int a;
    while(n>1e6){
        while(p[i]<=n/p[i]&&n%p[i]!=0)i++;
        if(p[i]>n/p[i])a=n;
        else a=p[i];
        x[++k]=a;
        y[k]=0;
        while(n%a==0)++y[k],n/=a;
    }
    int oo=1;
    while(n>1){
        a=e[n];
        x[++k]=a;
        y[k]=0;
        while(n%a==0) ++y[k], n/=a;
    }
}

void upd(int i, int pos, int va){return;}

int pw(int x, int i) {
    int b = 1;
    for(; i; i>>=1, x = x * x) if(i & 1) b = b * x;
    return b;
}

main(){
    For(i,1,1e6)e[i]=i;
    For(i,2,1e6)if(e[i]==i){
        for(int j=2*i;j<=1e6;j+=i)e[j]=i;
    }
    np=0;
    np=0;
    For(i,2,1e6)if(e[i]==i)p[++np]=i;
    cin >> n;
    pt(n);
    ans = 1;
    For(i, 1, k) {
        if(pw(x[i], y[i]) <= n - 1) continue;
        int tmp = 0;
        For(j, 1, y[i]) {
            if(pw(x[i], j) <= n - 1 + 1 - 1) {
                tmp = j;
            }
        }
        ans = ans * pw(x[i], y[i] - tmp);
    }
    cout << ans;
}
