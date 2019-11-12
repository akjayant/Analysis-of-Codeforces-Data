#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <random>
#include <iomanip>
#include <assert.h>
#include <ctime>
#include <random>
#include <fstream>
#include <sstream>


#define null nullptr

using namespace std;
typedef long long ll;
typedef double long dl;
typedef unsigned long long ull;

//struct Dinic{
//    struct edge{
//        ll from, to,flow,cap;
//    };
//    vector<edge> edges;
//    vector<vector<ll>> adj;
//    vector<ll> level;
//    vector<ll> ptr;
//    ll s,t,n;
//    Dinic(ll _s, ll _t, ll _n){
//        s=_s;
//        t=_t;
//        n=_n;
//        adj.resize(n);
//        level.resize(n);
//        ptr.resize(n);
//    }
//    void clear(){
//        n=0;
//        s=0;
//        t=0;
//        adj.clear();
//        level.clear();
//        ptr.clear();
//    }
//    void resize(ll _s ,ll _t,ll _n){
//        s=_s;
//        t=_t;
//        n=_n;
//        adj.resize(n);
//        level.resize(n);
//        ptr.resize(n);
//    }
//    void add_edge(ll from,ll to, ll cap){
//        edge a = {from,to,0,cap};
//        edge b = {to,from,0,0};
//        adj[from].push_back(edges.size());
//        edges.push_back(a);
//        adj[to].push_back(edges.size());
//        edges.push_back(b);
//    }
//    queue<ll> q;
//    bool bfs(){
//        level[s] = 0;
//        q.push(s);
//        while(!q.empty()){
//            ll v = q.front();
//            q.pop();
//            for(auto k : adj[v]){
//                auto e = edges[k];
//                if(e.cap-e.flow==0 || level[e.to]!=-1)continue;
//                level[e.to] = level[v] + 1;
//                q.push(e.to);
//            }
//        }
//        return level[t]!=-1;
//    }
//    ll dfs(ll node,ll flow = 1e10){
//        if(node==t){
//            return flow;
//        }
//        if(flow<=0){
//            return 0;
//        }
//        for(ll & cid = ptr[node];cid<adj[node].size();cid++){
//            auto id = adj[node][cid];
//            ll to = edges[id].to;
//            if(level[node]+1 !=level[to] || edges[id].cap-edges[id].flow==0)continue;
//            ll added = dfs(to,min(flow,edges[id].cap-edges[id].flow));
//            if(added>0){
//                edges[id].flow+=added;
//                edges[id^1].flow-=added;
//                return added;
//            }
//        }
//        return 0;
//    }
//    ll flow(){
//        ll answer =0;
//        while(true){
//            fill(level.begin(),level.end(),-1);
//            if(!bfs()){
//                break;
//            }
//            fill(ptr.begin(),ptr.end(),0);
//            while(ll added = dfs(s)){
//                answer+=added;
//            }
//        }
//        return answer;
//    }
//    void correct(ll node,ll i ,vector<string> &for_per,vector<vector<ll>> &ma,map<string,ll> &lol){
//        vector<bool> used(n);
//        correct_dfs(t,i,for_per,ma,used,lol);
//    }
//    bool correct_dfs(ll node,ll i ,vector<string> &for_per,vector<vector<ll>> &ma,vector<bool> &used,map<string,ll> &lol){
//        used[node] =true;
//        if(node==s){
//            return true;
//        }
//        if(node == t){
//            for(int j = 0 ; j < adj[node].size();j++){
//                ll id = adj[node][j];
//                auto temp = lol[for_per[i]];
//                if(edges[id].to == ma[temp][temp]){
//                    edges[id].flow=0;
//                    edges[id^1].flow=0;
//                    edges[id^1].cap+=3;
//                    correct_dfs(edges[id].to,i,for_per,ma,used,lol);
//                    break;
//                }
//            }
//        }else{
//            for(int j = 0 ; j < adj[node].size();j++){
//                ll id = adj[node][j];
//                if(!used[edges[id].to]&&correct_dfs(edges[id].to,i,for_per,ma,used,lol)){
//                    edges[id].flow+=3;
//                    edges[id^1].flow-=3;
//                }
//            }
//        }
//
//
//
//        return false;
//    }
//};
//void grays(vector<ll> &g,ll pos , ll n){
//    if(pos== 0 ){
//        g[0]=0;
//        g[1] = 1;
//    }else{
//        ll t = (1<<(pos));
//        for(int i = 0;i<t; i ++){
//            g[i+t] = g[t-i-1] ^t;
//        }
//    }
//    if(pos+1!=n){
//        grays(g,pos+1,n);
//    }
//}
//vector<ll> gray(ll n){
//    vector<ll> answer((1<<n));
//    grays(answer,0,n);
//    return answer;
//}
//
//ll am_bit(ll a){
//    ll answer = 0;
//    while(a){
//        answer+=a&1;
//        a>>=1;
//    }
//    return answer;
//}
//
//// m  - изначально сыгранный матчи нее пересекающиеся с нами
//bool win(ll mask,Dinic &dinic,vector<ll> &scores,vector<vector<ll>> &ma,ll n,ll m,ll z,vector<string> &for_per,map<string,ll> &lol,ll prev=0){
//    if(prev == 0 ){
//        ll am = 2 +z;
//        dinic.clear();
//        dinic.resize(am-2,am-1,am);
//        vector<ll> scores1 = scores;
//        for(int i =0 ; i < for_per.size() ; i ++){
//            if(mask& (1ll<<i)){
//                scores1[0]+=3;
//            }else{
//                scores1[lol[for_per[i]]]+=3;
//            }
//        }
//
//        for(int i = 1; i <n ; i++){
//            for(int j = i+1; j < n ; j++){
//                if(ma[i][j]!=-1){
//                    dinic.add_edge(am-2,ma[i][j],3);
//                    dinic.add_edge(ma[i][j],ma[i][i],3);
//                    dinic.add_edge(ma[i][j],ma[j][j],3);
//                }
//            }
//        }
//        for(int j = 1; j < n ; j ++){
//            if(scores1[0]-scores1[j]<=0){
//                return false;
//            }
//            dinic.add_edge(ma[j][j],am-1,scores1[0]-scores1[j]-1);
//        }
//        return dinic.flow()==3*dinic.adj[dinic.s].size();
//    }else{
//        for(int i = 0 ; i < for_per.size(); i ++){
//            if(((1ll<<i)&mask )&& !((1ll<<i)&prev )){
//                dinic.correct(dinic.t,i,for_per,ma);
//                break;
//            }
//        }
//        return dinic.flow()==3*dinic.adj[dinic.s].size();
//
//    }
//
//}
//ll answer =(1ll<<23)-1;
//bool brt(ll height,vector<vector<ll>> &per,Dinic &dinic,vector<ll> &scores,vector<vector<ll>> &ma,ll n,ll m,ll z,vector<string> &for_per,map<string,ll> &lol){
//    for(int i = 0 ; i < per[height].size() ; i ++){
//        if(win(per[height][i],dinic,scores,ma,n,m,z,for_per,lol)){
//            if(am_bit(per[height][i])<am_bit(answer)){
//                answer=per[height][i];
//            }
//            return true;
//        }
//    }
//    return false;
//}
//void match(vector<ll> & scores, vector<vector<ll>> &ma,map<string,ll> &lol,string & first,ll &cur){
//
//    string temp;
//    getline(cin,temp);
//
//    istringstream ss(temp);
//    int t = 0;
//    vector<string> input(10);
//    string a,b,score,fuck;
//    while(ss>>temp){
//        input[t++] = temp;
//    }
////    for(int i = 0 ; i < 4; i ++){
////        cout<<input[i]<<" ";
////    }
//    if(input[3]==""){
//        if(input[2][0]>input[2][2]){
//            scores[lol[input[0]]]+=3;
//        }else{
//            scores[lol[input[1]]]+=3;
//        }
//    }else{
//        if(input[2][0]>input[2][2]){
//            scores[lol[input[0]]]+=2;
//            scores[lol[input[1]]]+=1;
//        }else{
//            scores[lol[input[1]]]+=2;
//            scores[lol[input[0]]]+=1;
//        }
//    }
//    ma[lol[input[0]]][lol[input[1]]] = ma[lol[input[1]]][lol[input[0]]] =-1;
//    if(input[0]==first || input[1]==first){
//        cur++;
//    }
////    cout<<"\n";
//
//}

