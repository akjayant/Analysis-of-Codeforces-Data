#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=10086;
char s[N];
char t[N];
int cnt;
int wz[3];
int T;
int n;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s);
		scanf("%s",t);
		int ok=0;
		cnt=0;
		wz[1]=wz[2]=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]!=t[i])
			{
				cnt++;
				if(cnt>=3)
				{
					ok=1;
					printf("No\n");
					break;
				}
				wz[cnt]=i;
			}
		}
		if(ok)
			continue;
		if(cnt==0)
		{
			printf("Yes\n");
			continue;
		}
		if(cnt!=2)
		{
			printf("No\n");
			continue;
		}
		if(s[wz[1]]==s[wz[2]]&&t[wz[1]]==t[wz[2]])
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
}
