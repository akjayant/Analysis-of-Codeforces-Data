#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<" --> "<<x<<endl;
#define N 100005
#define M 1000000007
#define pii pair<int,int>
using namespace std;
main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        a=__gcd(a,b);
        if(a==1)
            cout<<"Finite\n";
        else
            cout<<"Infinite\n";
    }

}
