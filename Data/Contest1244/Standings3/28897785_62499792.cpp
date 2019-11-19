#include<bits/stdc++.h>
//#define DEBUG
#define FOR(i,n) for(int i=1;i<=n;i++)
#define FORZ(i,n) for(int i=0;i<n;i++)
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define piii pair<pair<int,int>,int>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define SIZE 32622
#define MOD 1000000007  
#define LD long long double
#define bpc __builtin_popcount
#define gentum getnum
using namespace std;

inline ll getnum()
{
    char c = getchar();
    ll num,sign=1;
    for(;c<'0'||c>'9';c=getchar())if(c=='-')sign=-1;
    for(num=0;c>='0'&&c<='9';)
    {
        c-='0';
        num = num*10+c;
        c=getchar();
    }
    return num*sign;
}

ll A[100005];
multiset<ll> Set;

int main()
{
    ll n=getnum(),k=getnum();

    for(int i=1;i<=n;i++)A[i]=getnum();

    sort(A+1,A+n+1);

    ll f=1,b=1,ch=-1,mn=A[1],mx=A[n];
    for(int l=1,r=n;l<r;)
    {
        if(b<f)
        {
            if((A[r]-A[r-1])*b<=k)
            {
                k-=(A[r]-A[r-1])*b;
                r--;
                b++;
                mx=A[r];
            }
            else
            {
                mx-=k/b;
                break;
            }
        }
        else
        {
            if((A[l+1]-A[l])*f<=k)
            {
                k-=(A[l+1]-A[l])*f;
                l++;
                f++;
                mn=A[l];
            }
            else
            {
                mn+=k/f;
                break;
            }
        }
    }

    printf("%lld\n",max(0LL,mx-mn));
    
}