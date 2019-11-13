#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define MAX 100005
#define pb push_back
#define T int t;cin>>t;while(t--)
#define vi vector<int>
#define ff first
#define ss second
using namespace std;
int func(int a,int b){
	if(b==0) return 1;
	if(b==1) return a;
	int x = func(a,b/2);
	// cout<<x<<endl;
	if(b%2==0) return ((x%MOD)*(x%MOD))%MOD;
	return (((a%MOD)*(x%MOD))%MOD*(x%MOD))%MOD;
}
int32_t main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    // cout<<func(2,m)<<endl;
    cout<<(func(func(2,m)-1,n))%MOD<<endl;
	return 0;
}