#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define mod 1000000007
#define int long long
#define ll long long
#define EPS 0.00000000000001
#define ld long double
#define inf 1000000002
#define N 500000

int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}

int32_t main()
{
	IOS;
	#ifndef ONLINE_JUDGE
    freopen("int.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int a,b;
   		cin >> a >> b;
   		int g = gcd(a,b);
   		if(g == 1)
   			cout << "Finite";
   		else
   			cout << "Infinite";
   		cout << endl;
   	}

	return 0;
}