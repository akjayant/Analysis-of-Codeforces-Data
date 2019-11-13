#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
typedef long long       ll;
#define pb                emplace_back
#define mp                make_pair
#define all(a)            (a).begin(), (a).end()
#define clr(a,h)          memset(a, (h), sizeof(a))
#define F first
#define S second
#define fore(i, b, e)     for (ll i = b; i < e; i++)
#define forr(i, b, e)     for (int i = b; i < e; i++)
ll faster_in(){ll r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -faster_in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
 
using namespace std;
//using namespace __gnu_pbds;

int main()
{
    std::ios::sync_with_stdio(false); cin.tie(0);
    int casos;
    cin>>casos;
    while(casos--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int maxx=0;
        forr(i,0,101)
        {
            forr(j,0,101)
            {
                if (i<=a && 2*i+j<=b && 2*j<=c)
                {
                    maxx=max(maxx,i+2*i+j+2*j);
                }
            }
        }
        cout<<maxx<<endl;
    }    
}
// PLUS ULTRA!