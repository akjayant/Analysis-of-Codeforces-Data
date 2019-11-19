#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=505;
struct node
{
	int opt,id;
} S[N];
int cnt=0,n,opt[N],used[N],num[N];
int ans=-1,x,y;
inline char get()
{
	register char ch=getchar();
	while (ch!='('&&ch!=')') ch=getchar();
	return ch;
}
int check()
{
	cnt=0;
	for(int i=1;i<=n;i++)
	{
		if (opt[i]=='(') S[++cnt].id=i,S[cnt].opt=opt[i];
		if (opt[i]==')') 
		{
			if (cnt&&S[cnt].opt=='(') 
			{
				cnt--;
				continue;
			}
			S[++cnt].id=i,S[cnt].opt=opt[i];
		}
	}
	memset(used,0,sizeof(used));
	memset(num,0,sizeof(num));
	int L=1,R=n;
	for(int i=1;i<=cnt;i++)
	{
		used[S[i].id]=1;
		if (S[i].opt==')') L=max(S[i].id,L);
		if (S[i].opt=='(') R=min(S[i].id,R);
	}
	int ret=cnt!=0;
	cnt=0;	
	for(int i=1;i<=n;i++)if (!used[i])
	{
		if (opt[i]=='(') S[++cnt].id=i,S[cnt].opt=opt[i];
		if (opt[i]==')') 
		{
			if (cnt&&S[cnt].opt=='(') 
			{
				if (--cnt==0) num[i]++;
				continue;
			}
			S[++cnt].id=i,S[cnt].opt=opt[i];
		}
	}
	for(int i=L;i<=R;i++) ret+=num[i];
	return ret;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) opt[i]=get();
	int num=0;
	for(int i=1;i<=n;i++)
		if (opt[i]=='(') num++;else num--;
	if (num)
	{
		printf("0\n1 1\n");
		return 0;
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
		{
			swap(opt[i],opt[j]);
			int sum=check();
			if (sum>ans)
			{
				ans=sum;
				x=i,y=j;
			}
			swap(opt[i],opt[j]);
		}
	printf("%d\n",ans);
	printf("%d %d\n",x,y);
	return 0;	
} 