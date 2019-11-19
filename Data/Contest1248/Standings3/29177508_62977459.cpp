#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
using namespace std;

typedef int ll;
 
#define int long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define endl '\n'
 
typedef pair<int,int>pii;
typedef pair<int,pair<int,int> > piii;
 
const int mod=1e9+7;
 
int POWER[65];
int power(int a, int b) {int ret=1;while(b) {if(b&1) ret*=a;a*=a;if(ret>=mod) ret%=mod;if(a>=mod) a%=mod;b>>=1;}return ret;}
int inv(int x) {return power(x,mod-2);}
 
void precompute() {
	POWER[0]=1;
	for(int i=1;i<63;i++) POWER[i]=POWER[i-1]<<1LL;
}

int gcd(int a, int b) {
   if (b == 0)
   return a;
   return gcd(b, a % b);
}

ll main() {
	// freopen("Task.in", "r", stdin);freopen("Task.out", "w", stdout);

	int t;
	cin>>t;

	while (t--) {
		int n;
		cin>>n;

		int evp=0, odp=0,evq=0,odq=0;
		for (int i=0; i<n; i++) {
			int x;
			cin>>x;

			if(x%2)	odp++;
			else evp++;
		}

		cin>>n;

		for (int i=0; i<n; i++) {
			int x;
			cin>>x;

			if(x%2)	odq++;
			else evq++;
		}

		cout<<odp*odq+evp*evq<<endl;
	}
}
 