//struct mset {
//    multiset<ll> data;
//
//    void operator -=(const mset &a) {
//        for(auto e : a.data){
//            auto t = data.find(e);
//            if(t!=data.end()){
//                data.erase(t);
//            }
//        }
//    }
//    void operator +=(const mset &a){
//        for(auto e : a.data){
//            data.insert(e);
//        }
//    }
//};
//
//ll askMaMi(ll n,ll ma,ll z){
//    if(n==1||n==z)return ma;
//    cout<<"2 ";
//    for(int i = 1; i <= n;i++){
//        cout<<i<<" ";
//    }
//    cout<<"\n";
//    cout.flush();
//    ma = -1e15;
//    ll a;
//    for(int i = 0 ; i < n*(n-1)/2;i++){
//        cin>>a;
//        ma=max(ma,a);
//    }
//    return ma;
//}
//mset ask(vector<int> &arr){
//    cout<<"2 ";
//    for(int i = 0; i < arr.size();i++){
//        cout<<arr[i]<<" ";
//    }
//    cout<<"\n";
//    cout.flush();
//    mset answer;
//    ll a;
//    for(int i = 0 ; i < arr.size()*(arr.size()-1)/2;i++){
//        cin>>a;
//        answer.data.insert(a);
//    }
//    return answer;
//}
//mset F(vector<int> &q,int pos){
//    vector<int> arr =q;
//    arr.push_back(pos);
//    auto t = ask(arr);
//    t-=ask(q);
//    return t;
//}
//vector<pair<ll, ll>> factorize(ll x) {
//    vector<pair<ll, ll>> res;
//    for (ll i = 2; i * i <= x; i++) {
//        if (x % i == 0) {
//            int k = 0;
//            while (x % i == 0) {
//                x /= i;
//                k++;
//            }
//            res.push_back({i, k });
//        }
//    }
//    if (x != 1) {
//        res.push_back({x, 1});
//    }
//    return res;
//}

