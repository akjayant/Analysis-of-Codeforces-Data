#include <bits/stdc++.h>
#define mk make_pair
#define fs first
#define sc second
using namespace std;
typedef long long ll;
typedef long double ld;
int a[100010];
int main(){
    int n, t;
    cin>>t;
    while(t--){
        ll ans=0, a, b, c;
        cin>>a>>b>>c;
        ll tmp=b/2, tmp1=c/2;
        ans=3*min(b, tmp1);
        b-=min(b, tmp1);
        ans+=3*min(a, b/2);
        cout<<ans<<endl;
    }
  return 0;
}


