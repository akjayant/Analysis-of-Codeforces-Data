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

#define N 55 // CUIDADO COM MAXNNNNNN

int n, m, q, k, v[N];

vector<int> w;

vector<pii> p;

int A[30], B[30];

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int T;

	cin>>T;

	for(int t = 1; t <= T; t++)
	{
		memset(A, 0, sizeof A);
		memset(B, 0, sizeof B);
		string s, p;

		cin>>n;

		cin>>s;

		cin>>p;

		int diff = 0;

		vector<int> d;

		for(int j = 0; j < n; j++)
		{
			if(s[j] != p[j])
			{
				diff ++;

				A[s[j] - 'a'] ++;

				B[p[j] - 'a'] ++;

				d.pb(j);
			}
		}

		if(diff > 2) cout<<"No\n";

		else
		{
			if(d.size() == 0) cout<<"Yes\n";

			else if(d.size() == 1) cout<<"No\n";

			else if(d.size() == 2)
			{
				int a = d[0], b = d[1];

				if( (s[a] == s[b] and p[a] == p[b])) cout<<"Yes\n";

				else cout<<"No\n";
			}

			else cout<<"No\n";
		}
	}

}