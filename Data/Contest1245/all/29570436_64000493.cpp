#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1000005;
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
const int mod=1e9+7;
typedef pair<int,int> pii;
#define X first
#define Y second
char s[N];
ll f[N];
int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	f[0]=1;
	for(int i=1;i<=n;i++) {
		if(s[i]=='w'||s[i]=='m') {
			puts("0");
			return 0;
		}
		f[i]=f[i-1];
		if(i!=1&&s[i]==s[i-1]&&(s[i]=='u'||s[i]=='n')) f[i]+=f[i-2];
		f[i]%=mod;
	}
	cout<<f[n];
	return 0;
} 