#include <bits/stdc++.h>
using namespace std;

const int MAXN=1e5+10;

set<int> x[MAXN];
set<int> y[MAXN];
set<int> xn[MAXN];
set<int> yn[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,k,a,b,px=1,py=1,mnx=0,mny=0,mxx,mxy,dir=1,ln,cnt=0;
    long long res=1,tot,NN,MM;
    cin>>n>>m>>k;
    NN=n;
    MM=m;
    tot=NN*MM-k;
    mxy=m+1;
    mxx=n+1;
    for(int i=1;i<=k;i++)
    {
        cin>>a>>b;
        y[a].insert(b);
        x[b].insert(a);
        yn[a].insert(-b);
        xn[b].insert(-a);
    }
    while(true)
    {
        if(dir==1)
        {
            auto xd=y[px].lower_bound(py);
            if(xd!=y[px].end())
                mxy=min(mxy,*xd);
            ln=mxy-py-1;
            if(ln==0&&cnt==0)
            {
                dir=2;
            }
            else
            {
                if(ln==0)
                    break;
                res+=ln;
                py=mxy-1;
                dir=2;
                mnx=max(mnx,px);
            }
            //cout<<px<<" "<<py<<"\n";
        }
        else
        if(dir==2)
        {
            auto xd=x[py].lower_bound(px);
            if(xd!=x[py].end())
                mxx=min(mxx,*xd);
            ln=mxx-px-1;
            if(ln==0)
                break;
            res+=ln;
            px=mxx-1;
            dir=3;
            mxy=min(mxy,py);
           //cout<<px<<" "<<py<<"\n";
        }
        else
        if(dir==3)
        {
            auto xd=yn[px].lower_bound(-py);
            if(xd!=yn[px].end())
                mny=max(mny,-(*xd));
            ln=py-mny-1;
            if(ln==0)
                break;
            res+=ln;
            py=mny+1;
            dir=4;
            mxx=min(mxx,px);
            //cout<<px<<" "<<py<<"\n";
        }
        else
        if(dir==4)
        {
            auto xd=xn[py].lower_bound(-px);
            if(xd!=xn[py].end())
                mnx=max(mnx,-(*xd));
            ln=px-mnx-1;
            if(ln==0)
                break;
            res+=ln;
            px=mnx+1;
            dir=1;
            mny=max(mny,py);
            //cout<<px<<" "<<py<<"\n";
        }
        cnt++;
    }
    if(res==tot)
        cout<<"Yes\n";
    else
        cout<<"No\n";
}
