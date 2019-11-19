#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 5;
const ll mod=1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;

    vector<ll> arr(n);
    for(ll i=0;i<n;i++)
        cin>>arr[i];

    sort(arr.begin() , arr.end() );
    ll h=0,v=0;
    ll i=0,j=n-1;
    while(i<j){
        h=h+arr[j];
        v=v+arr[i];
        i++;
        j--;
    }

    if(i==j)
        h = h + arr[j];

    cout<<h*h + v*v;
}

