#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define de(x) cout<<#x<<" = "<<x<<"\n"
#define dd(x) cout<<#x<<" = "<<x<<" "
#define mes(p) memset(p,0,sizeof(p))
#define all(x) x.begin(),x.end()
#define rson mid+1,r,rt<<1|1
#define sz(x) (int)x.size()
#define mp make_pair 
#define lson l,mid,rt<<1
#define pb push_back
#define ls (rt<<1)
#define rs (ls|1)
#define se second
#define fi first
typedef pair <int ,int > pi;
typedef vector <int > vi;
const int maxn=4e5+5;
const int mod = 1e9+7;
typedef long long ll;
int add(int a,int b){
	if((a+=b) >= mod) a-=mod;
	return a;
}
int mul(int a,int b){
	return 1ll* a *b %mod;
}
int qm(int a,int b){
	int s = 1;
	while(b){
		if(b&1) s = mul(s,a);
		a= mul(a,a);
		b>>=1;
	}
	return s;
}
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
	cin >> n >> m;
	int ans = add(qm(2,m), mod-1);
//	de(ans);
	ans = qm(ans, n);
	cout << ans;
	return 0;
}
