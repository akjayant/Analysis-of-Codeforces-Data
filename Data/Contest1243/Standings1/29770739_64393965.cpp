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

ll a[ma],fr[30],fr1[30];
int main()
{
    ll tc,n,i,j;
    cin>>tc;
    while(tc--)
    {
        cin>>n;
        string s,t;
        vector<pair<ll,ll> >v;
        cin>>s>>t;
        bool f1=0;

        for(i=0; i<n; i++)
        {
            if(s[i]!=t[i])
            {
                ll x=-1;
                for(j=i+1; j<n; j++)
                {
                    if(s[j]==s[i])
                    {
                        x=j;
                        break;
                    }
                }
                if(x!=-1)
                {
                    v.pb(mk(x,i));
                    swap(s[x],t[i]);
                    continue;
                }
                bool f=0;
                for(j=i+1;j<n;j++)
                {
                    if(t[j]==s[i])
                    {
                        if(i+1==n)continue;
                        f=1;

                        v.pb(mk(i+1,j));
                        swap(s[i+1],t[j]);
                        v.pb(mk(i+1,i));
                        swap(t[i],s[i+1]);
                        break;

                    }
                }
                if(f==0)
                {
                    f1=1;
                    break;
                }

            }
        }
        if(f1==1||s!=t)
        {
            cout<<"No"<<endl;
            continue;
        }
        cout<<"Yes"<<endl;
        cout<<v.sz<<endl;
        f(i,0,v.sz)cout<<v[i].ff+1<<" "<<v[i].ss+1<<endl;


    }
    return 0;
}
