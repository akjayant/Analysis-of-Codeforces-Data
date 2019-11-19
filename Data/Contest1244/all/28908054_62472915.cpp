#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
#define nn 100002
using namespace std;

int n;
LL k;
int a[nn];

int main()
{
	scanf("%d%lld\n",&n,&k);
	for(int i=1;i<=n;++i) scanf("%d",a+i);
	sort(a+1,a+n+1);
	int dl=a[1],dr=a[n];
	int l=1,r=n;
	int sl=0,sr=0;
	if(dl==dr) {printf("0"); return 0; }
	while(k&&dl<dr)
	{
		while(l<=n&&dl==a[l]) l++,sl++;
		while(r>=1&&a[r]==dr) r--,sr++;
		if(sl<=sr)
		{
			if(1LL*(a[l]-dl)*sl<=k) k-=1LL*(a[l]-dl)*sl,dl=a[l];
			else {dl+=k/sl,k=0; break; }
		}
		else
		{
			if(1LL*(dr-a[r])*sr<=k) k-=1LL*(dr-a[r])*sr,dr=a[r];
			else {dr-=k/sr,k=0; break; }
		}
	}
	printf("%d",dr-dl);
	
	return 0;
}
