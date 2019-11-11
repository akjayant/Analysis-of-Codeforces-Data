#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define mod 1000000007
#define int long long
#define ll long long
#define EPS 0.00000000000001
#define ld long double
#define inf 1000000002
#define N 500000

int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}

int32_t main()
{
	IOS;
	#ifndef ONLINE_JUDGE
    freopen("int.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n,a,b,c;
   		cin >> n >> a >> b >> c;
   		string st;
   		cin >> st;
   		vector<char> ans(n,'.');
   		int w = 0;
   		for(int i = 0;i < n;i++)
   		{
   			if(st[i] == 'R')
   			{
   				if(b)
   				{
   					b--;ans[i] = 'P';w++;
   				}
   			}
   			if(st[i] == 'P')
   			{
   				if(c)
   				{
   					c--;ans[i] = 'S';w++;
   				}
   			}
   			if(st[i] == 'S')
   			{
   				if(a)
   				{
   					a--;
   					ans[i] = 'R';w++;
   				}
   				
   			}
   		}
   		for(int i = 0;i < n;i++)
   		{
   			if(ans[i] == '.')
   			{
   				if(a)
   				{
   					ans[i] = 'R';
   					a--;
   				}
   				else
   					if(b)
   					{
   						ans[i] = 'P';
   						b--;
   					}
   					else
   						if(c)
   						{
   							ans[i] = 'S';
   							c--;
   						}
   			}
   		}
   		if(w >= (n + 1) / 2)
   		{
   			cout << "YES" << endl;
   			for(int i = 0;i < n;i++)
   				cout << ans[i];
   			cout << endl;
   		}
   		else
   			cout << "NO" << endl;
   	}

	return 0;
}