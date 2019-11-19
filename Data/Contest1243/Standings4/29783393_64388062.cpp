/*suri_kumkaran*/

#include <bits/stdc++.h>

using namespace std;

#define UB upper_bound
#define LB lower_bound
#define BS binary_search
#define MP make_pair
#define EB emplace_back
#define endl "\n"
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define F first
#define S second
#define ALL(a) (a).begin(),(a).end()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

typedef long long int int64;
typedef vector<int64> VI64;
typedef vector<pair<int64,int64>> VII64;
typedef vector<string> VS;
typedef vector<vector<int64>> VVI;

int main()
{
	IOS;
	int64 T=1;
	//cin>>T;
	while(T--)
	{
		int64 n,i;
		cin>>n;
		int64 g=n;
		for(i=2;i*i<=n;i++)
		{
			if(n%i==0)
			{
				g=__gcd(i,g);
				g=__gcd(g,n/i);
			}
		}
		cout<<g;
	}

	return 0;
}