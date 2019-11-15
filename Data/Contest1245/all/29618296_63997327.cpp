#include<vector>
#include<string>
#include<math.h>
#include<algorithm>
#include <iostream>
#include <iomanip>
#include <random>
#include <map>
#include <list>
#include<set>
using namespace std;

#define FOR(n) for(int i=0;i<n;++i)
#define FORj(n) for(int j=0;j<n;++j)
#define pb push_back
#define ll long long
#define vecI vector<int> 
#define vecII vector<vector<int>>
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define max4(a,b,c,d) max(max3(a,b,c),d)
int NOD(int a, int b)
{
	if (a*b == 0)return a + b;
	else
	{
		a = a % b;
		return NOD(b, a);
	}
}
int main()
{
	int t, a, b;
	cin >> t;
	while (t--)
	{
		cin >> a >> b;
		if (NOD(a, b) != 1)cout << "In";
		cout << "finite" << endl;
	}
}