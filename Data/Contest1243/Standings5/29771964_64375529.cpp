#include<bits/stdc++.h>
#include<unistd.h>
#define REP(i,n) for(int i=0,i##_len=(n);i<i##_len;++i)
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define All(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;

int main(){
    int k;cin>>k;
    REP(q,k){
        int n;cin>>n;
        vector<int> a(n);
        REP(i, n) cin >> a[i];
        sort(rbegin(a),rend(a));
        int ans=0;
        rep(i,1,n+1){
            bool ok=true;
            REP(j,i){
                if(a[j]<i){
                    ok=false;
                }
            }
            if(ok) ans=i;
        }
        cout<<ans<<endl;
    }
}
