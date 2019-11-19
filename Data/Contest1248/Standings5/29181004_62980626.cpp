#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pb push_back
#define pll pair<ll, ll>
#define fi first
#define se second

const int md = (int) 1e9 + 7;
const int siz = 300005;

ll arr[siz];
ll n, m, k, l, t;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>t;
    while(t--){
        cin>>n;
        ll odds=0, evens=0, o2=0, e2=0; 
        for(int i=0;i<n;i++){
            cin>>k;
            if(k%2) odds++;
            else evens++;
        }
        cin>>m;
 
        for(int i=0;i<m;i++){
            cin>>k;
            if(k%2) o2++;
            else e2++;
        }

        cout<<o2*odds+e2*evens<<endl;
    }
    
}