//Author - Rahil Malhotra
#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long
#define double long double

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        int gcd=__gcd(a,b);
        if(gcd==1)
            cout<<"Finite";
        else
            cout<<"Infinite";
        cout<<endl;
    }
}