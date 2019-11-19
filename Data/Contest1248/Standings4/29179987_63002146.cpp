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
const int LEN = (int)1e5;
const llint MOD = (llint)1e9 + 7;

int n, m;

llint dp[LEN][2][2];

llint norm(llint x)
{
	if (abs(x) >= MOD)
		x %= MOD;
	if (x < 0)
		x += MOD;
	return x;
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "rt", stdin); freopen("output.txt", "wt", stdout);
#endif
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m;

	int N = max(n, m);

	for (int i = 0; i < N; i++)
	{
		for (int color = 0; color <= 1; color++)
		{
			dp[i][color][0] = (i == 0 ? 1 : norm(dp[i-1][!color][0] + dp[i-1][!color][1]));
			dp[i][color][1] = (i == 0 ? 0 : dp[i-1][color][0]);
		}
	}

	llint ans = 0;
	for (int color = 0; color <= 1; color++)
		for (int l = 0; l <= 1; l++)
			ans = norm(ans + dp[n-1][color][l] + dp[m-1][color][l]);
	cout << norm(ans-2) << "\n";
	return 0;
}
