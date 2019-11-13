#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <iomanip>
#include <string>
#include <map>
#include <stdio.h>
using namespace std;


typedef long long ll;
typedef vector<ll> vi;
typedef vector<vector <ll> > vvi;
typedef pair<ll,ll> ii;
typedef vector <ii> vii;
#define REP(i,a,b)\
for (ll i=a; i<b; i++)

#define fastIO  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


/*ll toint(const string &s) { stringstream ss; ss << s; ll x; ss >> x; return x; }
string tostring ( ll number ){  stringstream ss; ss<< number; return ss.str();}*/

int main()
{
    fastIO;
	ll T;
    cin>>T;
    REP(t,0,T)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        ll maxx=0;
        REP(i,0,min(a,b/2)+1)
        {
            ll er=i*3+max((ll)0,min(b-2*i,c/2))*3;
            if (er>maxx)
                maxx=er;
        }
        cout<<maxx<<endl;

    }
}