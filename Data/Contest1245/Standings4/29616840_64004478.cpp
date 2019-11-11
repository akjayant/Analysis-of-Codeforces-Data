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
		int n;
		cin >> n;
		int a, b, c;
		cin >> a >> b >> c;
		string pal;
		cin >> pal;
		int x=0, y=0, z=0;
		forn(i,n)
		{
			if(pal[i]=='S') x++;
			if(pal[i]=='R') y++;
			if(pal[i]=='P') z++;
		}
		if(min(a,x)+min(b,y)+min(c,z) >= (n+1)/2) 
		{
			cout << "YES\n";
			vector <char> v(n);
			vector <bool> visto(n,false);
			forn(i,n)
			{
				if(pal[i]=='S' && a>0) {v[i]='R'; a--; visto[i]=true;}
				if(pal[i]=='R' && b>0) {v[i]='P'; b--; visto[i]=true;}
				if(pal[i]=='P' && c>0) {v[i]='S'; c--; visto[i]=true;}
			}
			forn(i,n)
			{
				if(visto[i]==false)
				{
					if(a > 0) {v[i]='R'; a--;}
					else if(b >0) {v[i]='P'; b--;}
					else if(c > 0) {v[i]='S'; c--;}
				}
			}
			forn(i,n) cout << v[i];
			cout << "\n";
		}
		else cout << "NO\n";
	}
    return 0;
}
