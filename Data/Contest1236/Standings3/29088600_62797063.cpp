#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const int MOD = 1e9 + 7;

signed main(){
    int n;
    cin >> n;
    vector<int> ans[n];
    REP(i,n){
        if(i % 2 == 0){
            for(int j = 1; j <= n; j++){
                ans[i].push_back(j + n * i);
            }
        }else{
            for(int j = n; j >= 1; j--){
                ans[i].push_back(j + n * i);
            }
        }
    }
    REP(i,n){
        REP(j,n){
            cout << ans[j][i];
            if(j != n - 1){
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}