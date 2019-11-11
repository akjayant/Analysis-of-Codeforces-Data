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
int Test;
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
		int a , b;
		cin >> a >> b;
		int x = __gcd(a , b);
		if(x == 1) cout << "Finite";
		else cout << "Infinite";
		cout << '\n';
	}
}
#undef int
int main()
{
	Input();
	Solve();
}