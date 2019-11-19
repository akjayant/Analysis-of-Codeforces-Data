#include<cstdio>
#include<cstring>
#include<algorithm>
#define nn 600002
using namespace std;

int n,k,m,dep;
char s[nn];
int c[nn],las[nn],fir[nn],b[nn],ans[nn],sta[nn];

int main()
{
	scanf("%d%d\n",&n,&k);
	scanf("%s",s);
	m=3*n;
	for(int i=n;i<2*n;++i) s[i]=s[i-n];
	for(int i=2*n;i<m;++i) s[i]=s[i-n];
	s[m]='\0';
	int cnt=0;
	for(int i=0;i<m;++i)
	{
		if(i&&s[i]==s[i-1]) c[cnt]++,las[cnt]=i;
		else c[++cnt]=1,b[cnt]=(s[i]=='B'?1:0),fir[cnt]=las[cnt]=i;
	}
	for(int i=1;i<=cnt;++i)
	{
		if(c[i]>=2)
		{
			sta[++dep]=i;
			if(fir[i]>=n) break;
		}
	}
	int x,y,bx,by;
	if(dep==0)
	{
		if(k&1) for(int i=0;i<n;++i) printf("%c",s[i]=='B'?'W':'B');
		else for(int i=0;i<n;++i) printf("%c",s[i]);
		return 0;
	}
	for(int i=1;i<dep;++i)
	{
		x=sta[i],y=sta[i+1];
		bx=b[x],by=b[y];
		int t=1;
		int l=las[x]+1,r=fir[y]-1;
		while(l<=r)
		{
			if(k>=t)
			{
				ans[l>=n?l-n:l]=bx;
				ans[r>=n?r-n:r]=by;
			}
			else
			{
				ans[l>=n?l-n:l]=(k&1)^(t&1?bx^1:bx);
				ans[r>=n?r-n:r]=(k&1)^(t&1?by^1:by);
			}
			t++; l++,r--;
		}
		for(int j=fir[x];j<=las[x];++j) ans[j>=n?j-n:j]=bx;
		for(int j=fir[y];j<=las[y];++j) ans[j>=n?j-n:j]=by;
	}
	for(int i=0;i<n;++i) printf("%c",ans[i]?'B':'W');
	
	return 0;
}
