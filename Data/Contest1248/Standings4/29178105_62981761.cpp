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
    int n;cin >> n;
    vector<LL> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(ALL(a));
    LL x=0,y=0;
    for (int i = 0; i < n/2; i++) {
        x+=a[i];
    }
    for (int i = n/2; i < n; i++) {
        y+=a[i];
    }
    cout << x*x + y*y << endl;
    return 0;
}
