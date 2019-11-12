#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
typedef long long ll;
using namespace std;
const int mx=110;

int k,n,tot;
char s1[mx],s2[mx];
int f[mx];
struct node{
	int a,b;
}s[mx];

int main(){
	scanf("%d",&k);
	while(k--){
		tot=0;
		memset(f,0,sizeof(f));
		scanf("%d",&n);
		scanf("%s",s1+1);
		scanf("%s",s2+1);
		for(int i=1;i<=n;i++)
		{
		   if(s1[i]!=s2[i])
		   {
		      f[s1[i]-'a']++;
		      f[s2[i]-'a']++;
		   }
	    }
	    int flag=0;
	    for(int i=0;i<26;i++)
	    {
	    	if(f[i]%2!=0)
	    	{
	    		flag=1;
	    		break;
	    	}
	    }
	    if(flag)
	    {
		  printf("No\n");
		  continue;
	    }
	    printf("Yes\n");
	    for(int i=0;i<26;i++)
	    {
	    	if(f[i])
	    	{
	    	   int ans1=0,ans2=0;
	    	   for(int j=1;j<=n;j++)
	    	   {
	    	   	   if(s1[j]!=s2[j])
	    	   	   {
	    	   	      if(s1[j]-'a'==i)
	    	   	      {
	    	   	   	    if(ans1==0)
	    	   	   	     ans1=j;
	    	   	   	     else
	    	   	   	  {
	    	   	   	    s[++tot].a=j;
	    	   	   	    s[tot].b=ans1;
	                    s1[j]=s2[ans1];
	                    s2[ans1]=s1[ans1];
	                    if(s1[j]==s2[j])
	                    f[s1[j]-'a']-=2;
	    	   	   	    ans1=0;
	    	   	   	    f[i]-=2;
	    	   	      }
	    	   	     }
	    	   	     if(s2[j]-'a'==i)
	    	   	     {
	    	   	   	  if(ans2==0)
	    	   	   	   ans2=j;
	    	   	   	   else
	    	   	   	  {
	    	   	   	   s[++tot].a=ans2;
	    	   	   	   s[tot].b=j;
	    	   	   	   s2[j]=s1[ans2];
	    	   	   	   s1[ans2]=s2[ans2];
	    	   	   	   if(s2[j]==s1[j])
	    	   	   	   f[s2[j]-'a']-=2;
	    	   	   	   ans2=0;
	    	   	   	   f[i]-=2;
	    	   	     }
	    	   	   }
	    	      }
	    	   }
	    	   if(f[i]!=0)
	    	   {
	    	   	  s[++tot].a=ans1;
	    	   	  s[tot].b=ans1;
	    	   	  s[++tot].a=ans2;
	    	   	  s[tot].b=ans1;
	    	   	  s1[ans1]=s2[ans1];
	    	   	  s2[ans1]=s1[ans2];
	    	   	  s1[ans2]=s2[ans2];
	    	   	  if(s1[ans1]==s2[ans1])
	    	   	  f[s1[ans1]-'a']-=2;
	    	   	  f[i]-=2;
	    	   }
	        }
	    }
	    printf("%d\n",tot);
	    for(int i=1;i<=tot;i++)
	    printf("%d %d\n",s[i].a,s[i].b);
	}
	return 0;
}
	    
	    	
	    
	