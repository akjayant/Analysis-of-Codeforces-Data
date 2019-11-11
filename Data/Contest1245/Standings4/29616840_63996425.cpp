#include <bits/stdc++.h>
using namespace std;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

typedef long long ll;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(int i = (a); i < (int) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "===============================" << endl

//#define DEBUG

int mcd(int a, int b)
{
	while(a!=0 && b!=0)
	{
		if(a > b) a%=b;
		else b%=a;
	}
	if(a==0) return b;
	else return a;
}

int main()
{ 	
	FIN;
	
	#ifdef DEBUG
		freopen("test_1.txt", "r", stdin);
	#endif
	
	int t;
	cin >> t;
	while(t--)
	{
		int n, m;
		cin >> n >> m;
		if(mcd(n,m) == 1) cout << "Finite\n";
		else cout << "Infinite\n";
	}
    return 0;
}
