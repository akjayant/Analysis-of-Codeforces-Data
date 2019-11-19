#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

#define REP(i,n) for(long long i = 0; i < (n); i++)
#define FOR(i, m, n) for(long long i = (m);i < (n); ++i)
#define ALL(obj) (obj).begin(),(obj).end()
#define SPEED cin.tie(0);ios::sync_with_stdio(false);

template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
template<class T> using PQ = priority_queue<T>;
template<class T> using PQR = priority_queue<T,vector<T>,greater<T>>;

constexpr long long MOD = (long long)1e9 + 7;
constexpr long long MOD2 = 998244353;
constexpr long long HIGHINF = (long long)1e18;
constexpr long long LOWINF = (long long)1e15;
constexpr long double PI = 3.1415926535897932384626433;

template <class T> vector<T> multivector(size_t N,T init){return vector<T>(N,init);}
template <class... T> auto multivector(size_t N,T... t){return vector<decltype(multivector(t...))>(N,multivector(t...));}
template <class T> void corner(bool flg, T hoge) {if (flg) {cout << hoge << endl; exit(0);}}
template <class T, class U>ostream &operator<<(ostream &o, const map<T, U>&obj) {o << "{"; for (auto &x : obj) o << " {" << x.first << " : " << x.second << "}" << ","; o << " }"; return o;}
template <class T>ostream &operator<<(ostream &o, const set<T>&obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
template <class T>ostream &operator<<(ostream &o, const multiset<T>&obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
template <class T>ostream &operator<<(ostream &o, const vector<T>&obj) {o << "{"; for (int i = 0; i < (int)obj.size(); ++i)o << (i > 0 ? ", " : "") << obj[i]; o << "}"; return o;}
template <class T, class U>ostream &operator<<(ostream &o, const pair<T, U>&obj) {o << "{" << obj.first << ", " << obj.second << "}"; return o;}
template <template <class tmp>  class T, class U> ostream &operator<<(ostream &o, const T<U> &obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr)o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
void print(void) {cout << endl;}
template <class Head> void print(Head&& head) {cout << head;print();}
template <class Head, class... Tail> void print(Head&& head, Tail&&... tail) {cout << head << " ";print(forward<Tail>(tail)...);}
template <class T> void chmax(T& a, const T b){a=max(a,b);}
template <class T> void chmin(T& a, const T b){a=min(a,b);}
void YN(bool flg) {cout << (flg ? "YES" : "NO") << endl;}
void Yn(bool flg) {cout << (flg ? "Yes" : "No") << endl;}
void yn(bool flg) {cout << (flg ? "yes" : "no") << endl;}

int main() {
    SPEED
    int N; cin >> N;
    vector<vector<ll>> c(3,vector<ll>(N));
    for(int i = 0; i < N; ++i) {
        cin >> c[0][i];
    }
    for(int i = 0; i < N; ++i) {
        cin >> c[1][i];
    }
    for(int i = 0; i < N; ++i) {
        cin >> c[2][i];
    }
    vector<vector<int>> edge(N);
    vector<int> cnt(N);
    for(int i = 0; i < N-1; ++i) {
        int a,b; cin >> a >> b;
        a--,b--;
        cnt[a]++,cnt[b]++;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    for(int i = 0; i < N; ++i) corner(cnt[i]>=3,-1);
    
    int root;
    for(int i = 0; i < N; ++i) if(cnt[i]==1) root = i;
    vector<ll> label(N,-1),ans;
    ll sum = 0,mini = HIGHINF;
    queue<int> q;
    
    for(int i = 0; i < N; ++i) label[i] = -1;
    q.push(root);
    label[root] = 0;
    while(q.size()) {
        int from = q.front();
        q.pop();
        for(int to:edge[from]){
            if(label[to]!= -1) continue;
            label[to] = (label[from]+1) % 3;
            q.push(to);
        }
    }
    sum = 0;
    for(int i = 0; i < N; ++i) sum += c[label[i]][i];
    if(sum < mini) {
        mini = sum;
        ans = label;
    }

    for(int i = 0; i < N; ++i) label[i] = -1;
    q.push(root);
    label[root] = 0;
    while(q.size()) {
        int from = q.front();
        q.pop();
        for(int to:edge[from]){
            if(label[to]!= -1) continue;
            label[to] = (label[from]+2) % 3;
            q.push(to);
        }
    }
    sum = 0;
    for(int i = 0; i < N; ++i) sum += c[label[i]][i];
    if(sum < mini) {
        mini = sum;
        ans = label;
    }
 
    for(int i = 0; i < N; ++i) label[i] = -1;
    q.push(root);
    label[root] = 1;
    while(q.size()) {
        int from = q.front();
        q.pop();
        for(int to:edge[from]){
            if(label[to]!= -1) continue;
            label[to] = (label[from]+1) % 3;
            q.push(to);
        }
    }
    sum = 0;
    for(int i = 0; i < N; ++i) sum += c[label[i]][i];
    if(sum < mini) {
        mini = sum;
        ans = label;
    }

    for(int i = 0; i < N; ++i) label[i] = -1;
    q.push(root);
    label[root] = 1;
    while(q.size()) {
        int from = q.front();
        q.pop();
        for(int to:edge[from]){
            if(label[to]!= -1) continue;
            label[to] = (label[from]+2) % 3;
            q.push(to);
        }
    }
    sum = 0;
    for(int i = 0; i < N; ++i) sum += c[label[i]][i];
    if(sum < mini) {
        mini = sum;
        ans = label;
    }

    for(int i = 0; i < N; ++i) label[i] = -1;
    q.push(root);
    label[root] = 2;
    while(q.size()) {
        int from = q.front();
        q.pop();
        for(int to:edge[from]){
            if(label[to]!= -1) continue;
            label[to] = (label[from]+1) % 3;
            q.push(to);
        }
    }
    sum = 0;
    for(int i = 0; i < N; ++i) sum += c[label[i]][i];
    if(sum < mini) {
        mini = sum;
        ans = label;
    }

    for(int i = 0; i < N; ++i) label[i] = -1;
    q.push(root);
    label[root] = 2;
    while(q.size()) {
        int from = q.front();
        q.pop();
        for(int to:edge[from]){
            if(label[to]!= -1) continue;
            label[to] = (label[from]+2) % 3;
            q.push(to);
        }
    }
    sum = 0;
    for(int i = 0; i < N; ++i) sum += c[label[i]][i];
    if(sum < mini) {
        mini = sum;
        ans = label;
    }
    cout << mini << endl;
    for(int i = 0; i < N; ++i) {
        cout << ans[i]+1 << " ";
    }
    cout << endl;

    return 0;
}
