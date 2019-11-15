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
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
const int maxn = 3e5 + 5;
const ll mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
ll pow_mod(ll a,ll b,ll c=mod,ll ans=1){while(b){if(b&1) ans=(a*ans)%c;a=(a*a)%c,b>>=1;}return ans;}
int co[maxn], dp[maxn];

string str;
ll n, m, k, t, d;
vector<ll>ff;
int cnt[3];
string aa = "RPS";
int aans[105];
int main() {
	IO;
	cin >> t;
	while(t--){
		cin >> n;
		rep(i,0,2)	cin >> co[i];
		int need = (n+1) / 2;
		cin >> str;
//		cout << cnt[0] << " " << cnt[1] << " " << cnt[2] << endl;
//		int ans = min(co[0], cnt[2]) + min(co[1], cnt[0]) + min(co[2], cnt[1]);
//		if(ans >= need)	cout << "YES" << endl;
//		else{
//			cout << "NO" << endl;
//			continue;
//		}
		rep(i,0,100)	aans[i] = -1;
		int ans = 0;
		for(int i = 0; i < str.size(); i++){
			rep(j,0,2)
				if(str[i] == aa[j]){
					if(co[(j+1)%3]){
						co[(j+1)%3]--;
						aans[i] = (j+1)%3;
						ans++;
					}
				}
		}
		rep(i,0,n-1)
			if(aans[i] == -1){
				rep(j,0,2)
					if(co[j]){
						co[j]--;
						aans[i] = j;
						break;
					}
			}
		if(ans >= need)	cout << "YES" << endl;
		else{
			cout << "NO" << endl;
			continue;
		}
		rep(i,0,n-1)
			cout << aa[aans[i]];
		cout << endl;
	}
}


