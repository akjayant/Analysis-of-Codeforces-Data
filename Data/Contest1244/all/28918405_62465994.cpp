#include <bits/stdc++.h>

using namespace std;

long long t,a,b,c,d,k,x,y;

int main()
{
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>a>>b>>c>>d>>k;
        x=a/c;
        if(a%c>0)x++;
        y=b/d;
        if(b%d>0)y++;
        if(x+y<=k)cout<<x<<" "<<y<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}
