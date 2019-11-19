#include<bits/stdc++.h>
#define ll long long 
#define ld long double
#define X first
#define Y second
#define pb push_back
#define max_el(x) max_element(x.begin(),x.end())-x.begin()
#define min_el(x) min_element(x.begin(),x.end())-x.begin()
#define mp make_pair
#define endl '\n'
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
// DONT USE MEMSET, USE VECTORS

int main(){
	int n;
	cin>>n;
	vector<ll> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}		
	sort(a.begin(), a.end());
	ll x,y;
	x = y = 0;

	int l = 0;
	int r = n-1;
	for(int i=0;i<n;i++){
		if(i%2==0){
			x += a[r];
			r--;
		}
		else{
			y += a[l];
			l++;
		}
	}
	cout<<(x*x+y*y)<<endl;
}
