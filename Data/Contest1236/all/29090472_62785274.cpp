#include <bits/stdc++.h>

#define maxn 200005
#define mod 1000000007
#define inf 0x3f3f3f3f
#define start ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;

int main() {
    start;
    int T;
    cin>>T;
    while(T--){
        int a,b,c;
        cin>>a>>b>>c;
        int ans=0;
        int tmp=min(c/2,b);
        ans+=3*tmp;
        b-=tmp;
        tmp=min(b/2,a);
        ans+=3*tmp;
        cout<<ans<<'\n';
    }
    return 0;
}