#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;
const ll P=1e9+7;
char s[100010];
ll mul[100010],cnt=0,arr[100010];
int main()
{
	s[0]=0;
	scanf("%s",s+1);
	ll len=strlen(s+1);
	arr[2]=2;arr[3]=3;
	for(ll i=4;i<=100000;i++)
		arr[i]=(arr[i-1]+arr[i-2])%P;
	ll ans=1;bool win=true;
	for(int i=1;i<=len;i++)
		if(s[i]=='m'||s[i]=='w'){win=false;break;}
	if(win)
	{
		for(ll i=1;i<=len;i++)
		{
			ll num=1;
			while(s[i]=='u'&&s[i-1]=='u'&&i<=len){num++;i++;}
			while(s[i]=='n'&&s[i-1]=='n'&&i<=len){num++;i++;}
			if(num>1) ans=ans*arr[num]%P;
		}
		printf("%lld\n",ans);
	}
	else printf("0\n");
}