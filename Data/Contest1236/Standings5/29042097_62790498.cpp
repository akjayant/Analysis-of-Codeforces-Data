#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define yoi cout<<"yo"<<endl;
#define debug(x) cerr << #x << " is " << x << endl;
#define all(x) x.begin(),x.end()
const lli inf=1e18;
const int mod=1e9+7;
lli power(lli x, lli y, lli p)
{
    if(!x)
        return 0;
    lli res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}
int main(){
IOS;
lli n,m;
cin>>n>>m;
lli x=power(2,m,mod)-1;
if(x<0)
    x++;
x=power(x,n,mod);
cout<<x<<endl;
}
