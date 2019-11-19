#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define II pair < int , int > 
#define pb push_back
#define Hmax priority_queue < int > 
#define Hmin priority_queue < int , vector < int > , greater < int > >
#define IImax priority_queue < II >  
#define IImin priority_queue < II , vector < II > , greater < II > >
#define FOR(i , a , b) for(int i = a ; i <= b ; ++i)
#define FOD(i , a , b) for(int i = a ; i >= b ; --i)
const int inf = 1e15;
bitset < 31 > B1 , B2;
int l , r , Test , dp[35][2][2][2][2] , vs[35][2][2][2][2] , f1[35] , f2[35];
void Input()
{
	cin >> l >> r;
}
int Get_Dp(int id , int isLess1 , int isLess2 , int isVal1 , int isVal2)
{
	int &foo = dp[id][isLess1][isLess2][isVal1][isVal2];
	int &vis = vs[id][isLess1][isLess2][isVal1][isVal2];
	if(vis) return foo;
	else vis = 1;
	if(id == 0)
	{
		foo = 1;
		return 1;
	}
	foo = 0;
	int End1 = isLess1 ? 1 : f1[id];
	int End2 = isLess2 ? 1 : f2[id];
	for(int i = 0 ; i <= End1 ; ++i)
	{
		for(int j = 0 ; j <= End2 ; ++j)
		{
			if(i == 1 && j == 1) continue;
			int newLess1 = isLess1 || i < End1;
			int newLess2 = isLess2 || j < End2;
			int newVal1 = isVal1 || i > 0;
			int newVal2 = isVal2 || j > 0;
			foo = foo + Get_Dp(id - 1 , newLess1 , newLess2 , newVal1 , newVal2);
		}
	}
	return foo;
}
int Get(int x1 , int x2)
{
	B1 = bitset < 31 > (x1);
	B2 = bitset < 31 > (x2);
	for(int i = 32 ; i >= 1 ; --i)
	{
		f1[i] = B1[i - 1];
		f2[i] = B2[i - 1];
	}
	memset(vs , 0 , sizeof vs);
	return Get_Dp(32 , 0 , 0 , 0 , 0);
}
void Solve()
{
	if(l != 0) cout << Get(r , r) - Get(l - 1 , r) - Get(r , l - 1) + Get(l - 1 , l - 1) << '\n';
	else
	{
		cout << Get(r , r) << '\n';
	}
}
#undef int
int main()
{
	if(fopen("trash.inp" , "r"))
		freopen("trash.inp" , "r" , stdin) , freopen("trash.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> Test;
	while(Test--)
	{
		Input();
		Solve();
	}
}