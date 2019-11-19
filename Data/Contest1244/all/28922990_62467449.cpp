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
    int t;
    cin>>t;
    while(t--)
    {
    	int a,b,c,d,k,x,y;
    	cin>>a>>b>>c>>d>>k;
    	if(a%c!=0)
    	{
    		x=a/c+1;
    	}
    	else
    	{
    		x=a/c;
    	}
    	if(b%d!=0)
    	{
    		y=b/d+1;
    	}
    	else
    	{
    		y=b/d;
    	}
    	if(x+y>k)
    	{
    		cout<<"-1\n";
    	}
    	else
    	{
    		cout<<x<<" "<<y<<"\n";
    	}
    }
    return 0;
}