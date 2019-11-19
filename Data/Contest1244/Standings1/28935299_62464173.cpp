#include <bits/stdc++.h>
#define pi acos(-1)
using namespace std;
const int N=5e3+10, base=1e9+123;
int t,a,b,c,d,k;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cin>>a>>b>>c>>d>>k;
        if(ceil((float)a/c)+ceil((float)b/d)>k) cout<<-1<<'\n';
        else cout<<ceil((float)a/c)<<' '<<ceil((float)b/d)<<'\n';
    }
    return 0;
}
