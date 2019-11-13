#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define fr(i,n) for(i=0;i<n;i++)
#define F first
#define S second
#define endl "\n"
#define fast std::ios_base::sync_with_stdio(false)
#define mod 1000000007
#define pi 3.14159265
void shikhar7s(int cas)
{
    int n,i;
    cin>>n;
    string s,t;
    cin>>s>>t;
    vector<int> v;
    int c=0;
    fr(i,n)
    {
    	if(s[i]==t[i])
    		c++;
    	else
    		v.pb(i);
    }
    if(c!=n-2&&c!=n)
    	cout<<"NO"<<endl;
    else if(c==n-2)
    {
    	if(s[v[0]]==s[v[1]]&&t[v[0]]==t[v[1]])
    		cout<<"YES"<<endl;
    	else
    		cout<<"NO"<<endl;
    }
    else
    	cout<<"YES"<<endl;
}
signed main()
{
    fast;
    int t=1;
    cin>>t;
    int cas=1;
    while(cas<=t)
    {
	shikhar7s(cas);
	cas++;
    }
    return 0;
}