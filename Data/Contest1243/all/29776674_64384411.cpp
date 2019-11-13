/*
 *  AUTHOR : MANAV PATEl
*/
#include<bits/stdc++.h>
#include<functional>
//#include<boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;

namespace fastio
{

	template <class T> istream &operator>>(istream &os, vector<T> & vec)
	{
		for (auto &u : vec)os >> u;
		return os;
	}
	template <class T> ostream &operator<<(ostream &os, const vector<T> & vec)
	{
		for (auto &u : vec)os << u << " ";
		return os;
	}
	template<class T1, class T2> inline istream& operator>>(istream& os, pair<T1, T2>& p)
	{
		return os >> p.first >> p.second;
	}
	template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1, T2>& p)
	{
		return os << p.first << " " << p.second;
	}
	template <class T> ostream &operator<<(ostream &os, set<T> & con)
	{
		for (auto &u : con) os << u << " ";
		return os;
	}
	void re() {}
	template <typename T, typename... args> void re(T& x, args&... tail)
	{
		cin >> x;
		re(tail...);
	}
	void pr() {}
	template <typename T> void pr(const T& x)
	{
		cout << x;
	}
	template <typename T, typename... args> void pr(const T& x, const args&... tail)
	{
		cout << x << " ";
		pr(tail...);
	}
	template <typename... args> void prln(const args&... tail)
	{
		pr(tail...);
		cout << "\n";
	}
}
using namespace fastio;

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9+7;
const ll mod1 = 998244353;

#define fill(a)  memset(a, 0, sizeof(a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back

int main()
{
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	cin.tie(0);
	int t;
	re(t);
	while(t--)
	{
		ll n, cnt=0;
		re(n);
		string s, s1;
		re(s,s1);
		vector <bool> visited(n, false);
		for(int i=0; i<n; i++)
			if(s[i]==s1[i])
				visited[i]=true, cnt++;
		cnt=(n-cnt);
		if(cnt == 0)
			prln("Yes");
		else if(cnt != 2)
			prln("No");
		else
		{
			vector <int> v1;
			for(int i=0; i<n; i++)
				if(!visited[i])
					v1.push_back(i);
			swap(s[v1[0]], s1[v1[1]]);
			if(s==s1)
				prln("Yes");
			else
				prln("No");
		}
	}
}


