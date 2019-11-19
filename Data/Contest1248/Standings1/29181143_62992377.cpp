#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
char str[51100];
int N,f1[51100],f2[51100];
inline void lqx()
{
    int totl=0,totr=0;
    for(register int i=1;i<=N;++i)
	{
        if(str[i]=='(') totl++;
        else if(totl==0)totr++;
		else totl--;
        if(totl==0) f1[i]=totr;
        else f1[i]=-1;
    }
}
inline void lqx1()
{
    int totl=0,totr=0;
    for(int i=N;i>=1;--i)
	{
        if(str[i]==')') totr++;
        else if(totr==0)totl++;
		else totr--;
        if(totr==0) f2[i]=totl;
        else f2[i]=-2;
    }
}
int maxn,ans,L,R;
int main()
{
    scanf("%d",&N);
	scanf("%s",str+1);
    maxn=-1;
    for(int i=1;i<=N;++i)
	{
        for(int j=i;j<=N;++j)
		{
            swap(str[i],str[j]);
            lqx();
            lqx1();
			ans=(f1[N]==0);
            for(int k=1;k<N;++k)ans+=(f1[k]==f2[k+1]);
            if(maxn<ans)
			{
				maxn=ans;
				L=i,R=j;
			}
            swap(str[i],str[j]);
        }
    }
    printf("%d\n%d %d\n",maxn,L,R);
    return 0;
}