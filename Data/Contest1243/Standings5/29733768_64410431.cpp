#include <bits/stdc++.h> 
using namespace std;
#define pb push_back
#define vi vector<int>
#define vpi vector<pair<ll,ll> >
#define mp make_pair
#define F first
#define S second
#define ll long long int
#define mod 1000000007
#define wh(a) cerr<<#a<<"  is  "<<a<<endl;
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n,i,j;
		cin>>n;
		string s,t;
		cin>>s>>t;
		int num[26];
		memset(num,0,sizeof(num));
		for(i=0;i<n;++i){
			num[s[i]-'a']++;
			num[t[i]-'a']++;
		}
		int pos=1;
		for(i=0;i<26;++i){
//			cout<<"i="<<i<<" "<<num[i]<<endl;
			if(num[i]%2==1){
				pos=0;
				break;
			}
		}
//		wh(pos);
		if(pos==0){
			cout<<"No"<<endl;
			continue;
		}
		cout<<"Yes"<<endl;
		vector<pair<int ,int> > ans;
		for(i=0;i<n;++i){
			if(s[i]==t[i]){
				continue;
			}
			else{
				int ok=0;
				char temp;
				for(j=i+1;j<n;++j){
					if(s[j]==s[i]){
						ok=1;
						temp=t[i];
						t[i]=s[j];
						s[j]=temp;
						ans.pb(mp(j+1,i+1));
						break;
					}
				}
				if(ok==0){
					for(j=i+1;j<n;++j){
						if(t[j]==s[i]){
							temp=t[j];
							t[j]=s[j];
							s[j]=temp;
							ans.pb(mp(j+1,j+1));
							temp=t[i];
							t[i]=s[j];
							s[j]=temp;
							ans.pb(mp(j+1,i+1));
							break;
						}
					}	
				}
			}
		}
		cout<<(int)ans.size()<<endl;
		for(i=0;i<(int)ans.size();++i){
			cout<<ans[i].F<<" "<<ans[i].S<<endl;
		}
	}
	return 0;
}