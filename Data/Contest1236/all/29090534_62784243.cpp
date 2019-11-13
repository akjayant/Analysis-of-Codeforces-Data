#include <iostream>

using namespace std;
int t,a,b,c,x,s;
int main()
{
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>a>>b>>c;
        x=min(b,c/2);
        s=x*3;
        b-=x;
        c-=2*x;
        x=min(a,b/2);
        s+=x*3;
        cout<<s<<'\n';
    }
    return 0;
}
