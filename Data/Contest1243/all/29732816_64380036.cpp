/*================= *\
|  ID : aman__guta__ |
|      LANG: C++     |
\*==================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mk make_pair
#define fs first
#define sc second 
#define mod 1000000007
#define JOKER ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
int fib[100010];
main()
{
    JOKER
    int t;
    cin>>t;
    while(t--)
    {
       int n;
       cin>>n;
       string s,t;
       cin>>s>>t;
       int a=0,b;
       char p,q,r,s1;
       for(int i=0; i<n; i++)
       {
        if(s[i]!=t[i])
        {
            a++;
        }
       }
       if(a==0)
       {
        cout<<"YES\n";
       }
       else if(a!=2)
       {
        cout<<"NO\n";
        continue;
       }
       else 
       {
        for(int i=0; i<n; i++)
        {
            if(s[i]!=t[i])
            {
                p=s[i];
                q=t[i];
                break;
            }
        }
        for(int i=n-1; i>=0; i--)
        {
            if(s[i]!=t[i])
            {
                r=s[i];
                s1=t[i];
                break;
            }
        }
        if(p==r && q==s1)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
       }
    }
    cerr<<"Time elapsed : "<<clock()*1000.0/CLOCKS_PER_SEC<<"ms"<<'\n'; 
    return 0;
}