#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n,i,p,c=0,y;
    cin >> n;
    y = n;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            c++;
            p=i;
            while(n%i==0)
            {
                n=n/i;
            }
        }
    }
    if(n>1 && n!=y)
    {
        c++;
        p = n;
    }
    if(c==0)
    {
        cout << n;
    }
    else if(c>=2)
    {
        cout << "1\n";
    }
    else
    {
        cout << p << "\n";
    }
}
