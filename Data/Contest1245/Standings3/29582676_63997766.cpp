#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define pii pair<int,int>
#define pll pair<ll,ll>
const int maxn=100000+10;


int main()
{
    int n,a,b;
    cin>>n;
    while(n--){
        cin>>a>>b;
        if(__gcd(a,b)==1)
            cout<<"Finite"<<endl;
        else
            cout<<"Infinite"<<endl;
    }
    return 0;
}
