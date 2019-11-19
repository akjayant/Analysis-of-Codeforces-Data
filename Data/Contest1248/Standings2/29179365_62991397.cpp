#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>

#define pb push_back
#define mp make_pair
#define taskname "A"

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef tree <int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const int maxn = 3e5 + 5;
const int mod = 1e9 + 7;
int n , m;
int Fib(int n , int a , int b){
    for(int i = 2 ; i <= n ; ++i){
        int c = (a + b) % mod;
        b = a;
        a = c;
    }
    return a;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(taskname".INP","r")){
        freopen(taskname".INP", "r",stdin);
        freopen(taskname".OUT", "w",stdout);
    }
    cin >> n >> m;
    cout << ((ll)Fib(n , 2 , 2) + Fib(m , 2 , 2) - 2 + mod) % mod;
}
