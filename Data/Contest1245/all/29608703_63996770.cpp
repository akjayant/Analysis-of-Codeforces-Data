#include<bits/stdc++.h>
#define F(i,a,b) for(int i=(a);i<=int(b);++i)
using namespace std;
typedef long long ll;
const int maxn = 1;
const int inf = 0x3f3f3f3f;
ll gcd(ll a, ll b)
{
	if (a < b)swap(a, b);
	return b == 0 ? a : gcd(b, a%b);
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
	while (T--)
	{
		ll a, b;
		cin >> a >> b;
		cout << ((gcd(a, b) == 1) ? "Finite" : "Infinite") << endl;
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