#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e6 + 100;
const int MOD = 1000000007;

void doc() {
    freopen("OB.inp","r",stdin);
    freopen("OB.out","w",stdout);
    ///cerr << "OK" << '\n';
}

int n;
typedef pair<int, int> ii;
#define X first
#define Y second
vector<ii> p;
int c[maxN], K[maxN];
struct Data{
    int X, Y;
    long long w;
    Data(){};
    Data(int _X, int _Y, long long _w) : X(_X), Y(_Y), w(_w){}
};

vector<Data> canh;

void Cre(){
    for(int i = 0; i < n - 1; i++)
    for(int j = i + 1; j < n; j++){
        long long _w = 1LL * (K[i] + K[j]) * (abs(p[i].X - p[j].X) + abs(p[i].Y - p[j].Y));
        canh.push_back(Data(i, j, _w));
    }
    for(int i = 0; i < n; i++)
        canh.push_back(Data(n , i, c[i]));
    sort(canh.begin(), canh.end(), [&](Data A, Data B){
        return A.w < B.w;
    });
}

int root[maxN * 5];

int findroot(int x){
    if (root[x] < 0) return x;
    else{
        root[x] = findroot(root[x]);
        return root[x];
    }
}

void Union(int s, int t){
    //if (root[s] > root[t]) swap(s, t);
    if (root[s] <= root[t]){
        root[s] += root[t];
        root[t] = s;
    }
    else Union(t, s);
}

vector<ii> Q;
vector<int> D;

void solve() {
    cin >> n;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        x--;y--;
        p.push_back(ii(x, y));
    }
    for(int i = 0; i < n; i++)
        cin >> c[i];
    for(int i = 0; i < n; i++)
        cin >> K[i];

    Cre();
    long long res = 0;
    for(int i = 0; i <= n; i++) root[i] = -1;
    for(int i = 0; i < (int)canh.size(); i++){
        int s = findroot(canh[i].X);
        int t = findroot(canh[i].Y);
        if (s != t){
            Union(s, t);
            if (canh[i].X == n) D.push_back(canh[i].Y);
            else
                Q.push_back({canh[i].X,canh[i].Y});
            res += canh[i].w;
        }
    }
    cout << res << '\n';
    cout << D.size() << '\n';
    for(int i = 0; i < (int)D.size(); i++)
        cout << D[i] + 1 << " ";
    cout << '\n' << Q.size() << '\n';
    for(int i = 0; i < (int)Q.size(); i++)
        cout << Q[i].X + 1 << " " << Q[i].Y + 1 << '\n';

}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
  //  doc();
//    int T;
//    cin >> T;
//    while (T--)

    solve();
}

