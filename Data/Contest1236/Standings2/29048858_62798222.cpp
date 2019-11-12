#define IOS ios::sync_with_stdio(false);
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e5 + 7;
const int M = 3e5 + 7;
const int INF = 1e8 + 7;
ll mod = 998244353;

int n;

int main(){
    cin >> n;
    vector<int> ans[333];
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= n; ++ j){
            ans[i & 1 ? j : n - j + 1].push_back((i-1)*n+j);
        }
    }
//
//    for(int i = 1; i <= n; ++ i){
//        for(int j = 1; j <= n; ++ j){
//            int x = 0;
//            if(i == j) continue;
//            for(int id = 0; id < ans[i].size(); ++ id){
//                for(int jd = 0; jd < ans[j].size(); ++ jd){
//
//                    if(ans[i][id] > ans[j][jd]){
//                        ++ x;
//                    }
//
//                }
//            }
//            cout << i << " " << j << " " << x << endl;
//        }
//    }
    for(int i =  1; i <= n; ++ i){
        for(int j = 0; j < ans[i].size(); ++ j){
            printf("%d%c", ans[i][j], j == ans[i].size() - 1 ? '\n' : ' ');
        }
    }


    return 0;
}