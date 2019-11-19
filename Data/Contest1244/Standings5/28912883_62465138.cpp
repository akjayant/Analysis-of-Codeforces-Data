#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define mt make_tuple

using namespace std;

const ll N = 10010;
const ll mod = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,a,b,c,d,k,res1,res2;
    cin>>t;
    while(t--){
        cin>>a>>b>>c>>d>>k;
        res1 = 0;
        res2 = 0;
        res1 = a/c + min(1,a%c);
        res2 = b/d + min(1,b%d);
        if(res1 + res2 <= k)
            cout<<res1 + (k - res1 - res2)<<" "<<res2<<endl;
        else    cout<<-1<<endl;
    }
    return 0;
}