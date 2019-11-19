#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define pll pair<ll,ll>
#define pii pair<int,int>
#define rep(i,n) for(int i=0;i<n;i++)
#define sz(x) ((ll)(x).size())
#define pb push_back
#define mp make_pair
#define bit(n) (1LL<<(n))
#define F first
#define S second
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
const ll INF = 1LL<<60;
const ll mod = (int)1e9 + 7;

int main() {
    int n;
    cin >> n;
    deque<int> d(n);
    rep(i,n)cin >> d[i];
    sort(all(d));
    int x=0;
    int y=0;
    int cnt=0;
    while(!d.empty()){
        if(cnt%2==0){
            x+=d.back();
            d.pop_back();
        }
        else{
            y+=d.front();
            d.pop_front();
        }
        cnt++;
    }
    cout << (ll)x*(ll)x+(ll)y*(ll)y;
    


}

/*



 */

