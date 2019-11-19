#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <stdio.h>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstdlib>
#define pi 3.14159265
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()

using namespace std;
typedef long long ll;
const ll mod = 1000000000 + 7;
const double kd = 1.41421356237;

int main()
{
    //freopen("ladder.in ","r",stdin);
    //freopen("ladder.out","w",stdout);
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt;
    cin>>tt;
    for(;tt;tt--)
    {
        ll n,m,chn=0,nchn=0,chm=0,nchm=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            if(a % 2 == 0)
                chn++;
            else nchn++;
        }
        cin>>m;
        for(int i=0;i<m;i++)
        {
            int a;
            cin>>a;
            if(a % 2 == 0)
                chm++;
            else nchm++;
        }
        cout<<nchn * nchm + chn * chm<<'\n';
    }
}
