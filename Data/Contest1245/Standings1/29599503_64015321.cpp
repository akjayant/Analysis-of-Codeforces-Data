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
const int N = 1e5 + 4;
const int MOD = 1e9 + 7;
int n , dp[N] , Res = 1;
string a;
void Input()
{
	if(fopen("trash.inp" , "r"))
		freopen("trash.inp" , "r" , stdin) , freopen("trash.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> a;
	n = a.size();
	a = ' ' + a;
}
void Solve()
{
	for(int i = 1 ; i <= n ; ++i) 
	{
		if(a[i] == 'm' || a[i] == 'w') 
		{
			cout << 0;
			exit(0);
		}
	}
	dp[1] = 1 , dp[2] = 2;
	a[n + 1] = '0';
	for(int i = 3 ; i <= n + 1 ; ++i)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
	}
	int num = 1;
	for(int i = 1 ; i <= n + 1 ; ++i)
	{
		if((a[i] == a[i - 1] && a[i] == 'u') || (a[i] == a[i - 1] && a[i] == 'n'))
		{
			num++;
		}
		else
		{
			Res = (Res * dp[num]) % MOD;
			num = 1;
		}
	}
	cout << Res;
}
#undef int
int main()
{
	Input();
	Solve();
}