#include<bits/stdc++.h>
#define MAX 100000
#define fi first
#define se second
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

ll n,k;
deque<pll> arr;
map<ll,ll> m;

int main(){
    cin>>n>>k;
    for(ll x,i=0; i<n; ++i){
        cin>>x;
        m[x]++;
    }
    for(auto& x:m){
        arr.push_back(x);
    }
    while(arr.size()>1){
        pll& a=arr[0];
        pll& b=arr[1];
        pll& c=arr[arr.size()-2];
        pll& d=arr.back();
        if(a.se<d.se){
            ll cnt=a.se*(b.fi-a.fi);
            if(k>=cnt){
                k-=cnt;
                b.se+=a.se;
                arr.pop_front();
            } else{
                a.fi+=k/a.se;
                break;
            }
        } else{
            ll cnt=d.se*(d.fi-c.fi);
            if(k>=cnt){
                k-=cnt;
                c.se+=d.se;
                arr.pop_back();
            } else{
                d.fi-=k/d.se;
                break;
            }
        }
    }
    cout<<arr.back().fi-arr.front().fi;
    return 0;
}
