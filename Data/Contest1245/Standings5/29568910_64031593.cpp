#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define lop(i,s,e) for(int i=s;i<=e;i++)
#define sort(v) sort(v.begin(),v.end())
#define prina(a,n) for(int i=0;i<n;i++)cout<<a[i]<<" ";cout<<endl; 
#define prin2da(a,n,m) lop(i,0,n-1){lop(j,0,m-1)cout<<a[i][j]<<" ";cout<<endl;} 
using namespace std;

int main()
{
IOS
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll t;string s;ll n,a,b,c;
    cin>>t;
    while(t--)
    {
    	
    	cin>>n>>a>>b>>c;
    	
    	cin>>s;
    	ll cnta=0,cntb=0,cntc=0;
    	for(auto x: s)
    	{
    		if(x=='R')
    			cnta++;
    		else if(x=='P')
    			cntb++;
    		else
    			cntc++;
    	}
    	vector<char > ans(s.length(),'x');
    	ll wn=min(a,cntc)+min(b,cnta)+min(c,cntb);

        if(wn>=ceil((double)n/2))
        {

        	cout<<"YES\n";
        	for(int i=0;i<s.length();i++)
    	{
    		if(s[i]=='R')
    		{
    			if(b>0)
    			{
    				b--;
    				ans[i]='P';
    			}
    		}
    		else if(s[i]=='P')
    		{
    			if(c>0)
    			{
    				c--;
    				ans[i]='S';
    			}
    		}
    		else
    		{
    			if(a>0)
    			{
    				a--;
    				ans[i]='R';
    			}
    		}
    	}
    	for(int i=0;i<s.length();i++)
    	{
        if(ans[i]=='x')
        {
    			if(b>0)
    			{
    				b--;
    				ans[i]='P';
    			}
    
    		else if(c>0)
    			{
    				c--;
    				ans[i]='S';
    			}

    			else if(a>0)
    			{
    				a--;
    				ans[i]='R';
    			}
    		}
    	}
    	for(auto x: ans)
    		cout<<x;
    	cout<<endl;
        }
        else
        	cout<<"NO\n";
    }
}