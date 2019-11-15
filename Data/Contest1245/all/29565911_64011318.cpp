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


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        LL n;
        LL r,p,s;

        cin>>n>>r>>p>>s;

        string S;

        cin>>S;

        LL win=0;
        string ans;
        for(auto u:S)
        {
            if(u=='R'&&p>0) {p--; win++;ans+='P';}
            else if(u=='P'&&s>0) {s--; win++;ans+='S';}
            else if(u=='S'&&r>0) {r--; win++;ans+='R';}
            else ans+='-';
        }

        int need = n/2;
        if(n%2==1) need++;

        if(win>=need)
        {
            cout<<"YES\n";

            for(auto u:ans)
            {
                if(u!='-') cout<<u;
                else
                {
                    if(p>0) {cout<<"P";p--;}
                    else if(s>0) {cout<<"S";s--;}
                    else if(r>0) {cout<<"R";r--;}
                }
            }
            cout<<"\n";
        }
        else cout<<"NO\n";


    }


}
