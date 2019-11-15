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
			ll n,i,j=0,l=-1,r,k=0,m=0,ans=0,max_ele=INT_MIN,min_ele=INT_MAX,sum=0,x,y,z;
			string s,s1,s2,s3;
			cin>>n>>s1>>s2;
			vector<ll>v;
			for(i=0;i<n;i++){
				if(s1[i]!=s2[i]){
					v.pb(i);
				}
			}
			if(v.size()==0){
				cout<<"Yes";
			}
			else if(v.size()==2){
				if(s1[v[0]]==s1[v[1]] && s2[v[0]]==s2[v[1]]){
					cout<<"Yes";
				}
				else 
					cout<<"No";
			}
			else{
				cout<<"No";
			}
			cout<<endl;
		}
		return 0;
	}