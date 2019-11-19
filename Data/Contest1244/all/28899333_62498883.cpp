#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<int, null_type, less<int>, rb_tree_tag, 
tree_order_statistics_node_update> ordered_set;
//s.find_by_order()
//s.order_of_key()
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef vector<int> VI;
 
#define SZ(a) (int)a.size()
#define FOR(i, a, b) for(int i = (a);i < (b);++i)
#define RFOR(i, b, a) for(int i = (b)-1;i >= (a);--i)
#define PB push_back
#define MP make_pair
#define FILL(a, b) memset(a, b, sizeof(a))
#define ALL(a) a.begin(), a.end()
#define f first
#define s second
 
const int INF = 1000 * 1000 * 1000;
const LL LINF = 1ll * INF * INF;
const long double PI = acos(-1.0);
const int MAXN = 1e5 + 7;
const int MOD = 1000 * 1000 * 1000 + 7;
 
map<int, int> mep;
 
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	LL k;
	cin >> n >> k;
	set<int> st;
	FOR(i, 0, n)
	{
		int a;
		cin >> a;
		st.insert(a);
		mep[a]++;
	}
	
	while(k > 0 && SZ(st) > 1)
	{
		int a = *st.begin();
		int b = *(--st.end());
		LL kola = mep[a];
		LL kolb = mep[b];
		if (kola < kolb)
		{
			auto it = st.begin();
			++it;
			LL el = *it - a;
			LL c = k / kola;
			if (c >= el)
			{
				st.erase(st.begin());
				mep[*st.begin()] += kola;
				k -= (LL)el * kola;
			}
			else
			{
				st.erase(st.begin());				
				st.insert(a + c);
				break;
			}
		}
		else
		{
			auto it = --st.end();
			--it;
			LL el = b - (*it);
			LL c = k / kolb;
			if (c >= el)
			{
				st.erase(--st.end());
				mep[*(--st.end())] += kolb;
				k -= (LL)el * kolb;
			}
			else
			{
				st.erase(--st.end());
				st.insert(b - c);
				break;
			}
		}
	}
	
	cout << *(--st.end()) - (*st.begin()) << "\n";
	
	return 0;
}
 
 
 
 
 
 
 
 
 