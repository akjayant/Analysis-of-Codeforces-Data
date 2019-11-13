#include<bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define ld long double
#define endl "\n"
#define ld long double
#define ff first
#define ss second
#define pi pair<float,int> 
#define PI 3.141592653589793238462643383279502884L
#define mp make_pair
#define pb push_back
#define forall(i,n) for(int i=0;i<n;i++)
ll mod = 998244353;
ll mod1 = 1e9 + 7;
const int N= 1e5+5;

ll expo(ll a,ll b){
	if(b==0)return 1;
	ll y=expo(a,b/2);
	
	if(b%2==1)return (((y*y)%mod1)*a)%mod1;
	return (y*y)%mod1;
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ll n,m;
	cin>>n>>m;
	ll x= expo(2,m)-1;
	ll y=expo(x,n);
	
	cout<<y;	
	
	return 0;
}