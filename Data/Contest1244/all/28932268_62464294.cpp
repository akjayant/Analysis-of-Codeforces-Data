#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define N 100000
#define M 205

int main()
{
//    freopen("f.txt","r",stdin);
//    freopen("g.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a,b,c,d,k,x,y,t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c>>d>>k;
        x=a/c;
        if(a%c)
            x++;
        y=b/d;
        if(b%d)
            y++;
        if(x+y>k)
            cout<<-1<<endl;
        else
            cout<<x<<" "<<y<<endl;
    }
    return 0;
}
