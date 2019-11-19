#include<bits/stdc++.h>
#define int int64_t
using namespace std;
signed main()
{
    int n,p,w,d;
    cin>>n>>p>>w>>d;
    
    for(int i=0;i<=100000;i++)
    {
        if( ( p - i*d )%w==0){
            int win= (p-i*d)/w;
            int draw=i;
            int loss=n-win-draw;
            if( win<0 || loss<0 || draw <0)
                continue;
            cout<<win<<" "<<draw<<" "<<loss<<endl;
            return 0;
        }
    }
    cout<<"-1"<<endl;
    return 0;
}