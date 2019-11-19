
/*Hey, What's up?*/

#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
vector<long long>v;
int main()
{
    fastio;
    long long a=0,b=0,c,d,e,f=0,l,g,m,n,k,i,j,t,p,q;
    cin>>n;
    d=sqrt(1.0*n);
    f=n;
    for(i=2;i<=d;i++){
        if(n%i==0){
            f=__gcd(i,f);
            p=n/i;
            f=__gcd(p,f);
        }
    }
    cout<<f<<'\n';
    return 0;
}
