#include<bits/stdc++.h>
#pragma GCC optimize ("-ffloat-store")
#define ll long long
#define For(i,a,b) for(ll i=a;i<=b;i++)
#define maxn 100002
#define pb push_back
#define X first
#define Y second
#define mod 1000000007
#define base 17
using namespace std;

ll f[maxn][4], g[maxn];
ll n,m;
void init(){
	f[1][2] = 1;
	f[1][1] = 1;	
	f[0][0] = 1;
	f[0][3] = 1;
	g[1] = 2;	
	For(i,2,maxn-1)	{
		f[i][0] = f[i-2][1] + f[i-2][3];
		f[i][3] = f[i-2][0] + f[i-2][2];
		f[i][1] = f[i-1][0] + f[i-1][2];
		f[i][2] = f[i-1][1] + f[i-1][3];
		For(j,0,3){
			f[i][j] %= mod;
			g[i] += f[i][j];
			g[i] %= mod;
		}		 
	}
//	For(i,1,10){
//		cout << "\n" << f[i][0] << " " << f[i][1] << " " << f[i][2] << " " << f[i][3] << "\n";
//	}
}
main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
    cout.tie(NULL);   
    cin >> n >> m;
    init();
    cout << (g[n] + g[m] - 2+mod)%mod;
}
