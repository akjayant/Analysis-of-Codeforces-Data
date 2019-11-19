#include <bits/stdc++.h>
using namespace std;
typedef long long llint;
#define fir first
#define sec second
#define len(v) (int)(v).size()
#ifdef LOCAL
template<class T>string DSTR(T v);string to_string(string v){return"\""+v+"\"";}string to_string(char v){return"\'"+string(1,v)+"\'";}string to_string(bool v){return(v?"true":"false");}template<class T>string to_string(T v){bool f=true;string res="{";for(const auto&i:v){if(!f)res+=", ";f=false;res+=DSTR(i);}res+="}";return res;}template<class A,class B>string to_string(pair<A,B>v){return"("+DSTR(v.first)+", "+DSTR(v.second)+")";}template<class T>string DSTR(T v){return to_string(v);}
#define watch(v) cerr<<"["<< __func__<<":"<<__LINE__<<"]: "#v" = "<<DSTR(v)<<"\n"
#define watchsl(v,f,l) cerr<<"["<< __func__<<":"<<__LINE__<<"]: "#v"["<<DSTR(f)<<".."<<DSTR(l)<<"] = {";for(auto ITE=f;ITE<l;ITE++)cerr<<DSTR(v[ITE])<<", ";cerr<<to_string(v[l])<<"}\n"
#define SEP cerr<<"-----------------------------------\n\n"
#define SEP2 cerr<<"===================================\n\n"
#else
#define watch(v) ;
#define watchsl(v,f,l) ;
#define SEP ;
#define SEP2 ;
#endif
//	const int LEN = (int);



int main()
{
#ifdef LOCAL
	freopen("input.txt", "rt", stdin); freopen("output.txt", "wt", stdout);
#endif
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int cntp1, cntp0;
		cntp1 = cntp0 = 0;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			(x & 1 ? cntp1 : cntp0) += 1;
		}

		int cntq1, cntq0;
		cntq1 = cntq0 = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			(x & 1 ? cntq1 : cntq0) += 1;
		}

		cout << 1LL * cntq1 * cntp1 + 1LL * cntq0 * cntp0 << "\n";
	}
	return 0;
}
