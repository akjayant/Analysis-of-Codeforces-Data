#include<bits/stdc++.h>

#define pb push_back
#define all(v) (v).begin(),(v).end()
#define ll long long int
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define sz(a) (ll)(a.size())
#define mod 1000000007
#define fi first
#define se second
#define pii pair<ll,ll>

using namespace std;

int main(){
	ll t,i,j,k,m,n;
	t=1;
	cin>>t;
	while(t--){
		cin>>n;
		ll ar1[26]={0},ar2[26]={0};
		string s1,s2;
		cin>>s1>>s2;
		for(i=0;i<n;i++){
			ar1[s1[i]-'a']++;
			ar1[s2[i]-'a']++;
		}
		ll flag=0;
		for(i=0;i<26;i++){
			if(ar1[i]%2!=0){
				flag=1;
				break;
			}
		}
		if(flag){
			cout<<"No\n";
			continue;
		}
		cout<<"Yes\n";
		vector<pair<ll,ll> >v;
		for(i=0;i<n-1;i++){
			ll f=0;
			if(s1[i]!=s2[i]){
				for(j=i+1;j<n;j++){
					if(s1[i]==s1[j]){
						v.pb({j,i});
						swap(s1[j],s2[i]);
						f=1;
						break;
					}
				}
				if(f==0){
					for(j=i+1;j<n;j++){
						if(s1[i]==s2[j]){
							v.pb({i+1,j});
							swap(s1[i+1],s2[j]);
							swap(s1[i+1],s2[i]);
							v.pb({i+1,i});
							break;
						}
					}

				}
			}
		}
		cout<<v.size()<<"\n";
		for(auto it:v){
			cout<<it.fi+1<<" "<<it.se+1<<"\n";
		}

	}
	return 0;
}