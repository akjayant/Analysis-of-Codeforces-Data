#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n,p,w,d,x,y,z;

int main()
{
        cin>>n>>p>>w>>d;
        ll tp=p%w;
        bool flag=false;
        for(y=0;y<w;y++)
        {
            ll tmp=y*d%w;
            if(tmp==tp)
            {
                x=(p-d*y)/w;
                z=n-x-y;
                if(x>=0&&y>=0&&z>=0)
                {
                    flag=true;
                    break;
                }
            }
        }
        //cout<<"1"<<endl;
        if(flag)
            cout<<x<<" "<<y<<" "<<z<<endl;
        else
            cout<<"-1"<<endl;
        
}