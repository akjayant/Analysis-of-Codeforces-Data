#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n; string a,b; int cnt[27],here,sw;
struct st{
	int f,s;
};
queue<st> ans;
int main() { 
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
    	cin>>n;
    	cin>>a;
    	cin>>b;
    	for(int i=0;i<=26;i++) cnt[i]=0;
    	for(int i=0;i<n;i++) cnt[a[i]-'a']++, cnt[b[i]-'a']++;
    	int tr=1;
    	for(int i=0;i<=26;i++) if(cnt[i]%2) tr=0;
		if(tr==0){
			cout<<"No\n";
			continue;
		}
		for(int i=0;i<n;i++){
			if(a[i]==b[i]) continue;
			
			//a에 똑같은 게 있는가 
			here=0;
			for(int j=i+1;j<n;j++){
				if(a[i]==a[j]){
					here=j;
					break;
				}
			}
			if(here){
				ans.push({here,i});
				a[here]=b[i];
				continue;
			}
			
			//b에 똑같은 게 있는가.
			here=0;
			for(int j=i+1;j<n;j++) {
				if(a[i]==b[j]){
					here=j;
					break;
				}
			}
			if(here){
				ans.push({here,here});
				b[here]=a[here];
				a[here]=a[i];
				ans.push({here,i});
				a[here]=b[i];
			}
		}
		cout<<"Yes\n";
		cout<<ans.size()<<'\n';
		while(!ans.empty()){
			cout<<ans.front().f+1<<' '<<ans.front().s+1<<'\n';
			ans.pop();
		}
	}
}