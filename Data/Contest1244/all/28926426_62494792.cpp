#include<bits/stdc++.h>
using namespace std;
int n,k,a[890890];
char s[890890];

void chg(int c,int k)
{
  if(k)
    {
    	if(s[c]=='W') s[c]='B';
    	else s[c]='W';
	}
}

int main()
{
  int pd,i,j,t;
  scanf("%d%d",&n,&k);
  scanf("%s",s+1),pd=0;
  for(i=1;i<=n;i++) 
   {
    s[n+i]=s[i];
    if(s[n+i]==s[n+i-1]) pd=1;
   }
   s[0]=s[n],s[2*n+1]=s[1];
   if(!pd)
     {
       k&=1;
       for(i=1;i<=n;i++) printf("%c",s[n+i-k]);
	   return 0;
	 }
   for(i=1;i<=n*2;i++)
     {
	   if(s[i]!=s[i-1] && s[i]!=s[i+1]) a[i]=1;
	 }
   for(i=2;i<=n+1;i++)
     {
	   if(a[i] && !a[i-1])
	     {
	       t=i;
		   while(a[i]) i++;
		   i--;
		   for(j=t;j<=i;j++)
		     {
			   if(j-t<i-j)
			     {
				   if(j-t+1<=k) s[(j-1)%n+1]=s[t-1];
				   else  chg((j-1)%n+1,k&1); 
				 } 
			   else
			     {
				   if(i-j+1<=k) s[(j-1)%n+1]=s[i+1];
				   else chg((j-1)%n+1,k&1); 
				 }
			 }
		 }
	 }
	 for(i=1;i<=n;i++) printf("%c",s[i]);
} 