#include<bits/stdc++.h>
using namespace std;
const int maxn=550;
char s[maxn];
int n,pre[maxn],suf[maxn],cnt1pre[maxn],cnt2suf[maxn];

int check()
{
	int c1=0,c2=0;
	for(int i=1;i<=n;++i){
		if(s[i]=='(')c1++;
		else c2++;
	}
	if(c1!=c2)return 0;
	memset(pre,0,sizeof(pre));
	memset(suf,0,sizeof(suf));
	memset(cnt1pre,0,sizeof(cnt1pre));
	memset(cnt2suf,0,sizeof(cnt2suf));
	int cnt2=0;
	for(int i=1;i<=n;++i){
		if(s[i]=='(')cnt2++;
		else if(s[i]==')'&&cnt2)cnt2--,pre[i]++;
		else cnt1pre[i]++;
		pre[i]+=pre[i-1];cnt1pre[i]+=cnt1pre[i-1];
	}
	int cnt1=0;
	for(int i=n;i>=1;--i){
		if(s[i]==')')cnt1++;
		else if(s[i]=='('&&cnt1)cnt1--,suf[i]++;
		else cnt2suf[i]++;
		suf[i]+=suf[i+1];cnt2suf[i]+=cnt2suf[i+1];
	}
	int cnt=0,ret=0;
	for(int i=1;i<=n;++i){
		if(pre[i]+suf[i+1]+min(cnt1pre[i],cnt2suf[i+1])==c1)cnt++;
	}
	return cnt;
}

int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	int ans=-1,pos1,pos2;
	for(int i=1;i<=n;++i)
	{
		for(int j=i;j<=n;++j)
		{
			swap(s[i],s[j]);
			int t=check();
			if(t>=ans){
				ans=t;
				pos1=i,pos2=j;
			}
			swap(s[i],s[j]);
		}
	}
	cout<<ans<<endl;
	cout<<pos1<<" "<<pos2;
} 
//10
//()()()()()
