#include <bits/stdc++.h>

using namespace std;

char s1[60];
char s2[60];
int num1[30];
int ans[200][2];

int main() {
int t;
cin>>t;
while (t--)
{
   int n;
   scanf("%d",&n);
   scanf("%s",s1);
   scanf("%s",s2);
   memset(num1,0,sizeof(num1));
   for (int a=0;a<n;a++)
      num1[s1[a]-'a']++;
   for (int a=0;a<n;a++)
      num1[s2[a]-'a']++;
   int flag=0; 
   for (int a=0;a<=25;a++)
   {
      if (num1[a]%2!=0)
      {
         flag=1;
         break;
		}
	}
	if (flag)
	{
	   printf("No\n");
	   continue;
	}
	int cnt=0;
	int ret=0;
	char c;
	for (int a=0;a<n;a++)
	{
	   if (s1[a]!=s2[a])
	   {
	   	int okk=0;
	      for (int b=a+1;b<n;b++)
	         if (s2[a]==s2[b])
	         {
	            ret=b;
	            okk=1;
	            break;
				}
			if (okk)
			{
			   c=s1[a];
		      s1[a]=s2[ret];
		      s2[ret]=c;
		      ans[++cnt][0]=a;
		      ans[cnt][1]=ret;
		      continue;
			}
		   for (int b=a+1;b<n;b++)
		   {
		      if (s2[a]==s1[b])
		      {
		         ret=b;
	            break;
				}
			}
		   ans[++cnt][0]=ret;
		   ans[cnt][1]=n-1;
		   c=s1[ret];
		   s1[ret]=s2[n-1];
		   s2[n-1]=c;
		   ans[++cnt][0]=a;
		   ans[cnt][1]=n-1;
		   c=s2[n-1];
		   s2[n-1]=s1[a];
		   s1[a]=c;
		}
	}
	printf("Yes\n");
	printf("%d\n",cnt);
	for (int a=1;a<=cnt;a++)
	   printf("%d %d\n",ans[a][0]+1,ans[a][1]+1);
}
	return 0;
}