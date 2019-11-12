#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repp(i,a) for(int i=1;i<=a;i++)
#define eb emplace_back
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define Fi first
#define Se second
#define INF 987654321
#define IINF 987654321987654321
#define LINF 987654321987654321
//0x3F3F3F3F3F3F3F3Fll
#define sz(v) ((int)((v).size()))
#define all(v) v.begin(),v.end()
#define pq priority_queue
#define BIGMOD 9223372036854775783
#define PI 3.14159265358979
#define eps 1e-7
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<bool,bool> pbb;
typedef pair<ll,ll> pll;
typedef complex<double> base;
typedef pair<bool,int> pbi;
typedef pair<ll,int> pli;
typedef pair<pll,ll> plll;
const ll MOD=1e9+7;

vector<int> v[302];
int main(){
	int n;
	scanf("%d",&n);
	rep(i,0,n){
		if(i%2){
			rep(j,0,n){
				v[j].pb(i*n+j);
			}
		}
		else{
			for(int j=n-1;j>=0;j--){
				v[n-1-j].pb(i*n+j);
			}
		}
	}
	rep(i,0,n){
		for(auto e : v[i]){
			printf("%d ",e+1);
		}
		printf("\n");
	}
}
