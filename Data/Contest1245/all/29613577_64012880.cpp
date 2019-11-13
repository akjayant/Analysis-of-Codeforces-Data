/*

Nasha rozpovid pro yizhachka
Pro malenkogo necluhnanogo,

Yak spitkala malogo bida
Vzhe ne zhvavogo ne rumyanogo.

V temnim lisi bagato prygod
Ptahy, ravlyky, ckunsy, oleni,

Ta chomus potyagnulo yogo
Na dorizhenku acphaltovanu.


YYIIZZHHAACCHHOOKK!!
Pidnimus, pidberys!

YYIIZZHHAACCHHOOKK!!
Razom z namy posmihnys!

YYIIZZHHAACCHHOOKK!!
Navkrugy, ozernys!

YYIIZZHHAACCHHOOKK!!
YYIIZZHHAACCHHOOKK!!

*/

#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio();cin.tie();cout.tie();
#define ops cout<<"ops"<<endl;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pllll;
typedef string str;
typedef char cr;

const ll DIM=1e2+7;
const ll DIMM=1e5+7;
const ll INF=1e18+7;
const ll X=20;
const ll MODULO=1000000007;

ll nt;
ll n,a,b,c,res,n1;
ll vis[DIM];
str s,s2;
cr s1[DIM];

int main()
{
    //freopen("input.txt","r",stdin);
    fast;
    //ll x1,y1,x2,y2;

    s2="RPS";

    cin>>nt;
    while(nt--)
    {
        cin>>n>>a>>b>>c>>s;


        res=0;
        for(int i=0; i<n; i++)
        {
            if(s[i]==s2[0])
            {
                if(b>0)
                {
                    vis[i]=1;
                    res++;
                    b--;
                    s1[i]=s2[1];
                }
            }
            else if(s[i]==s2[1])
            {
                if(c>0)
                {
                    vis[i]=1;
                    res++;
                    c--;
                    s1[i]=s2[2];
                }
            }
            else
            {
                if(a>0)
                {
                    vis[i]=1;
                    res++;
                    a--;
                    s1[i]=s2[0];
                }
            }
        }

        for(int i=0; i<n; i++)
        {
            if(vis[i]==1)continue;

            if(s[i]==s2[0])
            {
                if(a>0)
                {
                    s1[i]=s2[0];
                    a--;
                }
                else if(c>0)
                {
                    s1[i]=s2[2];
                    c--;
                }
            }
            else if(s[i]==s2[1])
            {
                if(a>0)
                {
                    s1[i]=s2[0];
                    a--;
                }
                else if(b>0)
                {
                    s1[i]=s2[1];
                    b--;
                }
            }
            else
            {
                if(c>0)
                {
                    s1[i]=s2[2];
                    c--;
                }
                else if(b>0)
                {
                    s1[i]=s2[1];
                    b--;
                }
            }
        }

        n1=n/2;
        if(n%2==1)n1++;

        if(res>=n1)
        {
            cout<<"YES"<<endl;
            for(int i=0; i<n; i++)cout<<s1[i];
            cout<<endl;
        }
        else cout<<"NO"<<endl;
        for(int i=0;i<n;i++)vis[i]=0;
    }
    return 0;
}
