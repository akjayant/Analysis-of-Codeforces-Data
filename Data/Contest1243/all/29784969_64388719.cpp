#include<bits/stdc++.h> 
using namespace std; 
#define ll long long int
#define v vector<ll>
#define vv vector<v>
//#define p pair<ll,ll>
#define MAX 15000001
#define vc vector<char>
int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    if (n==1)
    {
        cout<<1<<endl;
        return 0;
    }
    v temp;
    if (n%2==0)
    {
        temp.push_back(2);
        while (n%2==0)
            n=n/2;
    }

    for (ll i=3; i<=sqrt(n)+2; i++)
    {
        if (n%i==0)
        {
            temp.push_back(i);
            while (n%i==0)
                n=n/i;
        }
    }

    if (n>2)
    {
        temp.push_back(n);
    }
    if (temp.size()>=2)
    {
        cout<<1<<endl;
    }
    else
    {
        cout<<temp[0]<<endl;
    }
    return 0;   
} 