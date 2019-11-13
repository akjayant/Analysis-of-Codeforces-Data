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

/*const ll DIM=1e5+7;
const ll DIMM=1e5+7;
const ll INF=1e18+7;
const ll X=20;
const ll MODULO=1000000007;*/

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pllll;
typedef string str;
typedef char cr;

ll nt;
ll a,b;

int main()
{
    //freopen("input.txt","r",stdin);
    fast;
    //ll x1,y1,x2,y2;

    cin>>nt;
    while(nt--){
     cin>>a>>b;
     if(__gcd(a,b)==1)cout<<"Finite"<<endl;
     else cout<<"Infinite"<<endl;
    }
    return 0;
}
