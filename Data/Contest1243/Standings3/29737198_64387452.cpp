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
		string s1,s2;
		cin>>s1>>s2;
		ll c=0;
		ll ar1[26],ar2[26];
		for(i=0;i<n;i++){
			if(s1[i]!=s2[i]){
				c++;
			}
			// ar1[s1[i]-'a']++;
			// ar2[s2[i]-'a']++;
		}
		ll flag=0;
		vector<ll>temp;

		if(c>2){
			cout<<"No\n";
			continue;
		}

		if(c==1){
			for(i=0;i<n;i++){
				if(s1[i]!=s2[i]){
					flag=1;
					break;
				}
			}
			if(!flag){
			cout<<"Yes\n";
		}else{
			cout<<"No\n";
		}
		continue;
		}

		j=-1;
		k=-1;

		for(i=0;i<n;i++){
			if(s1[i]!=s2[i]){
				if(j==-1){
				j=s1[i]-'a';
				k=s2[i]-'a';
			}else{
				if(s1[i]-'a'!=j){
					flag=1;
					break;
				}
				if(s2[i]-'a'!=k){
					flag=1;
					break;
				}
			}
			}
		}
		if(!flag){
			cout<<"Yes\n";
		}else{
			cout<<"No\n";
		}

	}
	return 0;
}