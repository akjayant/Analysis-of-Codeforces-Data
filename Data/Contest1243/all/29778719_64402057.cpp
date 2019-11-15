#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mod 1000000007
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main(){
	fast;
	ll k;
	cin>>k;
	while(k--){
		string s,t;
		ll n;
		cin>>n>>s>>t;
		ll ar[26]={0};
		ll br[26]={0};
		for(ll i=0;i<n;i++){
			ar[s[i]-'a']++;
			br[t[i]-'a']++;
		}
		ll ans=1;
		for(ll i=0;i<26;i++){
			if((ar[i]+br[i])%2)ans=0;
		}
		if(ans){
			ll ansr[n+n][2];
			ll p=0;
			for(ll i=0;i<n;i++){
				if(s[i]!=t[i]){
					int x=0;
					for(ll j=i+1;j<n;j++){
						if(s[j]==s[i]){
							x=1;
							ansr[p][0]=j;
							ansr[p][1]=i;
							swap(s[j],t[i]);
							p++;
							break;							
						}
					}
					if(x==0){
						for(ll j=i+1;j<n;j++){
							if(t[j]==s[i]){
								ansr[p][0]=j;
								ansr[p][1]=j;
								swap(s[j],t[j]);
								p++;
								ansr[p][0]=j;
								ansr[p][1]=i;
								swap(s[j],t[i]);
								p++;
								break;
							}
						}
					}
				}
			}
			cout<<"YES\n"<<p<<"\n";
			for(ll i=0;i<p;i++){
				cout<<ansr[i][0]+1<<" "<<ansr[i][1]+1<<"\n";
			}
		}
		else cout<<"NO\n";
	}
	return 0;
}
