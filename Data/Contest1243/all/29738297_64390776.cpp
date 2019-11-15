#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define f(i,a,b) for(int i=a; i<b; i++)
#define pb push_back
#define vi vector<int>
#define vl vector<long long>
#define vii vector<vector<int>>
#define vll vector<vector<long long>>
using namespace std;

int main()
{
    IOS
    int t;
    cin>>t;
    while(t--)
    {
        int n, flag = 0, x[26] = {};
        string s, t;
        char c;
        vi v, w;
        cin>>n>>s>>t;
        f(i, 0, n)
        {
        	x[s[i] - 'a']++;
        	x[t[i] - 'a']++;
        }
        f(i, 0, 26) if(x[i]%2 == 1) flag++;
        if(flag) cout<<"No\n";
        else
        {
        	f(i, 0, n)
        	{
        		if(s[i] != t[i])
        		{
        			int f1 = 0;
        			c = s[i];
        			f(j, i+1, n) if(s[j] == c) { swap(s[j], t[i]); v.pb(j); w.pb(i); f1++; break; }
        			if(f1 == 0)
        			{ 
        				f(j, i+1, n)
        				{
        					if(t[j] == c){ swap(t[j], s[j]); v.pb(j); w.pb(j); swap(s[j], t[i]); v.pb(j); w.pb(i); f1++; break; }
        				}
        			}
        		}
        	}
	        cout<<"Yes\n"<<v.size()<<endl;
	        f(i, 0, v.size()) cout<<v[i]+1<<' '<<w[i]+1<<endl;
        }
    }
    return 0;
}