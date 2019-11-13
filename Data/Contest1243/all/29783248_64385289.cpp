/*
 * @Author: Snicky
 * @Date: 2019-11-06 23:14:39 
 * @Last Modified by: Simon
 * @Last Modified time: 2019-11-06 23:14:39
 */ 
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define maxn 205
#define INF 0x3f3f3f3f
char a[maxn],b[maxn];
int num[maxn];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;cin>>T;
	while(T--){
		memset(num,0,sizeof(num));
		vector<pair<int,int> >ans;
		int n;cin>>n;
		cin>>a+1>>b+1;
		for(int i=1;i<=n;i++){
			num[a[i]]++;num[b[i]]++;
		}
		bool flag=0;
		for(int i=0;i<26;i++){
			if(num[i+'a']%2){
				flag=1;break;	
			}
		}
		if(flag){
			cout<<"No"<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			if(a[i]==b[i]) continue;
			for(int j=i+1;j<=n;j++){
				if(a[j]==a[i]){
					swap(a[j],b[i]);
					ans.push_back({j,i});
					break;
				}
			}	
			if(a[i]==b[i]) continue;
			for(int j=i+1;j<=n;j++){
				if(b[j]==a[i]){
					swap(a[j],b[j]);
					swap(a[j],b[i]);
					ans.push_back({j,j});
					ans.push_back({j,i});
					break;
				}
			}
		}
		if(ans.size()>2*n){
			cout<<"No"<<endl;
			continue;
		}
		cout<<"Yes"<<endl;
		cout<<ans.size()<<endl;
		for(auto v:ans) cout<<v.first<<' '<<v.second<<endl;
	}
	return 0;
}
