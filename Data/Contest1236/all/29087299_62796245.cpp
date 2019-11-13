#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <iomanip>
#include <string>
#include <map>

using namespace std;


typedef long long ll;
typedef vector<ll> vi;
typedef vector<vector <ll> > vvi;
typedef pair<ll,ll> ii;
typedef vector <ii> vii;
#define REP(i,a,b)\
for (ll i=a; i<b; i++)
#define fastIO  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

/*ll toint(const string &s) { stringstream ss; ss << s; ll x; ss >> x; return x; }
string tostring ( ll number ){  stringstream ss; ss<< number; return ss.str();}*/


int main()
{
    fastIO;

	ll n;
	cin>>n;
	vi V(n*n);
	vi T(n);
	REP(i,0,n)
		T[i]=i;
	REP(i,0,n*n)
	{
		if ((i/n)%2==0)
		{
			V[i]=T[i%n];
		}
		else
		{
			V[i]=T[n-1-(i%n)];
		}
	}
	REP(j,0,n)
	{
		REP(i,0,n*n)
		{
			if (V[i]==j)
			{
				cout<<i+1<<" ";
			}
		}
		cout<<endl;
	}
}