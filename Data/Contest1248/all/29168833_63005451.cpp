#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long lint;
const int N=600;
int n;
int l[N],r[N],la,ra;
int a[N],s[N],pmi[N],smi[N];
char str[N];
int ans[3];
void work(int sl,int sr)
{
	pmi[0]=smi[n+1]=114514;
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i],pmi[i]=min(pmi[i-1],s[i]);
	for(int i=n;i;i--) smi[i]=min(smi[i+1],s[i]);
	int ret=0;
	if(pmi[n]>=0) ret++;
	for(int i=1;i<n;i++) if(pmi[i]+s[n]-s[i]>=0&&smi[i+1]-s[i]>=0) ret++;
	if(ret>ans[0]) ans[0]=ret,ans[1]=sl,ans[2]=sr;
}
int main()
{
	ans[0]=-1;
	scanf("%d%s",&n,str+1);
	for(int i=1;i<=n;i++)
	{
		if(str[i]=='(') a[i]=1,l[++la]=i;
		else a[i]=-1,r[++ra]=i;
	}
	if(la!=ra){puts("0");puts("1 1");return 0;}
	for(int li=1;li<=la;li++)
	{
		for(int ri=1;ri<=ra;ri++)
		{
				a[r[ri]]=1,a[l[li]]=-1;
				work(l[li],r[ri]);
				a[r[ri]]=-1,a[l[li]]=1;
		}
	}
	work(l[1],l[1]);
	printf("%d\n%d %d\n",ans[0],ans[1],ans[2]);
	return 0;
}
