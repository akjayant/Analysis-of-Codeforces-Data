	#include <bits/stdc++.h>
	using namespace std; 
	#define ll long long
	#define pb push_back
	#define N 1000005
	ll a[N],b[N],c[N][2],fq[N]={0},f[N]={0},T,TT=1,p=(ll)(1e9+7);
	bool mycmp(ll x,ll y){
		return (x>y);
	}
	int main(){	
		ios_base::sync_with_stdio(false); cin.tie(NULL); 
		#ifndef ONLINE_JUDGE 
		freopen("i.txt", "r", stdin);
		#endif	
		cin>>TT;
		for(T=1;T<=TT;T++){
			ll n,i,j=0,l=0,r,k=0,m=0,ans=0,max_ele=INT_MIN,min_ele=INT_MAX,sum=0,x,y,z;
			string s,s1,s2,s3;
			cin>>n;
			for(i=0;i<n;i++){
				cin>>a[i];
			}
			sort(a,a+n);
			for(i=0;i<n;i++){
				ans=max(ans,min(a[i],(n-i)));
			}
			cout<<ans<<endl;
		}
		return 0;
	}