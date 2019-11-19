#include <bits/stdc++.h>
using namespace std;
#define int long long int
#undef int
int main()
{
	#define int long long int
    ios_base::sync_with_stdio(false);//this works only
    cin.tie(NULL);// when first all inputs are from user
    cout.tie(NULL);//you will see all outputs afterwards
    int n,k;
    cin>>n>>k;
    int a[200000];
    for(int i=0;i<n;i++)
    {
    	cin>>a[i];
    }
    sort(a,a+n);
    int ans;
    for(int i=0;i<(n/2);i++)
    {
    	int x=(a[i+1]-a[i])*(i+1);
    	int y=(a[n-i-1]-a[n-i-2])*(i+1),op;
    	if(i+1!=n-i-1)
    	{
    		op=(x+y);
    	}
    	else
    	{
    		op=x;
    	}
    	//cout<<op<<" "<<k;
    	if(k>=op)
    	{
    		k=k-op;
    	}
    	else
    	{
    		k=k/(i+1);
    		ans=a[n-i-1]-a[i]-k;
    		break;
    	}
    }
  //  int ans=a[n-1]-a[0];
    cout<<ans;
    return 0;
}