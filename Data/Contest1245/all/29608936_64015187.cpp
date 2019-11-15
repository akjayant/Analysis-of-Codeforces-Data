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
const int maxn=1e6+5;
int _gcd(int a,int b){
	if(!b) return a;
	else return _gcd(b,a%b);
}
string s;
int main(){
	int T=read();
	while(T--){
		int n=read();
		int a=read(),b=read(),c=read(); //r p s
		int x=0,y=0,z=0;
		cin>>s; 
		for(int i=0;i<n;i++){
			if(s[i]=='S') x++;
			else if(s[i]=='P') z++;
			else y++;
		}
		int num=min(x,a)+min(y,b)+min(z,c);
		if(num>(n-1)/2)  {
			printf("YES\n");
			for(int i=0;i<n;i++){
				if(s[i]=='S'&&a) printf("R"),a--,x--;
				else if(s[i]=='R'&&b) printf("P"),b--,y--;
				else if(s[i]=='P'&&c) printf("S"),c--,z--;
				else {
					if(b>y) printf("P"),b--;
					else if(a>x) printf("R"),a--;
					else if(c>z) printf("S"),c--;
					if(s[i]=='R') y--;
					if(s[i]=='S') x--;
					if(s[i]=='P') z--;
				}
			}
			printf("\n");
		}
		else printf("NO\n");
	}
	
    return 0;
}










