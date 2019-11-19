#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
    	ll n;
    	cin>>n;
    	string s;
    	cin>>s;
    	int f1 = -1;
    	for(int i=0;i<n;i++)
    	{
    		if(s[i]=='1')
    		{
    			f1 = i;
    			break;
    		}
    	}
    	int l1 = -1;
    	for(int i=n-1;i>=0;i--)
    	{
    		if(s[i]=='1')
    		{
    			l1 = (n-1-i);
    			break;
    		}
    	}
    	if(f1 == -1)
    		cout<<n<<endl;
    	else
    		cout<<2*n-2*min(l1,f1)<<endl;
    }
	return 0;
}