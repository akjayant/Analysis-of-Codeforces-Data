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

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	int T;

	cin>>T;

	for(int t = 1; t <= T; t++)
	{
		string s, p;

		cin>>n;

		cin>>s;

		cin>>p;

		vector<pii> swaps;

		for(int j = 0; j < n; j++)
		{
			if(s[j] == p[j]) continue;

			//cout<<"J = "<<j<<"\n";

			int a = (s[j] - 'a'), b = (p[j] - 'a');

			//Procura por (a) em S
			for(int h = j + 1; h < n; h++)
				if(s[h] == s[j])
				{
					swaps.pb({h, j});

					swap(s[h], p[j]);

					//cout<<"alo "<<j<<" "<<h<<"\n";

					break;
				}

			if(s[j] == p[j]) continue;

			//Procura por (b) em P
			for(int h = j + 1; h < n; h++)
				if(p[h] == p[j])
				{
					swaps.pb({j, h});

					swap(s[j], p[h]);

					break;
				}

			if(s[j] == p[j]) continue;


			//Procura (a) em P

			int pa = -1, pb = -1;

			for(int h = j + 1; h < n; h++)
			{
				if(s[h] == p[j]) pb = h;

				if(p[h] == s[j]) pa = h;
			}

			if(pa != -1)
			{
				swap(s[pa], p[pa]);

				swap(s[pa], p[j]);

				swaps.pb({pa, pa});

				swaps.pb({pa, j});
			}

			else if(pb != -1)
			{
				swap(s[pb], p[pb]);

				swap(s[j], p[pb]);

				swaps.pb({pb, pb});

				swaps.pb({j, pb});
			}
		}

		if(s == p)
		{
			cout<<"Yes\n";
			cout<<sz(swaps)<<"\n";
			for(auto w: swaps) cout<<w.f + 1<<" "<<w.s + 1<<"\n";
		}

	else cout<<"No\n";
	}

}