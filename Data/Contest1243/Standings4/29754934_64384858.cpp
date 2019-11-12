#include<bits/stdc++.h>
using namespace std;
char s[20202],t[20202];
long long n,k,i,j,a,b,c,x,y;
int main(){
	cin>>k;
	for(i=1;i<=k;i++){
		cin>>n>>s>>t;
		c=0;
		for(j=0;j<n;j++) if(s[j]!=t[j]){
			if(c==0){
				c++;
				a=j;
			}
			else if(c==1){
				c++;
				b=j;
			}
			else{
				c=-1;
				break;
			}
		}
		if(c==2 && s[a]==s[b] && t[a]==t[b]) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}