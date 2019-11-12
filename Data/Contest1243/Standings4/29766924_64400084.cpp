#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<stack>
#include<map>
#include<deque>
#include<set>
#define inf 1e9
#define eps 1e-6
#define N 1010
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline ll read()
{
	char ch=getchar();
	ll s=0,w=1;
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return s*w;
}
int num[31];
int n,Q,len;
char s[N],t[N],S[N],T[N];
int L[N],R[N],pos[N]; 
int main()
{
	Q=read();
	while(Q--)
	{
		n=read();
		scanf("%s%s",s+1,t+1);memset(num,0,sizeof(num));
		len=0;
		for(register int i=1;i<=n;i++)if(s[i]!=t[i])S[++len]=s[i],T[len]=t[i],pos[len]=i;
		for(register int i=1;i<=len;i++)num[S[i]-'a'+1]++,num[T[i]-'a'+1]++;
		int flag=0,answer=0;
		for(register int i=1;i<=26;i++)
		{
			if(num[i]&1)
			{
				flag=1;break;
			}
		}
		if(flag){printf("No\n");continue;}
		for(register int i=1;i<=len;i++)
		{
			int FL=0;if(S[i]==T[i])continue;
			for(register int j=i+1;j<=len;j++)
			{
				if(T[i]==T[j])
				{
					FL=1;
					L[++answer]=pos[i],R[answer]=pos[j];
					swap(S[i],T[j]);
				}
				if(FL)break;
				if(T[i]==S[j])
				{
					FL=1;
					L[++answer]=pos[j],R[answer]=pos[j];
					swap(S[j],T[j]);
					L[++answer]=pos[i],R[answer]=pos[j];
					swap(S[i],T[j]);
				}
			}
		}
		printf("Yes\n");printf("%d\n",answer);
		for(register int i=1;i<=answer;i++)printf("%d %d\n",L[i],R[i]);
	}
	return 0;
}
/*
1
2
ab
ba
*/
