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
		int hash[26]={0};
		vector <int> v;
		vector <pair<int,int> > v1;
		for(int i=0; i<n; i++)
		{
			if(s[i]!=s1[i])
			{
				hash[s[i]-'a']++;
				hash[s1[i]-'a']++;
				v.pb(i);
			}
		}
		int flag=0;
		for(int i=0; i<26; i++)
		{
			if(hash[i]&1)
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			prln("No");
			continue;
		}
		flag=0;
		for(int i = 0; i + 1< v.size(); i++)
		{
			if(s[v[i]] == s1[v[i]]) continue;
			flag = 0;
			for(int j = i + 1; j < v.size(); j++)
			{
				if(s1[v[i]] == s1[v[j]])
				{
					v1.pb(mp(v[i],v[j]));
					swap(s[v[i]],s1[v[j]]);
					flag = 1;
					break;
				}
			}
			if(flag == 1) continue;
			for(int j = i + 1; j < v.size(); j++)
			{
				if(s1[v[i]] == s[v[j]])
				{
					v1.pb(mp(v[j],v[j]));
					swap(s[v[j]],s1[v[j]]);
					v1.pb(mp(v[i],v[j]));
					swap(s[v[i]],s1[v[j]]);
					flag = 1;
					break;
				}
			}
			if(flag == 0) break;
		}
		if(flag == 0)
		{
			//cout<<"hi";
			prln("No");
			continue;
		}
		else
		{
			prln("Yes");
			prln(v1.size());
			for(int i = 0; i < v1.size(); i++)	prln(v1[i].fst + 1,v1[i].snd + 1);
		}
		
	}
}


