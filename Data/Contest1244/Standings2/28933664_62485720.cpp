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
const int N = 2e5 + 11;
int n;
int a[5][N],f[5],p[5];
vector<int>v[N];
LL dfs(int now,int pre,int cnt=0){
    LL ans=a[f[cnt+1]][now];
    for(auto k:v[now]){
        if(k==pre)continue;
        ans+=dfs(k,now,(cnt+1)%3);
    }
    return ans;
}
int res[N];
void dfs1(int now,int pre,int cnt=0){
    res[now]=p[cnt+1];
    for(auto k:v[now]){
        if(k==pre)continue;
        dfs1(k,now,(cnt+1)%3);
    }
}
int main() {
	ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=n;j++)cin>>a[i][j];
    }
    for(int i=1;i<n;i++){
        int s,t;
        cin>>s>>t;
        v[s].pb(t);
        v[t].pb(s);
    }
    int s,cnt=0,one=0;
    for(int i=1;i<=n;i++){
        if(SZ(v[i])==1)s=i,cnt++,one++;
        else if(SZ(v[i])==2)cnt++;
    }
    LL ans=1e18;
    if(one==2&&cnt==n){
        for(int i=1;i<=3;i++)f[i]=i;
        do{
            LL now=dfs(s,0);
            if(now<ans){
                ans=now;
                for(int j=1;j<=3;j++)p[j]=f[j];
            }
        }while(next_permutation(f+1,f+4));
        cout<<ans<<endl;
        dfs1(s,0);
        for(int i=1;i<=n;i++)cout<<res[i]<<' ';
    }else cout<<-1<<endl;
	return 0;
}
