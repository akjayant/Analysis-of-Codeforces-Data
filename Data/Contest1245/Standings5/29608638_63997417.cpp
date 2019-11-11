//#pragma GCC optimize("Ofast")
#include <set>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <bitset>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define zy 2333333
#define bql 2147483647
using namespace std;
int t;
int main() 
{
	fast;
	cin>>t;
	while (t--)
	{
		int a,b;
		cin>>a>>b;
		if (__gcd(a,b)==1)
		    cout<<"Finite"<<endl;
		else 
		    cout<<"Infinite"<<endl;
	}
	return 0;
}