//ll get(string &a, ll base) {
//    ll answer = 0;
//    ll temp = 1;
//    for (int i = a.length() - 1; i >= 0; i--) {
//        ll k = (a[i] >= '0' && a[i] <= '9' ? a[i] - '0' : a[i] - 'A' + 10);
//        answer += temp * k;
//        temp *= base;
//    }
//    return answer;
//}
//
vector<ll> find_div(ll x) {
    vector<ll> answer;
    for (ll i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            answer.push_back(i);
            if (i*i!=x)
                answer.push_back(x / i);
        }
    }
    return answer;
}

//void dfs(ll node, vector<vector<ll>> &adj, vector<bool> &used, vector<ll> &color, ll c) {
//    used[node] = true;
//    color[node] = c;
//    for (auto e : adj[node]) {
//        if (!used[e]) {
//            dfs(e, adj, used, color, c);
//        }
//    }
//}
//
//vector<vector<ll>> adj;
//
//bool comp(const ll &a, const ll &b) {
//    return adj[a].size() < adj[b].size();
//}
//
//void solve() {
//    ll n;
//    cin >> n;
//    vector<pair<ll, ll>> edges(n);
//    map<pair<ll, ll>, ll> poses;
//    set<ll> temp;
//    for (int i = 0; i < n; i++) {
//        cin >> edges[i].first >> edges[i].second;
//        temp.insert(edges[i].first);
//        temp.insert(edges[i].second);
//
//    }
//    int k = 0;
//    vector<ll> nodes(temp.size());
//    map<ll, ll> pos;
//    for (auto e : temp) {
//        pos[e] = k;
//        nodes[k] = e;
//        k++;
//    }
//    for (int i = 0; i < edges.size(); i++) {
//        poses[{pos[edges[i].first], pos[edges[i].second]}] = i + 1;
//    }
//    n = nodes.size();
//    adj.clear();
//    adj.resize(n);
//    for (auto e : edges) {
//        adj[pos[e.first]].push_back(pos[e.second]);
//        adj[pos[e.second]].push_back(pos[e.first]);
//    }
//    ll am = 0;
//    vector<bool> used(n);
//    vector<ll> color(n);
//
//    for (int i = 0; i < n; i++) {
//        if (!used[i]) {
//            dfs(i, adj, used, color, am);
//            am++;
//        }
//    }
//    cout << am - 1 << "\n";
//    vector<vector<ll>> t(am);
//    for (int i = 0; i < n; i++) {
//        t[color[i]].push_back(i);
//    }
//
//    for (int i = 0; i < am; i++) {
//        sort(t[i].begin(), t[i].end(), comp);
//    }
//    for (int i = 0; i < am - 1; i++) {
//        ll was_to = t[i][0];
//        ll was = adj[was_to][0];
//        ll p;
//        if(poses[{was_to,was}]){
//            p = poses[{was_to,was}];
//        }else{
//            p  =poses[{was,was_to}];
//        }
//        ll to = t[i+1].back();
//        cout<<p<<" "<<nodes[was_to]<<" "<<nodes[to]<<"\n";
//    }
//
//}

