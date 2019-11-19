#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
#define MOD 1000000007
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fll
typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
int n;
char s[550],cur[550];
int presum[550];
inline int getans()
{
	presum[0]=0;
	int pos=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='(')presum[i]++;
		else presum[i]--;
		if(s[i]==')'&&presum[i]<0)pos=i+1,presum[i+1]=0;
		else presum[i+1]=presum[i];
	}
	for(int i=0;i<n;i++)
		cur[i]=s[(pos+i)%n];
//	cout<<s<<endl;
//	cout<<pos<<endl;
//	cout<<cur<<endl;
	presum[0]=0;
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(cur[i]=='(')presum[i]++;
		else presum[i]--;
		presum[i+1]=presum[i];
		if(!presum[i])cnt++;
	}
//	cout<<cnt<<endl;
//	system("pause");
	return cnt;
}
int main()
{
	scanf("%d",&n);
	scanf("%s",s);
	int c=0;
	for(int i=0;i<n;i++)
		if(s[i]=='(')c++;
		else c--;
	if(c)
	{
		printf("0\n1 1\n");
		return 0;
	}
	int ans=getans(),ai=1,aj=1;
//	cout<<ans<<endl;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
		{
			if(s[i]==s[j])continue;
			swap(s[i],s[j]);
			int res=getans();
			if(res>ans)
			{
				ans=res;
				ai=i;
				aj=j;
			}
			swap(s[i],s[j]);
		}
	printf("%d\n%d %d\n",ans,ai+1,aj+1);
	return 0;
}
