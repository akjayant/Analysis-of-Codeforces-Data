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
int Test , n , a , b , c;
char Out[200];
void Input()
{
	if(fopen("trash.inp" , "r"))
		freopen("trash.inp" , "r" , stdin) , freopen("trash.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> Test;
}
void Solve()
{
	while(Test--)
	{
		cin >> n >> a >> b >> c;
		int x1 = 0;
		string st;
		cin >> st;
		for(int i = 0 ; i < n ; ++i) Out[i] = '0';
		for(int i = 0 ; i < n ; ++i)
		{
			if(st[i] == 'R' && b > 0) b-- , Out[i] = 'P' , x1++;
			if(st[i] == 'P' && c > 0) c-- , Out[i] = 'S' , x1++;
			if(st[i] == 'S' && a > 0) a-- , Out[i] = 'R' , x1++;
		}
		if(x1 < (n + 1) / 2)
		{
			cout << "NO" << '\n';
		}
		else
		{
			cout << "YES" << '\n';
			for(int i = 0 ; i < n ; ++i)
			{
				if(Out[i] == '0')
				{
					if(a > 0) a-- , cout << 'R';
					else
					{
						if(b > 0) b-- , cout << 'P';
						else c-- , cout << 'S';
					}
				}
				else cout << Out[i];
			}
			cout << '\n';
		}
	}
}
#undef int
int main()
{
	Input();
	Solve();
}