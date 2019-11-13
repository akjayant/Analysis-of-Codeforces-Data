#include<bits/stdc++.h>
using namespace std;

#define db double
#define MAXN 200005
#define mo 1000000007
#define int long long

inline int read()
{
    register int x = 0 , ch = getchar();
    while( !isdigit( ch ) ) ch = getchar();
    while( isdigit( ch ) ) x = x * 10 + ch - '0' , ch = getchar();
    return x;
}

int n,m;
char s[MAXN];
int f[MAXN];

void rd()
{
	scanf("%s",s+1);
	n = strlen(s+1);
}

int w = 0,p = 0;
int ans = 1;

signed main()
{
	rd();
	f[0] = f[1] = 1;
	for(int i = 2; i <= n; i ++)
		f[i] = (f[i-1]+f[i-2])%mo;
	for(int i = 1; i <= n; i ++) {
		if(i == 1 || s[i] != s[i-1]) {
			ans = ans*f[w]%mo;
			w = 0; 
		}
		if(s[i] == 'n') {
			w ++;
		} else {
			if(s[i] == 'u')  {
				w ++;
			} else {
				ans = ans*f[w]%mo;
				w = 0;
 			}
		 }
		 if(s[i] == 'w' || s[i] == 'm') {
		 	cout<<0;
		 	return 0;
		 }
	}
//	cout<<w<<"\n";
	ans = ans*f[w]%mo;
	cout<<ans;
	return 0;
}
/*
ouuokarinn

nnuuuu


*/