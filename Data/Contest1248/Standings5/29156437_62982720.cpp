#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;

using namespace std;
lli ar[100001];
int main()
{
	lli n , tot = 0;
	cin>>n;
	REP(i , n) cin>>ar[i] , tot += ar[i];
	sort(ar+1 , ar+n+1);
	lli a = 0  , b = 0;
	for(int i=1;i<=n/2;i++)
	a += ar[i];
	tot -= a;
	
	cout<<(a * a + tot*tot);
}
