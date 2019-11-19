#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
set<int> sx[100005];
set<int> sy[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,m,k;
    cin>>n>>m>>k;

    for(int i=0;i<k;i++)
    {
        int c,d;
        cin>>c>>d;
        sx[c].insert(d);
        sy[d].insert(c);
    }
    ll path=1;
    ll dir=0,xp=0,yp=m+1,xn=n+1,yn=0;
    int nowx=1,nowy=1;
    while((xp<xn)&&(yn<yp))
    {
        if(dir==0)
        {
            int tem=yp;
            if(!sx[nowx].empty())
            {
                auto o=sx[nowx].upper_bound(nowy);
                if(o!=sx[nowx].end())
                {
                    if(*o<tem)
                        tem=*o;
                }
            }
            if((tem-nowy==1)&&(nowx==1))
            {
                dir++;
                continue;
            }
            if(tem-nowy==1)
                break;
            path=path+tem-nowy-1;
            nowy=tem-1;
            xp=nowx;
        }
        if(dir==1)
        {
            int tem=xn;
            if(!sy[nowy].empty())
            {
                auto o=sy[nowy].upper_bound(nowx);
                if(o!=sy[nowy].end())
                {
                    if(*o<tem)
                        tem=*o;
                }
            }
            if(tem-nowx==1)
                break;
            path=path+tem-nowx-1;
            nowx=tem-1;
            yp=nowy;
        }
        if(dir==2)
        {
            int tem=yn;
            if(!sx[nowx].empty())
            {
                auto o=sx[nowx].upper_bound(nowy);

                if(o!=sx[nowx].begin())
                {
                    o--;
                    if(*o>tem)
                        tem=*o;
                }
            }
            //cout<<"NOWY"<<yn<<'\n';
            if(nowy-tem==1)
                break;
            path=path+nowy-tem-1;
            nowy=tem+1;
            xn=nowx;
        }
        if(dir==3)
        {
            int tem=xp;
            if(!sy[nowy].empty())
            {
                auto o=sy[nowy].upper_bound(nowx);

                if(o!=sy[nowy].begin())
                {
                    o--;
                    if(*o>tem)
                        tem=*o;
                }
            }

            if(nowx-tem==1)
                break;
            path=path+nowx-tem-1;
            nowx=tem+1;
            yn=nowy;
        }
        //cout<<dir<<' '<<nowx<<' '<<nowy<<' '<<path<<'\n';
        dir++;
        dir%=4;
    }
    //cout<<path<<'\n';
    if(n*m-k==path)
        cout<<"Yes"<<'\n';
    else cout<<"No"<<'\n';
}
