#include<bits/stdc++.h>
using namespace std;
const int N=5100;
typedef long long ll;
const ll MOD=1e9+7LL;
string s,t;
set<int> ch[2][30];
int id[2][N];
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int q,n;
    cin>>q;
    while(q--)
    {
    	cin>>n;
    	cin>>s>>t;
    	vector<pair<int,int>> rs;
    			bool mov=false;
    	for (int i = 0; i < s.size(); ++i)
    	{
    		if(s[i]!=t[i])
    		{
    			mov=false;
    			for (int j = i+1; j < s.size(); ++j)
    			{
    				if(s[i]==s[j])
    				{
    					mov=true;
    					rs.push_back({j,i});
    					swap(s[j],t[i]);
    					break;
    				}
    			}
    			for (int j = i+1; j < t.size(); ++j)
    			{
    				if(s[i]==t[j] && mov==false)
    				{
    					mov=true;
    					rs.push_back({i,i});
    					rs.push_back({i,j});
    					swap(s[i],t[i]);
    					swap(s[i],t[j]);
    					break;
    				}
    			}
    			if(mov==false)
    				goto ed;
    		}
    	}
    	ed:;
    	// cout<<s<<" "<<t<<"\n";
    	if(mov==false )
    	{
    		cout<<"NO\n";
    	}else
    	{
    		cout<<"YES\n";
    		cout<<rs.size()<<"\n";	
    		for(auto it:rs)
    		{
    			cout<<it.first+1<<" "<<it.second+1<<"\n";
    		}
    	}

    }
    return 0;   
}