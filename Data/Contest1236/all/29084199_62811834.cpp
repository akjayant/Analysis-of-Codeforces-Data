#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			a.size()
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
//int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
//using namespace __gnu_pbds;

typedef long long 		ll;
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
const int tam = 100010;
const int MOD = 1e9+7;
const int MOD1 = 988244535;
const double EPS = 1e-9;
const double PI = acos(-1);
set<int> sts[2][2][100010];
int main()
{
	//ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	ll n, m, can;
	cin>>n>>m>>can;
	int a, b;
	fore(i, 0, 100010)
	{
		sts[0][0][i].insert(1000100);
		sts[1][0][i].insert(1000100);
		sts[0][1][i].insert(1);
		sts[1][1][i].insert(1);
	}
	fore(i, 0, can)
	{
		cin>>a>>b;
		a--, b--;
		sts[0][0][a].insert(b);
		sts[1][0][b].insert(a);
		sts[0][1][a].insert(-b);
		sts[1][1][b].insert(-a);
	}
	int minx = 0, miny = -1, maxx = n, maxy = m;
	int ori = 0;
	int x = 0, y = 0;
	ll reco = 1;
	bool bo = true;
	while(1)
	{
		//cout<<maxx<<' '<<minx<<' '<<maxy<<' '<<miny<<' '<<x<<' '<<y<<'\n';
		//if(x == maxx || x == minx || y == maxy || y == miny) break;
		if(ori == 0)
		{
			a = min(maxy, *sts[0][0][x].upper_bound(y));
			maxy = a-1;
			if(y == a -1 && !bo) 
				{
					break;
				}
			reco += a - y - 1;
			y = a - 1;
		}
		if(ori == 1)
		{
			a = min(maxx, *sts[1][0][y].upper_bound(x));
			maxx = a-1;
			if(x == a - 1) break;
			reco += a - x - 1;
			x = a - 1;
		}
		if(ori == 2)
		{
			a = max(miny, -*sts[0][1][x].upper_bound(-y));
			miny = a+1;
			if(y == a + 1) break;
			reco += y - a - 1;
			y = a + 1;
		}
		if(ori == 3)
		{
			a = max(minx, -*sts[1][1][y].upper_bound(-x));
			minx = a+1;
			if(x == a + 1) break;
			reco += x - a - 1;
			x = a + 1;	
		}
		bo = false;
		ori = (ori + 1) % 4;
		//cout<<reco<<'\n';
	}
	//cout<<reco<<'\n';
	if(reco + can == n * m)
		cout<<"Yes\n";
	else
		cout<<"No\n";
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2