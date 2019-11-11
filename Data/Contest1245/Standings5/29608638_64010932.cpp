//#pragma GCC optimize("Ofast")
#include <set>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <bitset>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define zy 2333333
#define bql 2147483647
using namespace std;
int t,n,a,b,c,sum,ck[105];
char s[105];
int main()
{
    cin>>t;
    while (t--)
    {
        sum=0;
        memset(ck,0,sizeof(ck));
        cin>>n>>a>>b>>c;
		scanf("%s",s+1);
        for (int i=1;i<=n;i++)
        {
            if (s[i]=='R')
            {
                if (b)
                {
                    b--,sum++;
                    ck[i]=1;
                }
            }
            else if (s[i]=='P')
            {
                if (c)
                {
                    c--,sum++;
                    ck[i]=1;
                }
            }
            else
            {
                if (a)
                {
                    a--,sum++;
                    ck[i]=1;
                }
            }
        }
        if (sum*2>=n)
        {
            cout<<"YES\n";
            for (int i=1;i<=n;++i)
            {
                if (ck[i])
                {
                    if (s[i]=='R')
                        cout<<'P';
                    else if (s[i]=='P')
                        cout<<'S';
                    else
                        cout<<'R';
                }
                else
                {
                    if (a)
                        cout<<'R',a--;
                    else if (b)
                        cout<<'P',b--;
                    else
                        cout<<'S';
                }
            }
            cout<<endl;
        }
        else
            cout<<"NO\n";
    }
	return 0;
}