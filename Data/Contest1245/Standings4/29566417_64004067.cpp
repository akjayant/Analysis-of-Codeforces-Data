#include<bits/stdc++.h>
using namespace std ;
typedef unsigned long long ll ;
const int maxn = 105 ;
const int M = 149993 ;
char s[maxn] ;
char ans[maxn] ;
bool vis[maxn] ;
int main()
{
	int t ;
	int n ;
	int a , b , c ;
	scanf("%d" , &t) ;
	while(t --)
	{
	  scanf("%d" , &n) ;
	  scanf("%d%d%d" , &a , &b , &c) ;
	  scanf("%s" , s) ;
	  int cnt = 0 ;
	  memset(vis , 0 , sizeof(vis)) ;
	  for(int i = 0 ; i < n ; i ++)
	  {
	  	  if(s[i] == 'S' && a > 0)
	  	  {
	  	     ans[i] = 'R' ;
			 a -- ;	
			 vis[i] = 1 ;
			 cnt ++ ;
	      }
	      if(s[i] == 'R' && b > 0)
	      {
	      	 ans[i] = 'P' ;
	      	 b -- ;
	      	 vis[i] = 1 ;
	      	 cnt ++ ;
		  }
		  if(s[i] == 'P' && c > 0)
		  {
		  	 ans[i] = 'S' ;
		  	 c -- ;
		  	 vis[i] = 1 ;
		  	 cnt ++ ;
		  }
	  }
	  if(cnt < (n + 1) / 2)
	  {
	  	printf("NO\n") ;
	  	continue ;
	  }
	  printf("YES\n") ;
	  for(int i = 0 ; i < n ; i ++)
	  {
	     if(vis[i])
		   printf("%c" , ans[i]) ;
		 else
		 {
		 	if(a > 0)
		 	{
		 	   ans[i] = 'R' ;
			   a -- ;	
			}
		    else if(b > 0)
		    {
		       ans[i] = 'P' ;
			   b -- ;	
			}		      
		    else
		    {
		       ans[i] = 'S' ;
			   c -- ;	
			}
		 	printf("%c" , ans[i]) ;
		 }	
	  }
	  printf("\n") ;
	} 
}