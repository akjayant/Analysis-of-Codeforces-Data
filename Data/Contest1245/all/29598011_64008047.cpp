#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef complex<double> cp;
typedef pair<int,int> pii;

const int maxn=(int)2e5+9;
const ll mod=(ll)1e9+7;
const db pi=acos(-1);
const db eps=1e-15;

#define dbg(x) cerr<<#x<<" is "<<x<<endl;

int n;
int f[maxn];
char s[maxn];

void init(){
	scanf("%s",s);
	f[1]=1;
	f[2]=2;
	for(int i=3;i<maxn;i++){
		f[i]=(f[i-1]+f[i-2])%mod;
	}
}

char as[maxn];

int main(){
	init();
	ll ans=1;
	int cnt=1;
	n=strlen(s);
	for(int i=0;i<=n;i++){
		if(s[i]=='w'||s[i]=='m'){
			printf("0");
			return 0;
		}
		if(!i)continue;
		if(s[i]==s[i-1])cnt++;
		else{
			if(s[i-1]=='u'||s[i-1]=='n'){
				ans=ans*f[cnt]%mod;
			}
			cnt=1;
		}
	}
	printf("%lld",ans);
	return 0;
}

