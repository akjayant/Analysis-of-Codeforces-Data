///not today

#include<bits/stdc++.h>
using namespace std;

#define SZ(x) (int)(x).size()
#define pb push_back
#define ll long long
#define xmax(x, y) (x) = max((x), (y))
#define xmin(x, y) (x) = min((x), (y))
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<long long, long long>
#define int long long
#define pipii pair<int, pair<int, int> >
#define pf push_front

const int maxn = 1000* 100 + 5;
set <int> aj[maxn], s;
queue <int> q;
vector <int> vec;

int32_t main(){
    int n, m;
    cin >>n >>m;
    for(int i = 0; i < m; i ++){
        int u, v;
        scanf("%lld%lld", &u, &v);
//        cin >>u >>v;
        u --;
        v --;
        aj[u].insert(v);
        aj[v].insert(u);
    }
    int ans = 0;
    for(int i = 0; i < n; i ++){
        s.insert(i);
    }
    while(SZ(s)){
        q.push(*s.begin());
        ans ++;
        s.erase(s.begin());
        while(SZ(q)){
            int v = q.front();
            q.pop();
            for(set <int> :: iterator it = s.begin(); it != s.end(); it ++){
                int u = *it;
                if(aj[v].find(u) == aj[v].end()){
                    vec.pb(u);
                }
            }
            for(int i = 0; i < SZ(vec); i ++){
                s.erase(s.find(vec[i]));
                q.push(vec[i]);
            }
            vec.clear();
        }
    }
    cout <<ans - 1 <<endl;
    return false;
}
