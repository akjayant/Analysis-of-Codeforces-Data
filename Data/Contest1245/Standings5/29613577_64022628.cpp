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

const ll DIM=1e5+7;
const ll DIMM=1e5+7;
const ll INF=1e18+7;
const ll X=20;
const ll MODULO=1000000007;

ll ns;
str s;
ll pr[DIM];
ll f,c,res;

int main()
{
    //freopen("input.txt","r",stdin);
    fast;
    //ll x1,y1,x2,y2;

    cin>>s;
    ns=s.length();

    pr[0]=1;
    pr[1]=1;
    for(int i=2;i<=ns;i++)pr[i]=(pr[i-1]+pr[i-2])%MODULO;

    if(s[0]=='m' || s[0]=='w')f=1;

    res=1;
    c=1;
    for(int i=1;i<ns;i++){

     if(s[i]=='m' || s[i]=='w')f=1;

     if(s[i]==s[i-1]){
      if(s[i]=='u' || s[i]=='n')
       c++;
     }
     else{
      res*=pr[c];
      res%=MODULO;
      c=1;
     }
    }
    res*=pr[c];
    res%=MODULO;
    if(f==1)cout<<0<<endl;
    else cout<<res<<endl;
    return 0;
}
