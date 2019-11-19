#include <iostream>
#include <vector>
#define Long long long int
using namespace std;

const int M = 100 * 1000;
const int C = 3;
const Long inf = 1e18;
int n, p, q, r, s;
int color[M];
int cost[M][C];
vector <int> N[M];

void read();
bool poss();
void init();
void print();
int getLeaf();
Long costOf(int, int, int, int);
void setColor();
void dfs(int, int, int, int);
Long sum();

int main(){
    read();
    if(poss()){
        init();
        print();
    }
    else
        cout << -1 << endl;
    return 0;
}

void read(){
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int c = 0; c < C; c++)
        for(int v = 0; v < n; v++)
            cin >> cost[v][c];
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        N[u].push_back(v);
        N[v].push_back(u);
    }
}

bool poss(){
    for(int v = 0; v < n; v++)
        if(N[v].size() > 2)
            return false;
    return true;
}

void init(){
    int u = getLeaf();
    int v = N[u][0];
    p = u;
    q = v;
    Long best = inf;
    Long value = costOf(u, v, 0, 1);
    if(value < best){
        best = value;
        r = 0;
        s = 1;
    }
    value = costOf(u, v, 0, 2);
    if(value < best){
        best = value;
        r = 0;
        s = 2;
    }
    value = costOf(u, v, 1, 0);
    if(value < best){
        best = value;
        r = 1;
        s = 0;
    }
    value = costOf(u, v, 1, 2);
    if(value < best){
        best = value;
        r = 1;
        s = 2;
    }
    value = costOf(u, v, 2, 0);
    if(value < best){
        best = value;
        r = 2;
        s = 0;
    }
    value = costOf(u, v, 2, 1);
    if(value < best){
        best = value;
        r = 2;
        s = 1;
    }
}

void print(){
    costOf(p, q, r, s);
    cout << sum() << endl;
    for(int v = 0; v < n; v++){
        if(v > 0)
            cout << ' ';
        cout << color[v] + 1;
    }
    cout << endl;
}

int getLeaf(){
    for(int v = 0; v < n; v++)
        if(N[v].size() == 1)
            return v;
    return -1;
}

Long costOf(int u, int v, int a, int b){
    setColor();
    color[u] = a;
    color[v] = b;
    dfs(u, -1, -1, -1);
    return sum();
}

void setColor(){
    for(int v = 0; v < n; v++)
        color[v] = -1;
}

void dfs(int v, int p, int a, int b){
    int col = color[v];
    if(color[v] == -1){
        if(a > 0 && b > 0)
            col = 0;
        else if(a < 2 && b < 2)
            col = 2;
        else
            col = 1;
        color[v] = col;
    }
    for(int i = 0; i < N[v].size(); i++){
        int u = N[v][i];
        if(u != p)
            dfs(u, v, b, col);
    }
}

Long sum(){
    Long res = 0;
    for(int v = 0; v < n; v++)
        res += cost[v][color[v]];
    return res;
}

