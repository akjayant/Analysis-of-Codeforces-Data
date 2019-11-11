#include <bits/stdc++.h>
const int N=1e5+10;
const int Mod=1e9+7;
int f[N];
char s[N];

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);std::cout.tie(0);
	std::cin>>s;
	if(s[0]=='w'||s[0]=='m'||s[1]=='w'||s[1]=='m'){
		std::cout<<'0';
		return 0;
	}
	f[0]=1;
	if(s[1]==s[0]&&(s[1]=='n'||s[1]=='u'))
		f[1]=2;
	else f[1]=1;
	int len=strlen(s);
	for(int i=2;i<len;++i)
		if(s[i]=='m'||s[i]=='w'){
			std::cout<<'0';
			return 0;
		}else{
			f[i]+=f[i-1];
			if(s[i]==s[i-1]&&(s[i]=='n'||s[i]=='u')){
				f[i]+=f[i-2];
			}
			f[i]%=Mod;
		}
	std::cout<<f[len-1]<<'\n';
	return 0;
}

