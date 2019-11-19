#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define v vector<ll> 
#define vv vector<v>
#define p pair<ll,ll>
#define vc vector<char>
#define fi first
#define se second
// qwertyiopwo
//for (int i=1; i<=n; i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while (t--)
    {
    	int n;
    	cin>>n;
    	string s;
    	cin>>s;
    	int first=-1;
    	int last=-1;
    	for (int i=0; i<n; i++)
    	{
    		if (s[i]=='1')
    		{
    			if (first==-1)
    				first=i;
    			last=i;
    		}
    	}
 		if (first==-1)
		{
			cout<<n<<endl;
		}
		else
		{
			ll ans=max(2*last+2, 2*(n-first));
			cout<<ans<<endl;
		}

    }
	return 0;
}