bool is_prime(ll x) {
    for (ll i = 2; i * i <= x; i++) {
        if (x % i == 0)return false;
    }
    return true;
}
//
////const ll maxN = 1e7;
////bool b[maxN];
////vector<ll> primes;
////
////void sphene() {
////    for (ll i = 2; i < maxN; i++) {
////        if (!b[i]) {
////            primes.push_back(i);
////            for (ll j = i * i; j < maxN; j+=i) {
////                b[j]=true;
////            }
////        }
////    }
////}
//const ll maxN = 1e5 + 1000;
////struct wor {
////    ll mi = 1e17;
////    ll ma = -1e17;
////};
//ll t[4 * maxN];
//ll d[4 * maxN];

//wor merge(wor a, wor b) {
//    wor res;
//    res.mi = min(a.mi, b.mi);
//    res.ma = max(a.ma, b.ma);
//    return res;
//}

//void build(ll v, ll vl, ll vr, vector<ll> &arr) {
//    if (vl == vr) {
//        t[v] = arr[vl];
//        return;
//    }
//    ll m = vl + (vr - vl) / 2;
//    build(2 * v + 1, vl, m, arr);
//    build(2 * v + 2, m + 1, vr, arr);
//    t[v] = min(t[2 * v + 1], t[2 * v + 2]);
//}
//void push(ll v, ll vl, ll vr) {
//    if (d[v] >= 0) {
//        if (vl == vr) {
//            t[v] = d[v];
//            d[v] = -1;
//            return;
//        }
//        t[v] = (vr - vl + 1) * d[v];
//        d[2 * v + 1] = d[2 * v + 2] = d[v];
//        d[v] = -1;
//    }
//}

//ll query(ll v, ll vl, ll vr, ll l, ll r) {
//    if (vr < l || vl > r) {
//        return 1e18;
//    }
//    if (l <= vl && vr <= r) {
//        return t[v];
//    }
//    ll m = vl + (vr - vl) / 2;
//    return min(query(2 * v + 1, vl, m, l, r), query(2 * v + 2, m + 1, vr, l, r));
//
//}

