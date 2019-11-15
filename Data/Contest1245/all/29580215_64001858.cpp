#include <bits/stdc++.h>
using namespace std;
#define inta long long
#define ii pair<int,int>
#define mp make_pair
#define pb push_back

int main()
{
	ios_base::sync_with_stdio(0);
	
	int n;
	cin>>n;
	while(n--)
	{
		int a,b;
		cin>>a>>b;
		if(__gcd(a,b)==1) cout<<"Finite\n";
		else cout<<"Infinite\n";
	}
}