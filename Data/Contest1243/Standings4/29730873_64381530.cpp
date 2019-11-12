#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int G=1e9+7;
const int NN=50005;
int n,m,k,x,y,cnt,val,num,tmp,Max;
//vector<Edge> ve[NN];
int dis[NN],inque[NN],b[NN];
int pos[NN];
string s,s2;

int main(){
	ios::sync_with_stdio(false);//cin.tie(0);cout.tie(0);
	int T;cin>>T;
	while(T--){
		cin>>n>>s>>s2;num=0;
		for(int i=0;i<n;i++){
			if(s[i]!=s2[i]){
				pos[++num]=i;
			}
		}
		if(num==2){
			if(s[pos[1]]==s[pos[2]]&&s2[pos[1]]==s2[pos[2]]) {
				cout<<"Yes"<<endl;
				continue;
			}
		}
		cout<<"No"<<endl;
	}
}


