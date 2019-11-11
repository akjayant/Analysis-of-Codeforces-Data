#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define inf 0x3f3f3f3f
#define inff 0x3f3f3f3f3f3f3f3f
#define ll long long
#define ull unsigned long long
#define sscc ios::sync_with_stdio(false);cin.tie(0);
#define ms(a) memset(a,0,sizeof(a))
#define mss(a) memset(a,-1,sizeof(a))
#define msi(a) memset(a,inf,sizeof(a))
using namespace std;

inline ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
inline ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
int moth[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int dir[4][2]={1,0 ,0,1 ,-1,0 ,0,-1};
int dirs[8][2]={1,0 ,0,1 ,-1,0 ,0,-1, -1,-1 ,-1,1 ,1,-1 ,1,1};

const int mod=1e9+7;

ll _pow(ll aa,ll nn)
{
	ll ans=1;
	while(nn){
		if(nn&1)
			ans=(ans*aa)%mod;
		aa=(aa*aa)%mod;
		nn>>=1;
	}
	return ans;
}

inline ll read()
{
    register ll now = 0;
    register char ch = getchar();
    register bool sign = false;
    while (!isdigit(ch)) {
        if (ch == '-') sign = true;
        ch = getchar();
    }
    while (isdigit(ch)) {
        now = (now << 1) + (now << 3) + ch - '0';
        ch = getchar();
    }
    return (sign == true ? -now : now);
}
inline unsigned long long get_hash()
{
    register unsigned long long ret = 1;
    register char ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) {
        ret = (ret * 31 + ch);
        ch = getchar();
    }
    return ret;
}

const int N=1e5+5;
ll d[N]; 
char s[N];

int main()
{
    scanf("%s",s+1);
    int len=strlen(s+1);
    d[0]=1;
    int flag=1;
    for(int i=1;i<=len;i++){
    	d[i]=d[i-1];
    	if(s[i]=='w'||s[i]=='m') {
    		puts("0");
    		flag=0;
    		break;
		}
    	if(s[i]=='u'||s[i]=='n'){
    		if(s[i]==s[i-1]) d[i]=(d[i-2]+d[i])%mod;
		}
	}
	if(flag)	printf("%lld\n",d[len]);
    return 0;
}

