#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;

long long k ,n,byk, freq[1000];
bool ada,sabi;
char s[10005],t[10005],atas,bawah;
vector<pair<int,int> > v;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>k;
	while(k--){
		cin>>n;
		memset(freq,0,sizeof(freq));
		v.clear();
		byk=0;
		for(int i =1;i<=n;i++){
			cin>>s[i];
			freq[s[i]]++;
		}
		for(int i =1;i<=n;i++){
			cin>>t[i];
			freq[t[i]]++;
		}
		sabi=1;
		for(int i = 'a';i<='z';i++){
			if(freq[i]%2==1){
				// cout<<freq[i]<<' '<<i<<endl;
				sabi=0;
				break;
			}
		}
		if(!sabi){
			cout<<"No"<<endl;
			continue;
		}
		cout<<"Yes"<<endl;
		for(int i =1;i<=n;i++){
			if(s[i]==t[i])continue;
			ada=0;
			for(int j = i+1;j<=n;j++){
				if(s[i]==s[j]){
					ada=1;
					swap(t[i],s[j]);
					v.pb({j,i});
					byk++;
					break;
				}
			}
			if(!ada){
				for(int j =i+1;j<=n;j++){
					if(t[j]==s[i]){
						swap(s[i+1],t[j]);
						swap(s[i+1],t[i]);
						v.pb({i+1,j});
						v.pb({i+1,i});
						byk+=2;
						break;
					}
				}
			}
		}
		cout<<byk<<endl;
		for(int i =0;i<v.size();i++){
			cout<<v[i].fi<<' '<<v[i].se<<endl;
		}

	}
}