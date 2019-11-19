#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policby.hpp>
 
#define ll long long int
#define mod 1000000007
using namespace std;
//using namespace __gnu_pbds;

//typedef tree<int,null_tbpe,less<int>,rb_tree_tag,tree_order_statistics_node_update> order_set;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,xa=0,ya=0;
    cin>>n;
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    ll i=0,j=n-1;
    while(1){
        xa += v[j--];
        if(j<i){
            break;
        }
        ya += v[i++];
        if(j<i){
            break;
        }
    }
    cout<<xa*xa+ya*ya;
    return 0;
}