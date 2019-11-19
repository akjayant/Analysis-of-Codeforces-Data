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
    	int n;
    	cin>>n;
    	string s;
    	cin>>s;
    	int m=0,flag=0;
    	for(int i=0;i<n;i++)
    	{
    		if(s[i]=='1')
    		{
    			flag=1;
    			int y=max(i+1,n-i);
    			m=max(m,y);
    		}
    	}
    	if(flag==0)
    	{
    		cout<<n<<"\n";
    	}
    	else
    	{
    		cout<<2*m<<"\n";
    	}
    }
    return 0;
}