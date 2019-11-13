#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int maxn=1e5+5;
ll tab[maxn];
void init(){
	tab[1]=1;tab[2]=2;
	for(int i=3;i<maxn;i++){
		tab[i]=(tab[i-1]+tab[i-2])%mod;
	}
}
int main(){
	init();
	string s;
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++){
		if(s[i]=='m'||s[i]=='w'){
			puts("0");
			return 0;
		}
	}
	ll ans=1;
	for(int i=0;i<len;i++){
		if(s[i]=='n'||s[i]=='u'){
			int j=i+1;
			while(s[j]==s[j-1])j++;
			ans=(ans*tab[j-i])%mod;
			i=j-1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
