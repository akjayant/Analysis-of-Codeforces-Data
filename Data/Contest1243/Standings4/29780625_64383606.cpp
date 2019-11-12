#include <bits/stdc++.h>
using namespace std;

long long k ,n,beda;
bool sabi, first;
char s[10005],t[10005],atas,bawah;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>k;
	while(k--){
		cin>>n;
		for(int i =1;i<=n;i++)cin>>s[i];
		for(int i =1;i<=n;i++)cin>>t[i];
		sabi=1;
		first =1;
		beda=0;
		for(int i =1;i<=n;i++){
			if(beda>2){
				sabi=0;
				break;
			}
			if(s[i]!=t[i]&&first){
				atas = s[i];
				bawah = t[i];
				first = 0;
				beda++;
			}
			else if(s[i]!=t[i]){
				if(s[i]!=atas||t[i]!=bawah){

					sabi=0;
					break;
				}
				beda++;
			}
		}
		if(!sabi||beda==1)cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
}