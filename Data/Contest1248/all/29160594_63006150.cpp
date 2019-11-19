#include <bits/stdc++.h>
#include <stdio.h>
#include <string.h>
using namespace std;

typedef long long ll;
typedef unsigned long long llu;
#define filein freopen("input.txt", "r", stdin)
#define fileout freopen("output.txt", "w", stdout)
#define inf 1000000009
#define ff first
#define ss second
#define pb push_back
#define mk make_pair
#define pll pair<ll, ll>

#define MX 100005
#define mod 1000000007
ll n, m, arr[MX], ans[MX];

void gen()
{
    arr[1] = 2;
    arr[2] = 4;
    arr[3] = 6;

    for(int i = 4; i < MX; i++) {
        arr[i] = ((arr[i-1]%mod) + (( (((arr[i-1]-arr[i-2])+mod)%mod) + (((arr[i-2]-arr[i-3])+mod)%mod) ) % mod))%mod;
    }
}

int main()
{
	gen();

	cin>>n>>m;

	ans[1] = arr[n];
	ans[2] = (ans[1]+2)%mod;
	ans[3] = (ans[2]+2)%mod;

    for(int i = 4; i <= m; i++) {
		ans[i] = ((ans[i-1]%mod) + (( (((ans[i-1]-ans[i-2])+mod)%mod) + (((ans[i-2]-ans[i-3])+mod)%mod) ) % mod))%mod;
    }

    cout<<ans[m]<<endl;
}
