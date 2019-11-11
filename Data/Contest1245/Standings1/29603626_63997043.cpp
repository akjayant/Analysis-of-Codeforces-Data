#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5,Mod=1e9+7;
char s[N];
int f[N][2];
int main(){
	scanf ("%s",s+1);
	int n=strlen(s+1);f[0][0]=1;
	for (int i=1;i<=n;i++)
		if (s[i]=='m'||s[i]=='w'){
			puts("0");
			return 0;
		}
	for (int i=1;i<=n;i++){
		if (s[i]=='n'||s[i]=='u')
			if (s[i]==s[i-1])
				f[i][1]=f[i-1][0];
		f[i][0]=(f[i-1][0]+f[i-1][1])%Mod;
	}
	printf ("%d",(f[n][0]+f[n][1])%Mod);
	return 0;
}
