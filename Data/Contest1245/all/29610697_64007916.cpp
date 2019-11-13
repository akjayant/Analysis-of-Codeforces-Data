#include<bits/stdc++.h>
using namespace std;
int n,m,t,s[1005],a,b,c,aa,bb,cc;
char st[1005];
int main()
{
	scanf("%d",&t);
	for(int i0=1;i0<=t;i0++)
     {
     	memset(s,0,sizeof(s));
     	aa=bb=cc=0;
     	scanf("%d%d%d%d",&n,&c,&a,&b);
        scanf("%s",st+1);
        for(int i=1;i<=n;i++)
         {
         if(st[i]=='R')aa++;
         if(st[i]=='P')bb++;
         if(st[i]=='S')cc++;
         }
        //cout<<min(a,aa)+min(b,bb)+min(c,cc)<<endl;
        if(min(a,aa)+min(b,bb)+min(c,cc)<=(n-1)/2){cout<<"NO"<<endl;continue;}
        cout<<"YES"<<endl;
        for(int i=1;i<=n;i++)
         {
         if(st[i]=='R'&&a){a--,aa--,cout<<'P';continue;}
         if(st[i]=='P'&&b){b--,bb--,cout<<'S';continue;}
         if(st[i]=='S'&&c){c--,cc--,cout<<'R';continue;}
         if(a>aa){a--,cout<<'P';continue;}
         if(b>bb){b--,cout<<'S';continue;}
		 if(c>cc){c--,cout<<'R';continue;}
         }
        cout<<endl;
     }
	return 0;
}