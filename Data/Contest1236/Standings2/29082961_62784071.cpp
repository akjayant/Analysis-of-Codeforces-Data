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

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		int a, b, c;
		cin >> a>> b >> c;
		int ans =0 ;
		rep(i,0,101)
		rep(j,0,101){
			if(i<=a && (2*i+j) <= b && 2*j <= c) 
				ans = max(i+j, ans);
		}
		cout << ans*3 << "\n";
	}
	return 0;
}
