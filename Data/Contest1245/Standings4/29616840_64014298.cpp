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

vector <ll> cont(100005);
ll modu=(ll) (1e9+7);

void funcion()
{
	cont[1]=1;
	cont[2]=2;
	for(int i=3; i<=100002; i++)
	{
		cont[i]=cont[i-1]+cont[i-2];
		cont[i]%=modu;
	}
}

int main()
{ 	
	FIN;
	
	#ifdef DEBUG
		freopen("test_2.txt", "r", stdin);
	#endif
	
	
	funcion();
	string pal;
	cin >> pal;
	int n=pal.size();
	forn(i,n)
	{
		if(pal[i]=='m') {cout << "0" << endl; return 0;}
		if(pal[i]=='w') {cout << "0" << endl; return 0;}
	}
	ll ans=1;
	forn(i,n)
	{
		//DBG(ans);
		if(pal[i]=='u')
		{
			ll ind=1; i++;
			while(i<n && pal[i]=='u') {i++; ind++;}
			ans*=cont[ind];
			ans%=modu;
			i--;
		}
		if(pal[i]=='n')
		{
			ll ind=1; i++;
			while(i<n && pal[i]=='n') {i++; ind++;}
			ans*=cont[ind];
			ans%=modu;
			i--;
		}
	}
	cout << ans << endl;
    return 0;
}
