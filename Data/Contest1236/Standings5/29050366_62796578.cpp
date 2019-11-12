#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
typedef long long ll;
ll mod = 1000000007;
ll raise(ll a, ll n){
  if(n == 0)return 1;
  if(n == 1)return a;
  ll x = 1;
    x *= raise(a,n/2);
    x %= mod;
    x *= x;
    x %= mod;
    if(n%2)x*= a;
    x %= mod;
    return x;
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, arr[500009];
	cin>>n;
	
	for(int i = 0; i < n; i++){
		if(i %2 == 0){
	
		for(int j = 1; j <= n; j++){
			arr[n*i + j] = j;
		}
		}
		else{
			for(int j = 1; j <= n; j++){
			arr[n*i + j] = n - j + 1;
		}
		}
	}
	for(int j = 1; j <= n; j++){
	    for(int i = 1; i <= n*n; i++){
			if(arr[i] == j) cout<<i<<" ";
		}
		cout<<'\n';
	}
}