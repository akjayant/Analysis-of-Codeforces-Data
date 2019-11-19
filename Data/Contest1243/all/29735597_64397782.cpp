#include<bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main()
{
    FIO;
    long long n,i,c=0;
    cin>>n;
    vector<long long>v;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            v.push_back(i);
            if(i*i!=n)
                v.push_back(n/i);
        }
    }
    v.push_back(n);
    for(i=0;i<v.size();i++)
        c=__gcd(c,v[i]);
    cout<<c<<endl;
}
