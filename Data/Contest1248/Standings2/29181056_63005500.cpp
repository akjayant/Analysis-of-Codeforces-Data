#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <fstream>
#include <math.h>
#include <queue>
#include <bitset>
#include <cmath>
#include <complex>
#include <iomanip>
#include <valarray>
#include <stack>
#include <cstring>

using namespace std;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef long long ll;
typedef vector<ull> vull;
typedef set<string> ss;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<int, ii> iii;
typedef pair<ii, ii> iiii;
typedef vector<iii> viii;
typedef vector<viii> vviii;
typedef vector<vii> vvii;
typedef vector<string> vs;
typedef map<string, int> msi;
typedef multiset<int> mlsi;
typedef set<ii> sii;
typedef map<int, ii> mii;
typedef pair<string, int> psi;
typedef queue<int> qi;
typedef pair<int, vi> pivi;
typedef vector<pivi> vpivi;
typedef pair<int, ii> iii;
typedef vector<iii> viii;
typedef pair<int, bool> ib;
typedef vector<ib> vib;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<vib> vvib;
typedef set<int> si;
typedef pair<bool, bool> bb;
typedef long long ll;
typedef pair<ll, ll>pll;
typedef vector<ll>vll;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;
typedef vector<vll> vvll;
typedef pair<int, string> pis;
typedef vector<pair<int, string>> vpis;



#define PI 3.14159265

/* ii;
class SegTree {
public:
   vii A;
   vi st;
   int n;
 
   int left(int i) {
       return (i << 1);
   }
 
   int right(int i) {
       return (i << 1) + 1;
   }
 
   void build(int p, int L, int R) {
       if (L == R)
           st[p] = L;
       else {
           build(left(p), L, (L + R) / 2);
           build(right(p), (L + R) / 2 + 1, R);
           int p1 = st[left(p)];
           int p2 = st[right(p)];
           st[p] = A[p1].second <= A[p2].second ? p1 : p2;
       }
   }
 
   SegTree(const vii &_A) {
       A = _A;
       n = _A.size();
       st.assign(4 * n, -1);
       build(1, 0, n - 1);
   }
 
   int rmq(int p, int L, int R, int i, int j) {
       if (i > R || j < L) return -1;
       if (L >= i && R <= j) return st[p];
       int p1 = rmq(left(p), L, (L + R) / 2, i, j);
       int p2 = rmq(right(p), (L + R) / 2 + 1, R, i, j);
       if (p1 == -1) return p2;
       if (p2 == -1) return p1;
 
       return (A[p1].second <= A[p2].second ? p1 : p2);
   }
 
   int rmq(int i, int j) {
       return rmq(1, 0, n - 1, i, j);
   }
 
   int getIndex(int p, int L, int R, int pos) {
       if (L == R) return p;
       if (pos <= (L + R) / 2) return getIndex(left(p), L, (L + R) / 2, pos);
       return getIndex(right(p), (L + R) / 2 + 1, R, pos);
   }
 
   void update(int pos, int value) {
       A[pos].second = value;
       pos = getIndex(1, 0, n - 1, pos);
       pos /= 2;
 
       while (pos != 0) {
           int p1 = st[left(pos)];
           int p2 = st[right(pos)];
 
           if (p1 >= 0 && p2 >= 0)
               st[pos] = A[p1].second <= A[p2].second ? p1 : p2;
           pos /= 2;
       }
   }
};
 */


class SegTree {
public:
    vll A;
    vll st;
    int n;

    int left(int i) {
        return (i << 1);
    }

    int right(int i) {
        return (i << 1) + 1;
    }

    void build(int p, int L, int R) {
        if (L == R)
            st[p] = L;
        else {
            build(left(p), L, (L + R) / 2);
            build(right(p), (L + R) / 2 + 1, R);
            int p1 = st[left(p)];
            int p2 = st[right(p)];
            st[p] = A[p1] >= A[p2] ? p1 : p2;
        }
    }

    SegTree(const vll &_A) {
        A = _A;
        n = _A.size();
        st.assign(4 * n, -1);
        build(1, 0, n - 1);
    }

    int rmq(int p, int L, int R, int i, int j) {
        if (i > R || j < L) return -1;
        if (L >= i && R <= j) return st[p];
        int p1 = rmq(left(p), L, (L + R) / 2, i, j);
        int p2 = rmq(right(p), (L + R) / 2 + 1, R, i, j);
        if (p1 == -1) return p2;
        if (p2 == -1) return p1;

        return (A[p1] >= A[p2] ? p1 : p2);
    }

