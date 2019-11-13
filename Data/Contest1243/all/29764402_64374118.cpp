// TEMPLATE --------------------------------------------------
#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
template<class T1, class T2>
istream &operator>>(istream &in, pair<T1, T2> &P){
	in >> P.first >> P.second;
	return in;
}
template<class T1, class T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &P){
	out << "(" << P.first << ", " << P.second << ")";
	return out;
}
template<class T>
istream &operator>>(istream &in, vector<T> &arr){
	for(auto &x: arr) in >> x;
	return in;
}
template<class T>
ostream &operator<<(ostream &out, const vector<T> &arr){
	for(auto &x: arr) out << x << ' '; cout << "\n";
	return out;
}
template<class T>
istream &operator>>(istream &in, deque<T> &arr){
	for(auto &x: arr) in >> x;
	return in;
}
template<class T>
ostream &operator<<(ostream &out, const deque<T> &arr){
	for(auto &x: arr) out << x << ' '; cout << "\n";
	return out;
}

// TEMPLATE --------------------------------------------------

#define N 100050 // CUIDADO COM MAXNNNNNN

int n, m, q, k, v[N];

vector<int> w;

vector<pii> p;

int T;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	cin>>T;

	while(T--)
	{

	cin>>n;

	for(int i = 1; i <= n; i++) cin>>v[i];

	sort(v + 1, v + n + 1);

	ll ans = 0;
	for(int i = 1; i <= n; i++)
	{

		ll menor = v[i];

		for(int j = i; j <= n; j++)
		{
			menor = min(menor, (ll)v[j]);

			ans = max(ans, min(menor, (ll)j - (ll)i + 1LL));
		}
	}

	cout<<ans<<"\n";
}
}