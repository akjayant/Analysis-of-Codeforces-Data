#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define PB pusb_back
#define P push
#define mem(x,y) memset(x,y,sizeof(x))

int main()
{
    LL a,b,c,d,k,i,j,s,x,y;
    LL test,tc;
    cin>>test;

    for(tc=1; tc<=test; tc++)
    {
        cin>>a>>b>>c>>d>>k;
        x=a/c;
        if(a%c)
            x++;
        y=b/d;
        if(b%d)
            y++;
        if(x+y<=k)
            cout<<x<<" "<<y<<endl;
        else
            cout<<"-1\n";
    }


}

