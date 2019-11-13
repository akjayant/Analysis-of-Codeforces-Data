#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int maxn = 1e4 + 5 ;
int n ;
char s[maxn] ;
char t[maxn] ;
int main()
{
	int k ;
	scanf("%d" , &k) ;
	while(k --)
	{
		scanf("%d" , &n) ;
		scanf("%s" , s) ;
		scanf("%s" , t) ;
		int f1 = -1 , f2 = -1 , f3 = -1 ;
		for(int i = 0 ; i < n ; i ++)
		{
			if(s[i] == t[i])
			  continue ;
			else if(f1 == -1)
			  f1 = i ;
			else if(f2 == -1)
			  f2 = i ;
			else
			  f3 = i ;
		}
		if(f3 != -1 || f1 != -1 && f2 == -1)
		  printf("NO\n") ;
		else if(f1 == -1)
		  printf("YES\n") ;
		else
		{
			if(s[f1] == s[f2] && t[f1] == t[f2])
			  printf("YES\n") ;
			else
			  printf("NO\n") ;
		}
	}
}