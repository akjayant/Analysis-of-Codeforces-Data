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
    int q;
    cin>>q;
    while(q--){
        int n;
        cin>>n;
        int t1=0,t2=0;
        for(int i=0;i<n;i++){
            int x; cin>>x;
            if(x%2==0) t1++;
            else t2++;
        }
        int m;
        cin>>m;
        int t3=0,t4=0;
        for(int i=0;i<m;i++){
            int x; cin>>x;
            if(x%2==0) t3++;
            else t4++;
        }
        int ans=t1*t3+t2*t4;
        cout<<ans<<endl;
    }
}
