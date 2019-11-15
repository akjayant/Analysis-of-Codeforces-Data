/*
Nahid Hossain
Jahangirnagar University
Roll:54
*/
#include<bits/stdc++.h>
#define ll          long long int
#define db          double
#define pf          printf
#define sf          scanf
#define ff          first
#define ss          second
#define clr         clear()
#define sz          size()
#define pb          push_back
#define mk          make_pair
#define pi          acos(-1)
#define inf         100000000000000000
#define mod         100000007
#define ull         unsigned long long int
#define f(i,k,n)    for(ll i=k;i<n;i++)
#define fr(i,n,k)   for(i=n;i>=k;i--)
#define ent(a)      scanf("%lld",&a)
#define ent2(a,b)   scanf("%lld%lld",&a,&b)
#define ent3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define mem(a)      memset(a,0,sizeof(a))
#define vec(v,s)    vector<ll>v[s]
#define arr(a,s)    ll a[s];
#define bitone(x)   __builtin_popcount(x)
//#define check(n,pos) (n&(1<<pos))
//#define set(n,pos)  (n|(1<<pos))
//knight and king//

//for(i=x;i>0;i=(i-1)&x)
int dr[]= {2, 2, -2, -2, 1, -1, 1, -1};
int dc[]= {1,-1,  1, -1, 2,  2,-2, -2};
int dr1[]= {0, 0, 0, 1, 1, 1, -1, -1, -1};
int dc1[]= {-1,0, 1,-1, 0, 1, -1, 0,   1};
int dr2[]= {0, 0, 1, -1};
int dc2[]= {1,-1, 0,  0};
////////////////////////////
#define ma 100005
using namespace std;

ll a[ma];
int main()
{
    ll tc,n,i,j;
    cin>>tc;
    while(tc--)
    {
       cin>>n;
       string s,t;
       cin>>s>>t;
       vector<ll>v;
       for(i=0;i<n;i++)
       {
           if(t[i]!=s[i])v.pb(i);
       }
       if(v.sz!=2)
       {
           cout<<"NO"<<endl;
           continue;
       }

       ll x=v[0];
       ll y=v[1];
       swap(s[x],t[y]);
       if(s==t)cout<<"YES"<<endl;
       else cout<<"NO"<<endl;



    }
    return 0;
}
