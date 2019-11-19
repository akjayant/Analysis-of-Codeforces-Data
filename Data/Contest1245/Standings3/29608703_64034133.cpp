#include<bits/stdc++.h>
#define F(i,a,b) for(int i=(a);i<=int(b);++i)
using namespace std;
typedef long long ll;
const int maxn = 1;
const int inf = 0x3f3f3f3f;
int le, ri;
int L[40], R[40];
ll dp[2][2][2][2][100];

int  pre(int val, int ar[])
{
	int pos = 0;
	while (val)
	{
		ar[pos] = val & 1;
		val >>= 1;
		++pos;
	}
	return pos;
}
ll dfs(int pos, int freeA, int freeB,int overA,int overB)
{
	if (pos == 2)
		pos = pos;
	if (pos == -1)return 1;


	ll &ans=dp[freeA][freeB][overA][overB][pos];
	if (ans == -1)
	{
		ans = 0;
		F(i, 0, 1)F(j, 0, 1)
		{
			if (i&&j)continue;
			int useA = i, useB = j;
			if (!freeA&&useA > R[pos])continue;
			if (!freeB&&useB > R[pos])continue;
			if (!overA&&useA < L[pos])continue;
			if (!overB&&useB < L[pos])continue;

			ans += dfs(pos - 1, freeA || useA <R[pos], freeB || useB < R[pos], overA || useA>L[pos], overB || useB>L[pos]);
		}
	}
	return ans;
}
#define endl '\n'
int main()
{
#ifndef endl
	freopen("C:\\Users\\VULCAN\\Desktop\\data.in", "r", stdin);
	cout << "************************************Local Test*********************************" << endl;
#endif // !endl
	ios::sync_with_stdio(false);
	int T(1), cas(0);
	cin >> T;
	memset(dp, -1, sizeof(dp));
	while (T--)
	{
		//cout << clock()*1. / CLOCKS_PER_SEC << endl;
		F(i0, 0, 1)F(i1, 0, 1)F(i2, 0, 1)F(i3, 0, 1)
		{
			if (i0 + i1 + i2 + i3 != 4)
			{
				F(j, 0, 36)dp[i0][i1][i2][i3][j] = -1;
			}
		}
		memset(L, 0, sizeof(L));
		memset(R, 0, sizeof(R));
		cin >> le >> ri;
		int ma = max(pre(le, L), pre(ri, R));
		cout << dfs(ma, 0, 0,0,0) << endl;
	}
	//cout << clock()*1. / CLOCKS_PER_SEC << endl;
	return 0;
}
//What to Debug
/*
-1.最好把全部warning都X掉,否则:https://vjudge.net/solution/19887176
0.看看自己是否有可能需要快读，禁endl
1.数组越界，爆int,浮点精度(查看精度是否达到题目要求,看有没有浮点数比较:eps)，取模操作，初始化数组，边缘数据,输出格式(cas),强制在线是否更新了las
2.通读代码，代码无逻辑错误
3.读题，找到题意理解失误或算法错误
4.放弃
*/