#include<bits/stdc++.h>

using namespace std;

#define LCM(a,b)                (a / __gcd(a,b) ) *b
#define GCD(a,b)                __gcd(a,b)
#define dist(x1,y1,x2,y2)       sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))
#define distl(x1,y1,x2,y2)      sqrtl((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))
#define fRead(x)                freopen(x,"r",stdin)
#define fWrite(x)               freopen (x,"w",stdout)
#define LL                      long long
#define ULL                     unsigned long long
#define pb                      push_back
#define tcase                   cout<<"Case "<<C++<<": ";
#define all(a)                  a.begin(),a.end()
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end
#define ABS(x)                  ((x)<0?-(x):(x))
#define min3(a,b,c)             min(a,min(b,c))
#define min4(a,b,c,d)           min(a,min(b,min(c,d)))
#define max3(a,b,c)             max(a,max(b,c))
#define max4(a,b,c,d)           max(a,max(b,max(c,d)))
#define PI                      acos(-1.0)
#define ff                      first
#define ss                      second
#define SP(x,y)                 fixed<<setprecision((y))<<(x)
#define FastRead                ios_base::sync_with_stdio(0);cin.tie(NULL);
#define FOR(x, l, r)            for (int x = l; x<=r; ++x)
#define REP(x,r)                for (int x = 0; x <r; ++x)
#define NN                      cout<<"\n";
#define NNN                     cout<<"\n------------------------------\n";

//***********************************************************************//
//                      SHAHED AHMED, CSE'15, IUT                        //
//***********************************************************************//

set<LL> rob[100010];
set<LL> cob[100010];

LL yfirst;
LL ylast;

LL xfirst;
LL xlast;



LL shoot(LL pos, LL lo,LL hi,LL d)
{
    if(lo>hi) swap(lo,hi);

    if(d==0)
    {
        if(rob[pos].lower_bound(lo)==rob[pos].upper_bound(hi)) return hi;

        auto it = rob[pos].lower_bound(lo);
        return *it;
    }
    if(d==1)
    {
        if(cob[pos].lower_bound(lo)==cob[pos].upper_bound(hi)) return hi;

        auto it = cob[pos].lower_bound(lo);
        return *it;
    }

    if(d==2)
    {
        if(rob[pos].lower_bound(lo)==rob[pos].upper_bound(hi)) return lo;

        auto it = rob[pos].upper_bound(hi);
        it--;
        return *it;
    }


    if(d==3)
    {
        if(cob[pos].lower_bound(lo)==cob[pos].upper_bound(hi)) return lo;

        auto it = cob[pos].upper_bound(hi);
        it--;
        return *it;
    }

}




int main()
{
    LL n,m,k,x,y;

    cin>>n>>m>>k;

    for(LL i=1;i<=k;i++)
    {
        cin>>x>>y;
        rob[x].insert(y);
        cob[y].insert(x);
    }

    LL dd = 0;

    xfirst = 0 ;
    yfirst = 0;

    xlast = n+1;
    ylast = m+1;

    LL currx=1,curry=0;
    LL ans=0;
    while(1)
    {


        LL prevx = currx;
        LL prevy = curry;

        if(dd==0)  // shoot row L ->R
        {
            LL nxty = shoot(currx,curry,ylast,dd);
            curry =nxty-1;
            xfirst=currx;
        }

        if(dd==1) // shoot col up ->down
        {
            LL nxtx = shoot(curry,currx,xlast,dd);
            currx = nxtx-1;
            ylast = curry;
        }

        if(dd==2) // shoot col R ->L
        {
            LL nxty = shoot(currx,yfirst,curry,dd);
            curry =nxty+1;
            xlast = currx;
        }

        if(dd==3) // shoot down -> up
        {
            LL nxtx = shoot(curry,xfirst,currx,dd);
            currx = nxtx+1;
            yfirst = curry;
        }

        //cout<<currx<<" "<<curry<<"\n";
        if(prevx==currx && prevy==curry) break;


        ans+= ABS(currx-prevx) + ABS(curry-prevy);

        dd =dd+1;
        dd%=4;

    }

    ans+=k;

    if(ans==n*m) cout<<"Yes\n";
    else cout<<"No\n";




}
