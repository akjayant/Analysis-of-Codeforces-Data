#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int T , l , r;
LL ans , ss;
struct mmp{
	int p , s;
};
vector<mmp> v;

void div(int x , int y , int z)
{
	if (z == -1) v.push_back({z,x});
	else if (((x>>z)&1) == ((y>>z)&1)) div(x,y,z-1);
	else if (!(x&((1<<z)-1)) && (y&((1<<z)-1)) == ((1<<z)-1)) v.push_back({z,x});
	else
	{
		int yy = ((y>>z)<<z);
		int xx = yy-1;
		if (yy <= y) div(yy,y,z-1);
		if (x <= xx) div(x,xx,z-1);
	}
}

int main()
{
	int i , j , k;
	cin >> T;
	while (T--)
	{
		v.clear();
		ans = 0;
		cin >> l >> r;
		div(l,r,29);
		for (auto i: v)
			for (auto j: v)
			{
				mmp x = i;
				mmp y = j;
				if (x.p > y.p) swap(x,y);
				ss = 1;
				for (k = 29 ; k > y.p ; k--)
					if (((x.s>>k)&1) && ((y.s>>k)&1)) ss = 0;
				if (!ss) continue;
				for (k = y.p ; k > x.p ; k--)
					if (!((x.s>>k)&1)) ss = ss*2;
				for (k = x.p ; k >= 0 ; k--)
					ss = ss*3;
				ans += ss;
			}
		cout << ans << "\n";
	}
	return 0;
}