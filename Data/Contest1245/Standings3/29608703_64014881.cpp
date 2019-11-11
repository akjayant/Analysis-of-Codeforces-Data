#include<bits/stdc++.h>
#define F(i,a,b) for(int i=(a);i<=int(b);++i)
using namespace std;
typedef long long ll;
const int maxn = 1;
const int inf = 0x3f3f3f3f;
#define endl '\n'
vector<int>en;
vector<int>use;
int hav[3];
int main()
{
#ifndef endl
	freopen("C:\\Users\\VULCAN\\Desktop\\data.in", "r", stdin);
	cout << "************************************Local Test*********************************" << endl;
#endif // !endl
	ios::sync_with_stdio(false);
	int T(1), cas(0);
	cin >> T;
	while (T--)
	{
		en.clear();
		int n; cin >> n;
		cin >> hav[0] >> hav[1] >> hav[2];
		F(i, 1, n)
		{
			char c; cin >> c;
			if (c == 'R')c = 0;
			else if (c == 'P')c = 1;
			else if (c == 'S')c = 2;
			en.push_back(c);
		}
		use.resize(n); F(i, 0, n - 1)use[i] = -1;
		int win(0);
		F(i, 0, n - 1)
		{
			int val = en[i];
			int wan = (val + 1) % 3;
			if (hav[wan])--hav[wan], use[i] = wan, ++win;
		}
		F(i, 0, n - 1)if (use[i] == -1)
		{
			F(j, 0, 2)if (hav[j])
			{
				--hav[j];
				use[i] = j;
				break;
			}
		}

		if (win >= (n + 1) / 2)
		{
			cout << "YES" << endl;
			F(i, 0, n - 1)
			{
				int val = use[i];
				if (val == 0)cout << "R";
				else if (val == 1)cout << "P";
				else if (val == 2)cout << "S";
			}
			cout << endl;
		}
		else cout << "NO" << endl;
	}
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