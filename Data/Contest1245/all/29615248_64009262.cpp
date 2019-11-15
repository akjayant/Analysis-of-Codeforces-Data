#include<bits/stdc++.h>
using namespace std;
 
long double p[1003];
 
int main(){
	
	int t;
	cin>>t;
	while(t--){
		int n,r,p,s;
		cin>>n>>r>>p>>s;
		string ss;
		cin>>ss;
		int cnt[4];
		cnt[0] = cnt[1] = cnt[2] = 0;
		for(int i=0;i<(int)ss.size();i++){
			if(ss[i] == 'R') cnt[0]++;
			if(ss[i] == 'P') cnt[1]++;
			if(ss[i] == 'S') cnt[2]++;
		}
		string sol = ss;
		int ans = min(r,cnt[2])+min(p,cnt[0])+min(s,cnt[1]);
		if(ans >= ((int)ss.size()+1)/2){
			cout<<"YES"<<endl;
			for(int i=0;i<(int)ss.size();i++){
				if(ss[i] == 'R'){
					if(p){
						sol[i] = 'P';
						p--;
						continue;
					}
					
				}
				if(ss[i] == 'P'){
					if(s){
						sol[i] = 'S';
						s--;
						continue;
					}
					
				}
				if(ss[i] == 'S'){
					if(r){
						sol[i] = 'R';
						r--;
						continue;
				}
				
				}
				sol[i] = '*';
			}
			for(int i=0;i<(int)ss.size();i++){
				if(sol[i] == '*'){
					if(r){
						cout<<'R';
						r--;
						continue;
					}
					if(p){
						cout<<'P';
						p--;
						continue;
					}
					if(s){
						cout<<'S';
						s--;
						continue;
					}
				}
				else{
					cout<<sol[i];
				}
			}
			cout<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	
	return 0;
}
