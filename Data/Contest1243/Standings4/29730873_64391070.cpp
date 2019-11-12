#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int G=1e9+7;
const int NN=50005;
int n,m,k,x,y,cnt,val,num,tmp,Max;
//vector<Edge> ve[NN];
int cont[30],inque[NN],b[NN];
int pos[NN];
string s,s2;
struct node{
	int x,y;
	node(int _x=0,int _y=0):x(_x),y(_y){}
}ans[NN];

int main(){
	ios::sync_with_stdio(false);//cin.tie(0);cout.tie(0);
	int T;cin>>T;
	while(T--){
		cin>>n>>s>>s2;num=0;
		memset(cont,0,sizeof(cont));
		for(int i=0;i<n;i++){
			cont[s[i]-'a']++;
			cont[s2[i]-'a']++;
		}
		for(int i=0;i<=25;i++){
			if(cont[i]%2) {
				cout<<"No"<<endl;
				goto out;
			}
		}
		for(int i=0;i<n;i++){
			if(s[i]==s2[i]) continue;
			int flag=0;
			for(int j=i+1;j<n;j++){
				if(s[j]==s[i]){
					s[j]=s2[i];
					ans[++num]=node(j,i);
					flag=1;
					break;
				}
			}
			if(!flag){
				for(int j=i+1;j<n;j++){
					if(s2[j]==s[i]){
						s2[j]=s[n-1];
						s[n-1]=s2[i];
						ans[++num]=node(n-1,j);
						ans[++num]=node(n-1,i);
						break;
					}
				}
			}
		}
		cout<<"Yes"<<endl;
		cout<<num<<endl;
		for(int i=1;i<=num;i++){
			cout<<ans[i].x+1<<' '<<ans[i].y+1<<endl;
		}
		out:;
	}
}


