#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define scanVec(vec , n) for(int i = 0; i < n ; i++){ cin>>vec[i];}
#define printVec(vec , n) for(int i = 0; i < n ; i++){ cout<<vec[i]<<" ";}
#define S second
#define F first
const int  MOD = 1e9 + 7;
const int  N = 1e5 + 7;

int main(){
    ios::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
    ll t ,n , res; cin>>t;
    vector<int> v(1005);
    char ch;
    while(t--){
        cin>>n;
        for(int i = 1 ; i <= n ; i++){
            cin>>ch;
            v[i] = ch - '0';
        }
        res = n;
        for(ll i = 1 ; i <= n ; i++){
            if(v[i]) res = max(res , 2 * i);
            if(v[i]) res = max(res , 2 * (n - i + 1));
        }
        cout<<res<<endl;
    }


    return 0;
}