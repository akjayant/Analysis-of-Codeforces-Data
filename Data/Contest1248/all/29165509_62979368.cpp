#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll inf=10000000000000000;
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ll t,n,num,o1,o2,e1,e2;
    cin>>t;
    while(t--)
    {
        cin>>n;o1=0;o2=0;e1=0;e2=0;
        for(ll i=0;i<n;i++)
        {
            cin>>num;
            if(num&1)
            o1++;
            else
            e1++;
        }
        cin>>n;
        for(ll i=0;i<n;i++)
        {
            cin>>num;
            if(num&1)
            o2++;
            else
            e2++;
        }

        cout<<o1*o2+e1*e2<<endl;

    }

    return 0;
}
