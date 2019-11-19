#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int n,a[maxn];
ll A,B;
void solve(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n/2;++i){
        A+=a[i];
    }
    for(int i=n/2+1;i<=n;++i){
        B+=a[i];
    }
    cout<<A*A+B*B<<endl;
}
int main(){
    solve();

    return 0;
}