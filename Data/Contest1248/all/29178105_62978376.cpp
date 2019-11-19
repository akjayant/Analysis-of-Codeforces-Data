#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<LL,LL> P;
LL mod=1000000007;
LL LINF=1LL<<60;
const int INF=1<<30;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};




int main(){
    int t;cin >> t;
    while(t--){
        LL n,m;
        cin >> n;
        LL a=0,b=0;
        for (int i = 0; i < n; i++) {
            LL p;cin >> p;
            if(p%2) b++;
            else a++;
        }
        cin >> m;
        LL aa=0,bb=0;
        for (int i = 0; i < m; i++) {
            LL q;cin >> q;
            if(q%2) bb++;
            else aa++;
        }
        cout << aa*a + bb*b << endl;
    }
    return 0;
}
