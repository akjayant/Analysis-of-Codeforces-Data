#include<bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false)
#define popcnt __builtin_popcount
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb emplace_back
#define pii pair<int,int>
#define all(n) (n).begin(),(n).end()
#define rep(i,a,n) for (int i = a; i <= n; i++)
#define QAQ sort(co+1,co+1+n)
const int maxn = 3e5 + 5;
const ll mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
ll pow_mod(ll a,ll b,ll c=mod,ll ans=1){while(b){if(b&1) ans=(a*ans)%c;a=(a*a)%c,b>>=1;}return ans;}
ll co[maxn];


string str;
ll n, m, k, t, need;

vector<int>ff[maxn];
int ans[305][305];
int main() {
	IO;
	cin >> n;
	for(int i = n; i >= 1; i--){
		if(i&1)
			for(int j = n; j >= 1; j--){
				ans[i][j] = i * n + j;
			}
		else{
			for(int j = 1; j <= n; j++)
				ans[i][j] = i * n + n - j + 1;
		}
	}
	rep(i,1,n){
		rep(j,1,n)
			cout << ans[j][i] - n << " ";
		cout << endl;
	}
		
}

