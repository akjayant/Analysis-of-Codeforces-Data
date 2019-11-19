#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,dem;
vector<int> a;
main()
{
    //freopen("c.inp","r",stdin);
    //freopen("c.out","w",stdout);
    cin>>n;
    int d=sqrt(n);
    for(int i=2;i<=d;i++)
    {
        if(n%i==0)a.push_back(i);
        while(n%i==0)
        n/=i;
    }
    if(n>1)
        a.push_back(n);
    if(a.size()==1)
    {
        cout<<a[0];
        return 0;
    }
    cout<<1;
    return 0;
}
