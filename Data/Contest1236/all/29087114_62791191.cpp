#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mod 1000000007
#define lli long long int
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define ve vector<lli>
#define vep vector<pair<lli,lli> >
#define fr(i,n) for(lli i=0;i<(n);i++)
#define F first
#define S second
long long int gcd(long long int a,long long int b)
{
	if(a==0)return b;
	return gcd(b%a,a);
}
int bin(long int a[],long int low,long int high,long d,long day[])
{
	//cout<<low<<" "<<high<<" "<<d<<"\n";
	if(low>high)return -1;
	long mid=(low+high)/2;
	if(a[mid]>(a[low]+d)&&(a[mid-1]<=(a[low]+d)||day[mid-1])&&day[mid]==0)
		return mid;
	else if(a[mid]>(a[low]+d)&&day[mid]==0)
		return bin(a,low,mid-1,d,day);
	else
		return bin(a,mid+1,high,d-a[mid+1]+a[low],day);
}
long long power(long long a,long long b)
{
	//cout<<a<<" "<<b<<"\n";
	if(b==0)return 1;
	if(b%2==0)return (power((a*a)%mod,b/2))%mod;
	return ((a%mod)*(power((a*a)%mod,b/2))%mod)%mod;
}
/*int subtree(vector<int>v,int sub[],i,j)
{
	if(sub[i]>0)return sub[i];
	for(auto x:v[i])
	{
		if(x!=j)sub[i]+=subtree(v,sub,x,i);
	}
	return sub[i];
}*/
int main()
{	
	/*ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);*/
	int t=1;
	//cin>>t;
	while(t--)
	{
		lli n,m,a;
		cin>>n>>m;
		a=power(2,m);
		cout<<power(a-1,n)<<"\n";
	}
	return 0;
}
