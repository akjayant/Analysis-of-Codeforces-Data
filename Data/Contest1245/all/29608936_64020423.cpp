/*            ,%%%%%%%%%%%,
             ,%%/\%%%%%%/\%%
            ,%%%\c  """  J/%%
            %%%%/  O   O \%%%
 %.         %%%%         |%%%
 ~%%.        `%%%%(__Y__)%%'
  ~%%         ;%%%%`\_/%%%'
          /   '%%%%%%%'
  <<      ,            |
   \\    .       \     |
    \\  /        /   | |
     \\/        /    | |
      \          __  | |___
           ((           ))))))
*/
#include"bits/stdc++.h"
//next_permutation(str,str+n) 
//getline(cin,s) 
#include"iostream"
#include"string"
#include"cstring"
#include"algorithm"
#include"cmath"
#include"map"
#include"queue"
#include"vector"
#include"cstdio"
#include"cstdlib"
#include"set"
#include"sstream"
#include"stack"
#define f(i,a,b) for(int i=a;i<=b;i++)
#define fill(a,b) memset(a,b,sizeof(a))
#define PI acos(-1)
#define INF 0x3f3f3f3f
#define _mod (ll)(1e9+7)
#define gc() getchar()
#define lowbit(x) (x&(-x))
//#define sd(n) scanf("%d",&n)
//#define sd(n,m) scanf("%d%d",&n,&m)
typedef long long ll ;
typedef unsigned long long ull;
using namespace std;
inline int read(){
    int res=0,f=0;char c;c=gc();
    while(!isdigit(c)){if(c=='-')f=1;c=gc();}
    while(isdigit(c)){res=res*10+c-48;c=gc();}
    if(f)return -res;return res;
}
const int maxn=1e5+5;
string s;
ll str[maxn]={1,1,2,3};
ll solve(){
	ll ans=1LL;
	int len=s.length();
	for(int i=0;i<len;i++) if(s[i]=='w'||s[i]=='m') return 0;
	ll a=0,b=0;
	for(int i=0;i<len;i++){
		if(s[i]=='n') a++;
		else {
			ans=ans*str[a]%_mod;
			a=0;
		}
		
		if(s[i]=='u') b++;
		else {
			ans=ans*str[b]%_mod;
			b=0;
		}
		
	}
	ans=ans*str[a]%_mod*str[b]%_mod;
	return ans;
}
int main(){
	for(int i=4;i<=100000;i++) str[i]=(str[i-1]+str[i-2])%_mod;
	cin>>s;
	printf("%I64d\n",solve());
    return 0;
}










