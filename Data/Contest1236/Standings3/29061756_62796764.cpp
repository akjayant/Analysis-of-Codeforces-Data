/*Arnab's Code
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(n) push_back(n)
#define take(a,n) for(ll i=0;i<n;i++)cin>>a[i]
#define takes(a,n,st) for(ll i=st;i<n+st;i++)cin>>a[i]
ll sum(ll a[],ll n,ll s){ for(ll i=0;i<n;i++)s+=a[i]; return s;}
static ll a[400][400];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	ll n,i,j,k;
	cin>>n;
	for(i=0;i<n;i++){
		if(i%2 == 1){
			for(j=1;j<=n;j++){
				a[i][j-1]=i*n + j;
			}
		}
		else{
			for(j=n-1,k=1;k<=n;k++,j--){
				a[i][j]=i*n + k;
			}
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			cout<<a[j][i]<<" ";
		cout<<endl;
	}
	return 0;
}