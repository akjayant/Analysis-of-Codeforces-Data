#include <iostream>
#include <fstream>
#include <numeric>
#include <stdio.h>
#include <cmath>
#include <queue>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <deque>
#include <bitset>
#include <cstring>
#include <sstream>
 
#define f first
#define s second
#define ll long long
#define ld long double
#define pb push_back
#define all(x) x.begin(),x.end()
#define mp make_pair
#define y0 eto
#define y1 mezhdy
#define y2 nami
#define left extermination
#define right dismemberment
 
using namespace std;
 
typedef pair<int,int> pii;
 
template <class T>void read(vector<T> &a,ll n){T x; a.clear();for(ll i=0;i<n;i++){cin>>x;a.pb(x);}}
template <class T>void write(vector<T> &a){for(T x : a) cout<<x<<" ";cout<<endl;}

ll n,m,k;
ll cnt;
map<ll,set<ll> > r,c;

ll lx,ly,ux,uy;

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("INPUT.txt", "r", stdin);
    cin>>n>>m>>k;
    for(int i=0;i<k;i++)
    {
        ll a,b;
        cin>>a>>b;
        r[a].insert(b);
        c[b].insert(a);
    }
    for(int i=1;i<=n;i++)
    {
        if(r[i].count(1))
            break;
        else
            cnt++;
    }
    if(n*m==k+cnt)
    {
        cout<<"Yes";
        return 0;
    }
    
    lx=2;
    ly=1;
    ux=n;
    uy=m;
    ll x=1;
    ll y=1;
    cnt=1;
    while(1)
    {
        ll yy,xx;
        set<ll>::iterator it;
        
        
        it=r[x].lower_bound(y);
        if(it==r[x].end())
            yy=uy;
        else
            yy=min(uy,*it-1);
        
        //cout<<x<<" "<<y<<" ->  "<<x<<" "<<yy<<" "<<yy-y<<endl;
        
        if(yy==y)
            break;
        
        cnt+=(yy-y);
        y=yy;
        uy=yy-1;
        
        it=c[y].lower_bound(x);
        if(it==c[y].end())
            xx=ux;
        else
            xx=min(ux,*it-1);
        
        if(xx==x)
            break;
        
        //cout<<x<<" "<<y<<" ->  "<<xx<<" "<<y<<" "<<(xx-x)<<endl;
        cnt+=(xx-x);
        x=xx;
        ux=xx-1;
        
        it=r[x].lower_bound(y);
        if(it==r[x].begin())
            yy=ly;
        else
        {
            it--;
            yy=max(ly,*it+1);
        }
        
        if(yy==y)
            break;
        
        //cout<<x<<" "<<y<<" ->  "<<x<<" "<<yy<<" "<<(y-yy)<<endl;
            
        cnt+=(y-yy);
        y=yy;
        ly=yy+1;
        
        it=c[y].lower_bound(x);
        if(it==c[y].begin())
            xx=lx;
        else
        {
            it--;
            xx=max(lx,*it+1);
        }
        
        if(xx==x)
            break;
        
        //cout<<x<<" "<<y<<" ->  "<<xx<<" "<<y<<" "<<x-xx<<endl;
        
        cnt+=(x-xx);
        x=xx;
        lx=xx+1;
    }
    if(cnt+k==n*m)
        cout<<"Yes";
    else
        cout<<"No";
    
    
}
