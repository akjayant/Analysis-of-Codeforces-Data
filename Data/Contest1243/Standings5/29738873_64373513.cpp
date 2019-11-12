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
const int maxn=2e3+3;
const int mod = 1e9+7;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int M = 1 << 20 << 1; 
const int N = 3e6+5;
int a[maxn];
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		rep(i,0,n) cin >> a[i];
		sort(a, a+n);
		reverse(a, a+n);
		int ans =0;
		rep(i,0,n)
			if(a[i] >= i+1) ans =i+1;
		cout << ans  << "\n";
	}
	return 0;
}

