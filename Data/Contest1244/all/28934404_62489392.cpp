#include <iostream>
#include <vector>
using namespace std;
vector< vector<int> > cst, edg;
vector<int> ans;
long long cal(int x, int p, int c, int d){
    long long res = cst[x][c];
    for(int i=0;i<edg[x].size();i++){
        int y = edg[x][i];
        if(y == p)continue;
        res += cal(y, x, (3-d-c)%3, c);
    }
    return res;
}
void set_ans(int x, int p, int c, int d){
    ans[x] = c;
    for(int i=0;i<edg[x].size();i++){
        int y = edg[x][i];
        if(y == p)continue;
        set_ans(y, x, (3-d-c)%3, c);
    }
}
int main(void){
    int n;
    cin >> n;
    cst.assign(n, vector<int>());
    edg.assign(n, vector<int>());
    ans.assign(n, 0);
    for(int i=0;i<n;i++){
        cst[i].assign(3, 0);
    }
    for(int j=0;j<3;j++){
        for(int i=0;i<n;i++){
            cin >> cst[i][j];
        }
    }
    for(int i=0;i<n-1;i++){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        edg[a].push_back(b);
        edg[b].push_back(a);
    }
    int s = 0;
    for(int i=0;i<n;i++){
        if(edg[i].size() > 2){
            cout << -1 << endl;
            return 0;
        }
        if(edg[i].size() == 1)s = i;
    }
    long long mx = 1e18;
    int ai, aj;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i == j)continue;
            long long res = cal(s, -1, i, j);
            if(res < mx){
                mx = res;
                ai = i;
                aj = j;
            }
        }
    }
    set_ans(s, -1, ai, aj);
    cout << mx << endl;
    for(int i=0;i<n;i++){
        cout << ans[i]+1 << " ";
    }
    cout << endl;
}
