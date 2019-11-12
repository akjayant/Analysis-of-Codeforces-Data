#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define de(x) cout<<#x<<" = "<<x<<"\n"
#define dd(x) cout<<#x<<" = "<<x<<" "
#define mes(p) memset(p,0,sizeof(p))
#define per(i,a,b) for(int i=(b)-1;i>=a;i--)
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
typedef long long ll;
const int maxn=2e5+3;
const int mod = 1e9+7;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int M = 1 << 20 << 1; 
const int N = 3e6+5;
char s[maxn], t[maxn];
int c[maxn];
vector < pair < int , int > > ans;
int solve(){
	int n;
	cin >> n;
	cin >> s;
	cin >> t;
	rep(i,0,26) c[i]=0;
	rep(i,0,n) c[s[i]-'a']++, c[t[i]-'a']++;
	rep(i,0,26) if(c[i]&1) return 0;
	ans.clear();
	while(1){
		rep(i,0,n)rep(j,0,n)
			if(i!=j && s[i]==s[j] && s[i]!=t[i] && s[j]!=t[j]){
				ans.pb(mp(i,j)); swap(s[i], t[j]);
				
		}
		rep(i,0,n){
			rep(j,0,n)
				if(s[i]!=t[i] && s[i]==t[j]&&s[j]!=t[j]){
					ans.pb(mp(i,i)), swap(s[i], t[i]);
					ans.pb(mp(i,j)), swap(s[i], t[j]);
				}
		}
		int f = 0;
		rep(i,0,n) if(s[i]!=t[i]){
			f = 1;
			break;
		}
		if(f) continue;
		break;
	}
	assert((sz(ans)<=2*n));
	cout << "Yes\n";
	cout << sz(ans) << "\n";
	rep(i,0,sz(ans)){
		cout << ans[i].fi+1 << " " << ans[i].se+1 <<"\n";
	}
	return 1;
}
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		if(!solve()) cout << "No\n";
	} 
	return 0;
}

