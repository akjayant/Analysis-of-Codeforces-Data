#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
set<ll>s;
ll c[100010];
map<ll,ll>mp;
int main()
{
    ll n,k,i,a;
    scanf("%lld%lld",&n,&k);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&a);
        mp[a]++;
        s.insert(a);
    }
    int sum=0;
    for(auto it:s)
        c[++sum]=it;
    int l=1,r=sum;
    while(1)
    {
        if(l==r)break;
        else
        {
            if(mp[c[l]]<mp[c[r]])
            {
                ll zz=(c[l+1]-c[l])*mp[c[l]];
                if(k>=zz)
                {
                    k-=zz;
                    mp[c[l+1]]+=mp[c[l]];
                    l++;
                }
                else
                {
                    c[l]+=k/mp[c[l]];
                    break;
                }
            }
            else
            {
                ll zz=(c[r]-c[r-1])*mp[c[r]];
                if(k>=zz)
                {
                    k-=zz;
                    mp[c[r-1]]+=mp[c[r]];
                    r--;
                }
                else
                {
                    c[r]-=k/mp[c[r]];
                    break;
                }
            }
//            cout<<l<<" "<<r<<" "<<k<<endl;
        }
    }
    printf("%lld\n",c[r]-c[l]);
}