//void update(ll v, ll vl, ll vr, ll l, ll r, ll val) {
//    push(v, vl, vr);
//    if (vr < l || vl > r) {
//        return;
//    }
//    if (l <= vl && vr <= r) {
//        d[v] = val;
//        push(v, vl, vr);
//        return;
//    }
//    ll m = vl + (vr - vl) / 2;
//    update(2 * v + 1, vl, m, l, r, val);
//    update(2 * v + 2, m + 1, vr, l, r, val);
//    t[v] = t[2 * v + 1] + t[2 * v + 2];
//}

//void modify(ll v, ll vl, ll vr, ll pos, ll val) {
//    if (vl == vr) {
//        t[v].mi = val;
//        t[v].ma = val;
//        return;
//    }
//    ll m = vl + (vr - vl) / 2;
//    if (pos <= m) {
//        modify(2 * v + 1, vl, m, pos, val);
//    } else {
//        modify(2 * v + 2, m + 1, vr, pos, val);
//    }
//    t[v] = merge(t[2 * v + 1], t[2 * v + 2]);
//}
//struct Node {
//    ll count = 0;
//    ll mi=1e18;
//    ll val=0;
//    ll y;
//    Node* left = null;
//    Node* right = null;
//};
//void recalc(Node *T){
//    if(T==null)return;
//    T->count =1;
//    T->mi =T->val;
//    if(T->left!=null){
//        T->count +=T->left->count;
//        T->mi = min(T->mi , T->left->mi);
//    }
//    if(T->right!=null){
//        T->count +=T->right->count;
//        T->mi = min(T->mi , T->right->mi);
//    }
//
//}
//Node * merge(Node* T1,Node *T2){
//    if(T1==null){
//        return T2;
//    }
//    if(T2==null){
//        return T1;
//    }
//    recalc(T1);
//    recalc(T2);
//    if(T2->y > T1->y){
//        T2->left=merge(T1,T2->left);
//        recalc(T2);
//        return T2;
//    }
//    else{
//        T1->right = merge(T1->right,T2);
//        recalc(T1);
//        return T1;
//    }
//}
//ll get_x(Node* T){
//    if(T->left==null){
//        return 0;
//    }
//    return T->left->count;
//}
//pair<Node*,Node*> split(Node *T,ll key){
//    if(T==null)return {null,null};
//    if(get_x(T)<=key){
//        auto e = split(T->right,key-get_x(T)-1);
//        recalc(e.first);
//        recalc(e.second);
//        T->right = e.first;
//        recalc(T);
//        return {T,e.second};
//    }else{
//        auto e = split(T->left,key);
//        recalc(e.first);
//        recalc(e.second);
//        T->left = e.second;
//        recalc(T);
//        return {e.first,T};
//    }
//
//}
//const ll maxN = 2e5+100;
//Node nodes[maxN];
//struct wor {
//    ll mi = 1e18;
//    ll ma = -1e18;
//};
//const ll maxN = 1e5 + 1000;
//wor t[4*maxN];
//
//
//void build(ll v, ll vl, ll vr, vector<ll> &arr) {
//    if (vl == vr) {
//        t[v].mi = arr[vl];
//        t[v].ma = arr[vl];
//        return;
//    }
//    ll m = vl + (vr - vl) / 2;
//    build(2 * v + 1, vl, m, arr);
//    build(2 * v + 2, m + 1, vr, arr);
//    t[v].mi = min(t[2 * v + 1].mi, t[2 * v + 2].mi);
//    t[v].ma = max(t[2 * v + 1].ma, t[2 * v + 2].ma);
//}
//
//void modify(ll v, ll vl, ll vr, ll pos, ll val) {
//    if (vl == vr) {
//        t[v].mi = val;
//        t[v].ma = val;
//        return;
//    }
//    ll m = vl + (vr - vl) / 2;
//    if (pos <= m) {
//        modify(2 * v + 1, vl, m, pos, val);
//    } else {
//        modify(2 * v + 2, m + 1, vr, pos, val);
//    }
//    t[v].mi = min(t[2 * v + 1].mi, t[2 * v + 2].mi);
//    t[v].ma = max(t[2 * v + 1].ma, t[2 * v + 2].ma);
//}

