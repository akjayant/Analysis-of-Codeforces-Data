#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = (int)a; i <= (int)b; ++i)
#define FORD(i, a, b) for (int i = (int)a; i >= (int)b; --i)
#define REP(i, n) for (int i = 0; i < (int)n; ++i)
#define Debug(x) cerr << #x << " = " << x << '\n';
#define HERE cerr << "HERE\n\n";
#define X first
#define Y second


using namespace std;
typedef pair <int, int> ii;
typedef vector <int> vi;



int main(){
    int n;
    cin >> n;
    vi ans[n];
    int id = 0, way = 1;
    FOR(i, 1, n*n){
        ans[id].push_back(i);
        id = id + way;
        if (id == n){
            way = -1;
            id--;
        }
        else if (id == -1){
            way = 1;
            id++;
        }
    }
    REP(i, n){
        REP(j, ans[i].size()) cout << ans[i][j] << ' ';
        cout << '\n';
    }
}
