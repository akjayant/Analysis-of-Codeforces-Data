#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
int gcd(int a, int b)
{
    if(b > a)
        swap(a, b);
    if(b == 0)
        return a;
    return gcd(a % b, b);
}
signed main() {
    int q;
    cin>>q;
    while(q--)
    {
        int a, b;
        cin>>a>>b;
        //cout<<gcd(a, b)<<endl;
        if(gcd(a, b) > 1)
        {
            cout<<"Infinite"<<endl;
        }
        else
        {
            cout<<"Finite"<<endl;
        }
    }
}