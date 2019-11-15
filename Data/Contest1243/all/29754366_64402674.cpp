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
			vector<ll>v1(26,0);
			vector<ll>v2(26,0);
			for(i=0;i<n;i++){
				v1[s1[i]-'a']++;
			}
			for(i=0;i<n;i++){
				v2[s2[i]-'a']++;
			}
			k=0;
			for(i=0;i<26;i++){
				if((v1[i]+v2[i])%2!=0)
					k=1;
			}
			if(k==1){
				cout<<"No"<<endl;
			}
			else{
				cout<<"Yes"<<endl;
				vector<pair<ll,ll>>ans;
				for(i=0;i<n-1;i++){
					if(s1[i]!=s2[i]){
						k=0;
						for(j=i+1;j<n;j++){
							if(s1[i]==s1[j]){
								k=1;
								break;
							}
						}
						if(k==1){
							swap(s2[i],s1[j]);
							ans.pb({j+1,i+1});
						}	
						else{
							for(j=i+1;j<n;j++){
								if(s1[i]==s2[j]){
									break;
								}
							}
							swap(s1[i+1],s2[j]);
							ans.pb({i+2,j+1});
							swap(s1[i+1],s2[i]);
							ans.pb({i+2,i+1});
						}
					}		
				}
				cout<<ans.size()<<endl;
				for(i=0;i<ans.size();i++){
					cout<<ans[i].first<<" "<<ans[i].second<<endl;
				}
			}
		}
		return 0;
	}