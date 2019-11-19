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

vector<int> w;

vector<pii> p;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	ll n;

	cin>>n;

	ll menor = n;

	ll raiz = sqrt(n);

	int qtd = 0;

	for(ll i = 2; i <= raiz; i++)
	{
		if(n % i != 0) continue;

		ll ii = n/i;

		if(i != 1) menor = min(menor, i);

		if(ii != 1) menor = min(menor, ii);
	}

	for(ll i = 2; i <= raiz; i++)
	{
		if(n % i != 0) continue;

		while(n % i == 0)
		{
			n /= i;

		}
		qtd ++;
	}

	if(n != 1) qtd ++;

	if(qtd > 1) cout<<"1\n";
	else cout<<menor<<"\n";
}