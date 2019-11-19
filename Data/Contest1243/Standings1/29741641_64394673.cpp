#include<bits/stdc++.h>
#pragma GCC optimize ("-ffloat-store")
#define ll long long
#define For(i,a,b) for(ll i=a;i<=b;i++)
#define maxn 100002
#define pb push_back
#define X first
#define Y second
#define mod 1000000007
#define base 17
//#define db(x) cerr << "[" << #x << ": " << (x) << "] ";
#define db(x) ;
using namespace std;
typedef pair<ll,ll> ii;
ll cnt[30];
ll n,k;
string s,t;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
    cout.tie(NULL);   
    cin >> n;
    if(n==1){
    	cout << "1";
    	return 0;
	}
    ll sqrtt = sqrt(n);    
    ll smallestPrime = n;
    ll temp = n;
    For(i,2,sqrtt+1){
    	if(n%i==0){
    		smallestPrime = i;
    		break;
		}
	}
	
	while(temp%smallestPrime==0){
		temp/=smallestPrime;
	}
	if(temp !=1){
		cout << "1";
	}	else	{
		cout << smallestPrime;
	}
	return 0;
}