    int rmq(int i, int j) {
        if (i < 0)
            i = 0;

        return rmq(1, 0, n - 1, i, j);
    }

    int getIndex(int p, int L, int R, int pos) {
        if (L == R) return p;
        if (pos <= (L + R) / 2) return getIndex(left(p), L, (L + R) / 2, pos);
        return getIndex(right(p), (L + R) / 2 + 1, R, pos);
    }

    void update(int pos, int value) {
        A[pos] = value;
        pos = getIndex(1, 0, n - 1, pos);
        pos /= 2;

        while (pos != 0) {
            int p1 = st[left(pos)];
            int p2 = st[right(pos)];

            if (p1 >= 0 && p2 >= 0)
                st[pos] = A[p1] >= A[p2] ? p1 : p2;
            pos /= 2;
        }
    }
};

class UnionFind {
public:
    vi rank;
    vii p;

    UnionFind(int N) {
        rank.assign(N, 0);
        p.assign(N, ii(0, 1));
        for (int i = 0; i < N; i++) p[i].first = i;
    }

    int findSet(int i) {
        return (p[i].first == i) ? i : (p[i].first = findSet(p[i].first));
    }

    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }

    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) {
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) {
                p[y].first = x;
                p[x].second += p[y].second;
            } else {
                p[x].first = y;
                p[y].second += p[x].second;
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
    }

    int getMaxId() {
        int maxIn = 0;
        for (int i = 0; i < p.size(); i++)
            if (p[i].second > p[maxIn].second)
                maxIn = i;

        return maxIn;
    }

    int getNum() {
        si par;

        for (int i = 0; i < p.size(); i++)
            par.insert(p[i].first);
        return par.size();
    }

};

string getString(char x) {
    // string class has a constructor 
    // that allows us to specify size of 
    // string as first parameter and character 
    // to be filled in given size as second 
    // parameter. 
    string s(1, x);

    return s;
}

ull cost[4][4];
char dna[5] = {'A', 'T', 'C', 'G', '?'};
int n, k, m;
vvi rels;
vpis ls;
bool isl[10003];
ull dp[10003][203][4];
int par[10003];

bool comp(pis a, pis b) {
    return a.first < b.first;
}

void dfs(int u) {
    if (isl[u]) return;
    for (int j = 0; j < rels[u].size(); j++) {
        int v = rels[u][j];
        if (v == par[u]) continue;
        par[v] = u;
        dfs(v);
    }



    for (int i = 0; i < m; i++) {
        for (int k = 0; k < 4; k++) {
            ull c = 0;
            for (int j = 0; j < rels[u].size(); j++) {
                int v = rels[u][j];
                if (v == par[u]) continue;

                ull mn = (1ull << 60);
                for (int t = 0; t < 4; t++) {
                    ull tmp = dp[v][i][t] + cost[k][t];
                    mn = min(mn, tmp);
                }
                c += mn;
            }
            dp[u][i][k] = c;
        }
    }


}

int get(string str , int n){
    int dp[n];
    int arr[n];
    
    for(int i=0 ; i<n ; i++)
        if(str[i] == '(') arr[i] = 1;
        else arr[i] = -1;
    
    dp[0] = arr[0];
    for(int i=1 ; i<n ; i++) dp[i] = dp[i-1] + arr[i];

    int mn = (1<<30);
    for(int i=0 ; i<n ; i++) mn = min(mn , dp[i]);
    
    
    int dpr[n];
    dpr[0] = arr[n-1];
    for(int i=1 ; i<n ;i++) dpr[i] = dpr[i-1] + arr[n-i-1];
    
    if(dp[n-1] != 0) return 0;

    int res =0 ;
    for(int i=0 ; i<n ; i++)
        if(dpr[i] + mn >=0) res ++;
    
    return res;
} 

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  
    int n;
    cin >> n;
    string str;
    cin >> str;
    
    int tt = get("()()()()()" , 10);
    
    int res = -1;
    
    int l , r;
    for(int i=0 ; i<n  ; i++)
           for(int j=0 ; j<n ; j++){
            string tmp;
            tmp = str;
            char a = str[i];
            char b = str[j];
            tmp[i] = b;
            tmp[j] = a;
            int cur = get(tmp , n);
            if(cur > res){
                res = cur;
                l = min(i , j);
                r = max(i , j);
            }
        }
    
    printf("%d\n%d %d" , res , l+1 , r+1);
}


























