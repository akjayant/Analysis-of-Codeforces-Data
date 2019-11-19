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
		//cin>>TT;
		for(T=1;T<=TT;T++){
			ll n,i,j=0,l=-1,r,k=0,m=0,ans=0,max_ele=INT_MIN,min_ele=INT_MAX,sum=0,x,y,z;
			string s,s1,s2,s3;
			cin>>n;
			k=n;
			for(i=2;i<=sqrt(k);i++){
				if(k%i==0){
					m=i;
					ans++;
					while(k%i==0){
						k/=i;
					}
				}
			}
			if(k>1){
				m=k;
				ans++;
			}
			if(ans==1){
				cout<<m;
			}
			else{
				cout<<1;
			}
			cout<<endl;
		}
		return 0;
	}