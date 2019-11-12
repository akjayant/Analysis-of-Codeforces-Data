/*
 * @Author: Snicky
 * @Date: 2019-11-06 23:11:00 
 * @Last Modified by: Simon
 * @Last Modified time: 2019-11-06 23:11:00
 */ 
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define maxn 200005
#define INF 0x3f3f3f3f
char a[maxn],b[maxn];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		cin>>a+1>>b+1;
		char la,ra,lb,rb;
		int tmp=0;
		for(int i=1;i<=n;i++){
			if(a[i]!=b[i]){
				tmp++;
				if(tmp==1){
					la=a[i];lb=b[i];
				}
				else{
					ra=a[i];rb=b[i];
				}
			}	
		}
		if(tmp>2){
			cout<<"No"<<endl;
			continue;
		}
		if(la==ra&&lb==rb){
			cout<<"Yes"<<endl;
			continue;
		}
		cout<<"No"<<endl;
	}
	return 0;
}
