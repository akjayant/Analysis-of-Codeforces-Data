#include<iostream>
#include<vector>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<bitset>
#include<string>
#include<queue>
#include<set>
using namespace std;
typedef long long ll;
#define mem(a,b) memset(a,b,sizeof(a))
#define rep(a,b,c) for(int a=b;a<c;a++)
#define repp(a,b,c) for(int a=b;a<=c;a++)
#define pb push_back
const int inf=0x3f3f3f3f;
const int maxn=1e5+10;
int arr[maxn];
int main()
{
	int n;
	cin>>n;
	ll sum=0;
	rep(i,0,n)
	{
		cin>>arr[i];
		sum+=arr[i];
	}
	sort(arr,arr+n);
	int len=n/2;
	ll ans=0;
	ll ans1=0;
	for(int i=0;i<len;i++)
	{
		ans+=arr[i];
	}
	ans1=sum-ans;
	cout<<ans1*ans1+ans*ans<<endl;
}
