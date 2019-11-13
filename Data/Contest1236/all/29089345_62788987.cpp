#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<long long int,long long int> pll;
typedef vector<int> vi;
typedef vector<long long int> vl;
#define pb push_back
#define mp make_pair

ll exp(ll n, ll m, ll mod){
	ll ans = 1;
	while(m>0){
		if(m%2==0) m/=2, n*=n, n%=mod;
		else m-=1, ans*=n, ans%=mod;
	}
	
	return ans%mod;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	
	ll n,m;
	cin >> n >> m;
	
	cout << exp(exp(2,m,(ll)(1e9+7))-1,n,(ll)(1e9+7)) << endl;
	return 0;
}

