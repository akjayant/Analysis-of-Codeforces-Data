#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int int64_t
#define F first
#define S second

using namespace std;
using namespace __gnu_pbds;
const int N = 1e5+5;
const int INF = 1e18+7;
const int MOD = 1e9+7;
typedef tree<int, null_type, less<int>,rb_tree_tag,tree_order_statistics_node_update> SET; // *find_by_order(), order_of_key()

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
//    freopen("diet.in","r",stdin);
//    freopen("diet.out","w",stdout);
//    setlocale(LC_ALL,"russian");
//    clock_t StartTime = clock();
//    cout<<"Time = "<<(long double)(clock()-StartTime)/CLOCKS_PER_SEC;
    int n;
    cin>>n;
    deque<int> v;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        v.push_back(x);
    }
    sort(v.rbegin(),v.rend());
    queue<int> q1,q2;
    int tt=1;
    for(int i=0;i<n;i++){
        if(tt){
            q1.push(v.front());
            v.pop_front();
        }else{
            q2.push(v.back());
            v.pop_back();
        }
        tt^=1;
    }
    int x=0,y=0;
    int t=1;
    for(int i=0;i<n;i++){
        if(t==1){
            x+=q1.front();
            q1.pop();
        }else{
            y+=q2.front();
            q2.pop();
        }
        t^=1;
    }
    cout<<(x)*(x)+(y)*(y)<<endl;
}
