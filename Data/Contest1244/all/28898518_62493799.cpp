#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<ll,ll>

ll arr[200005];

map<ll,ll>mp;
int main()
{

    ll i,j,n,m,t;
    scanf("%lld%lld",&n,&m);

    for(i=0;i<n;i++){
        scanf("%lld",&arr[i]);
        mp[arr[i]]++;
    }

    sort(arr,arr+n);

    ll ans=arr[n-1]-arr[0];

    for(i=0,j=n-1;i<j;){
            //cout<<ans<<" "<<i<<" "<<j<<endl;
            if(arr[i]==arr[i+1]){i++; continue;}
            if(arr[j]==arr[j-1]){j--;continue;}
        if(mp[arr[j]]>mp[arr[i]]){
            if((arr[i+1]-arr[i])*mp[arr[i]]<=m){
                m-=(arr[i+1]-arr[i])*mp[arr[i]];
                mp[arr[i+1]]+=mp[arr[i]];
            ans-=arr[i+1]-arr[i];
            i++;
            }
            else{
                ans-=m/mp[arr[i]];
                break;
            }
        }
        else{
            if((arr[j]-arr[j-1])*mp[arr[j]]<=m){
                m-=(arr[j]-arr[j-1])*mp[arr[j]];
                mp[arr[j-1]]+=mp[arr[j]];
            ans-=arr[j]-arr[j-1];
            j--;
            }
            else{
                ans-=m/mp[arr[j]];
            break;
            }
        }
    }
    cout<<max(0LL,ans)<<endl;
}

