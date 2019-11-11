#include <bits/stdc++.h>

using namespace std;
long t,x,y;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>x>>y;
        if(__gcd(x,y)==1)
            cout<<"Finite"<<"\n";
        else cout<<"Infinite"<<"\n";
    }
}
