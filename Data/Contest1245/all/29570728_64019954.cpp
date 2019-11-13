#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<string>
using namespace std;
typedef long long ll;
#define mem(a,b) memset(a,b,sizeof(a))
#define rep(a,b,c) for(int a=b;a<c;a++)
#define repp(a,b,c) for(int a=b;a<=c;a++)
#define pb push_back
const int maxn=100005;
const int mod=1e9+7;
ll dp[maxn];
vector<int>vis;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    dp[1]=1;
    dp[2]=2;
    dp[3]=3;
    for(int i=4;i<=100000;i++)
    {
    	dp[i]=(dp[i-1]+dp[i-2])%mod;
    }
    string str;
    cin>>str;
    int flag=1;
    int last=-1;
    int cnt=0;
    for(int i=0;i<str.size();i++)
    {
    	if(str[i]=='w'||str[i]=='m')
    	{
    		flag=0;
    		break;
    	}
    	if(str[i]!=last)
    	{
    		if(cnt>=2)
    		{
    			vis.pb(cnt);
    		}
    		cnt=1;
    		last=str[i];
    	}
    	else if(str[i]=='u'||str[i]=='n')cnt++;
    }
    if(cnt>=2)vis.pb(cnt);
    if(!flag)
    {
    	cout<<0<<endl;
    	return 0;
    }
    else 
    {
    	ll ans=1;
    	for(int i=0;i<vis.size();i++)
    	{
    		ans*=dp[vis[i]];
    		ans%=mod;
    	}
    	cout<<ans<<endl;
    }
    
    return 0;
}