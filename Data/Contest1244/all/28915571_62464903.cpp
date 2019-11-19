#include <bits/stdc++.h>
using namespace std;
int q,a,b,c,d,k;
int main()
{
    cin>>q;
    while(q--)
    {
        cin>>a>>b>>c>>d>>k;
        k-=((a-1)/c+1);
        k-=((b-1)/d+1);
        if(k<0)
            cout<<"-1\n";
        else
            cout<<(a-1)/c+1<<" "<<(b-1)/d+1<<"\n";
    }
}
