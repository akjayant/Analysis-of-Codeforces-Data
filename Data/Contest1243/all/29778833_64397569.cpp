#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize ("-ffloat-store") // to restrict undesirable precision
#pragma GCC optimize ("-fno-defer-pop")// to pop argument of function as soon as it returns
#define all(a) a.begin(),a.end()
#define ll long long int
#define ld long double
ll power(ll a,ll b,ll m){ if(b==0) return 1; if(b==1) return a%m; ll t=power(a,b/2,m)%m; t=(t*t)%m; if(b&1) t=((t%m)*(a%m))%m; return t;}
ll modInverse(ll a, ll m) { return power(a, m-2, m); }
#define ps push_back
#define fs first
#define takeline cin.ignore();
#define sc second
#define N 3000005
#define endl "\n"
#define mod 1000000007
//((1.0l)*BIG MULTIPLY MAGIC?)
// string to integer stoi()
// string to long long stoll()
// string.substr(position,length);
// integer to string to_string();
//-----------------------------------------------
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll t;
	cin>>t;
	while(t--){
		ll i,j,k,l,n;
		cin>>n;
		string ar,br;
		cin>>ar;
		cin>>br;

		ll fl[26]={0};
		for(i=0;i<n;i++){
			fl[ar[i]-'a']++;
			fl[br[i]-'a']++;
		}
		int flg=1;
		for(i=0;i<26;i++){
			if(fl[i]%2){
				flg=0;
				break;
			}
		}
		if(flg==0){
			cout<<"No"<<endl;
		}
		else{
			char cc;
			cout<<"Yes"<<endl;
			vector< pair<ll,ll> > vc;
			for(i=0;i<n;i++){
				if(ar[i]!=br[i]){
					ll c1=0,c2=0;
					for(j=i+1;j<n;j++){
						if(ar[j]==br[i]) c1++;
						if(br[j]==br[i]) c2++;
					}
				//	cout<<c1<<" "<<c2<<endl;
					if(c1>c2){
						for(j=i+1;j<n;j++){
							if(ar[j]==br[i]) break;
						}
						cc=br[i+1];
						br[i+1]=ar[j];
						ar[j]=cc;
						vc.ps({j,i+1});
						cc=ar[i];
						ar[i]=br[i+1];
						br[i+1]=cc;
						vc.ps({i,i+1});
					}
					else{
						for(j=i+1;j<n;j++){
							if(br[j]==br[i]) break;
						}
						cc=ar[i];
						ar[i]=br[j];
						br[j]=cc;
						vc.ps({i,j});
					}
				}
			}
			cout<<vc.size()<<endl;
			for(auto it:vc){
				cout<<it.fs+1<<" "<<it.sc+1<<endl;
			}
		}
	}
	return 0;
}