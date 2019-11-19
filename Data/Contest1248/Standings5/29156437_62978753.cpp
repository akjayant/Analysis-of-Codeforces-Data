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
int main()
{
	int t , n , m , x;
	cin>>t;
	while(t--)
	{
		cin>>n;
		lli odd1 = 0 , eve1 = 0;
		lli odd2 = 0 , eve2 = 0;
		lli ans = 0;
		REP(i , n)
		{
			cin>>x;
			if(x % 2) odd1++;
			else	eve1++;
		}
		cin>>m;
		REP(i , m)
		{
			cin>>x;
			if(x % 2) odd2++;
			else eve2++;
		}
		
		cout<<(odd1*odd2 + eve1*eve2)<<endl;
	}
}
