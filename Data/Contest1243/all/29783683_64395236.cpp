#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector < ll > vec;

int main()
{
    ll n,m,i,j,k,a,b,c,x,y,z;
    cin>>n;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            vec.push_back(i);
            if(n/i>1)
                vec.push_back(n/i);
        }

    }
    if(vec.size()==0)
    {
        vec.push_back(n);
    }
    a=vec[0];
    for(i=0;i<vec.size();i++)
    {
        b=vec[i];
        a=__gcd(a,b);
    }
    cout<<a<<endl;
}
