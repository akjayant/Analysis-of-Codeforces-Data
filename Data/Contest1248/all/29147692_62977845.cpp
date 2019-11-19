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

/*
テストケース全てに目を通す
テストケースが2個以下だったらなんかある
N最小のコーナーケースがないか調べる
制約をしっかりと確認する（1からNまでの順列、全て異なる値などの制約も含め）
操作の逆順を考える
Codeforcesではscanfを使う
エラー出力は消す
 */

int main() {
    int T;
    cin >> T;
    rep(t,T){
        int n;
        cin >> n;
        int odn=0;
        int evn=0;
        rep(i,n){
            int x;
            cin >> x;
            if(x%2==0)evn++;
            else odn++;
        }
        int m;
        cin >> m;
        int odm=0;
        int evm=0;
        rep(i,m){
            int x;
            cin >> x;
            if(x%2==0)evm++;
            else odm++;
        }
        cout << (ll)odn*(ll)odm+(ll)evn*(ll)evm << endl;
    }
    


}

/*



 */

