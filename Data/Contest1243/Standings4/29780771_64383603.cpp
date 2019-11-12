#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;   
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ld long double
#define dd double
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define sz(a) (ll)(a.size())
typedef long long ll;
typedef unsigned long long ull;
typedef pair <ll, ll> pll;
typedef vector<pll> vplll;
ll mod = 1e9+7;
const ld PI = 2 * acos(0.0);
const vector<ll> dx = {1, -1, 0, 0};
const vector<ll> dy = {0, 0, 1, -1};
#define round(x, y) ((x + y - 1) / y)
#define ce(x, y) ((x + y - 1) / y)
#define amax(x, y) \
    if (y > x)     \
        x = y;
#define amin(x, y) \
    if (y < x)     \
        x = y;
#define lcm(x, y) ((x) * (y) / __gcd(x, y))
#define len(x) (ll) x.length()
#define sq(x) ((x) * (x))
#define cb(x) ((x) * (x) * (x))
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a,b,c,t,n,m,k; 
    cin>>t;
    while(t--)
    {
    	cin>>n;
    	string s1,s2;
    	cin>>s1>>s2;
    	int fl = 0;
    	int fl1 = 1;
    	vplll v;
    	for(int i=0;i<n;i++)
    	{
    		fl1 = 0;
    		if(s1[i]!=s2[i])
    		{
    			for(int j=i+1;j<n;j++)
    			{
    				if(s1[i]==s1[j])
    				{
    					// cout<<j+1<<' '<<i+1<<endl;
    					v.pb(mp(j+1,i+1));
    					char ch = s2[i];
    					s2[i] = s1[j];
    					s1[j] =  ch;
    					fl1 = 1;
    					break;
    				}
    			}
    			if(fl1==0)
    			{
    				for(int j = i+1; j < n;j++)
    				{
    					if(s1[i]==s2[j])
    					{
    						v.pb(mp(i+2,j+1));
    						v.pb(mp(i+2,i+1));
    						char ch = s2[i];
    						s2[i] = s2[j];
    						s2[j] = s1[i+1];
    						s1[i+1] = ch;
    						fl1 = 1;
    						break;
    					}
    				}
    			}
    			if(fl1==0)
    			{
    				cout<<"No"<<endl;
    				fl = 1;
    				break;
    			}
    		}
    	}
    	if(fl==1||s1!=s2)
    	{
    		continue;
    	}
    	else
    	{
    		cout<<"Yes"<<endl;
    		cout<<v.size()<<endl;
    		for(auto j:v)
    		{
    			cout<<j.ff<<" "<<j.ss<<endl;
    		}
    	}
    }
    return 0;
}