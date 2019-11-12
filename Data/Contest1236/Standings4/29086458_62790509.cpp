#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<vector>
#include<set>
#include<string>
#include<cmath>
#include<cstring>
#define FF first
#define SS second
#define ll long long
#define pb push_back
#define pm make_pair
using namespace std;
typedef pair<int,int> PII;
const int MAX = 2e5 + 5;
const ll mod = 1e9 + 7;
ll qpow(ll a,ll b) {
	ll res = 1;
	while(b) {
		if(b&1) res = (res*a)%mod;
		b>>=1;a=a*a%mod;
	}return res%mod;
}
int main()
{
	ll n,m;
	cin>>n>>m;
	cout << qpow(qpow(2,m)-1,n) << endl;
	return 0 ;
}