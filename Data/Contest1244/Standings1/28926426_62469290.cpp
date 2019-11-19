#include<bits/stdc++.h>
using namespace std;
int T,a,b,c,d,k,n,t;
int i;
char s[12345];

int main()
{
  scanf("%d",&T);
  while(T--)
    {
	  scanf("%d",&n);
	  scanf("%s",s+1),t=0;
	  for(i=1;i<=n;i++)
	    {
		  if(s[i]-'0') t=max(t,max(i,n-i+1));
		}
	  if(!t) printf("%d\n",n);
	  else printf("%d\n",t*2);
	}
} 