//wor query(ll v, ll vl, ll vr, ll l, ll r) {
//    if (vr < l || vl > r) {
//        return {(ll) (1e18), (ll) (-1e18)};
//    }
//    if (l <= vl && vr <= r) {
//        return t[v];
//    }
//    ll m = vl + (vr - vl) / 2;
//    return merge(query(2 * v + 1, vl, m, l, r), query(2 * v + 2, m + 1, vr, l, r));
//}
//ll query_min(ll v, ll vl ,ll vr, ll l ,ll r){
//    if(vl>r || vr<l){
//        return LONG_LONG_MAX;
//    }
//    if(l<=vl && vr<=r){
//        return t[v].mi;
//    }
//    ll m = vl + (vr-vl)/2;
//    return min(query_min(2*v+1,vl,m,l,r),query_min(2*v+2,m+1,vr,l,r));
//}
//ll query_max(ll v, ll vl ,ll vr, ll l ,ll r){
//    if(vl>r || vr<l){
//        return -LONG_LONG_MAX;
//    }
//    if(l<=vl && vr<=r){
//        return t[v].ma;
//    }
//    ll m = vl + (vr-vl)/2;
//    return max(query_max(2*v+1,vl,m,l,r),query_max(2*v+2,m+1,vr,l,r));
//}
ll sum(ll l, ll r, vector<ll> &pref) {
    return pref[r] - pref[l - 1];
}

ll fact(ll x) {
    if (x == 0)return 1;
    return x * fact(x - 1);
}
vector<ll> canon(ll x){
    vector<ll> answer;
    for(ll i =2 ; i*i<=x; i++){
        if(x%i==0){
            answer.push_back(i);
            while(x%i==0){
                x/=i;
            }
        }
    }
    if(x!=1){
        answer.push_back(x);
    }
    return answer;
}
int main() {
//    freopen("rvq.in", "r", stdin);
//    freopen("rvq.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    ll n;
//    for(int n = 1; n <=100; n++){
//        vector<int> arr(n+1);
//        ll z = 0;
//        for(int i = 1 ; i <= n ; i ++){
//            for(int  j = 1; j<i; j++){
//                if(abs(j-i) > 1 && n %(abs(j-i)) == 0){
//                    arr[i] = arr[j];
//                    break;
//                }
//            }
//            if(arr[i]==0){
//                z++;
//                arr[i]=z;
//            }
//        }
//        cout<<n<<" "<<z<<" "<<find_div(n).size()<<"\n";
//    }
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string a,b;
        cin>>a>>b;
        map<char,int> m;

        for(int i= 0 ; i < n ; i ++){
            m[a[i]]++;
            m[b[i]]++;
        }
        bool f = false;
        for(auto e : m){
            if(e.second %2==1){
                f=true;
            }
        }
        if(f){
            cout<<"No\n";
            continue;
        }
        cout<<"Yes\n";
        vector<pair<ll,ll>> answer;
        for(int i = 0 ; i < n-1 ; i ++){
            if(a[i]!=b[i]){
                bool f = false;
                for(int j = i+1; j < n && !f ; j++){
                    if(b[i] == b[j]){
                        answer.push_back({i,j});
                        swap(a[i],b[j]);
                        f=true;
                    }
                }
                if(!f){
                    for(int j = i+1; j < n && !f ; j++){
                        if(b[i] == a[j]){
                            answer.push_back({j,i+1});
                            swap(a[j],b[i+1]);
                            answer.push_back({i,i+1});
                            swap(a[i],b[i+1]);
                            f=true;
                        }
                    }
                }
            }
        }
        cout<<answer.size()<<"\n";
        for(auto e : answer){
            cout<<e.first+1<<" "<<e.second+1<<"\n";
        }
    }


    return 0;

}