#include <bits/stdc++.h>


#define mkp(i,j) make_pair(i,j)
#define int long long
#define _sz(x) (int)x.size()

using namespace std;
typedef long long ll;
const int MAX = 1e5 + 10;
const int LOGMAX = 105;
const int inf = 1e9;
const int md = 1e9 + 7;
typedef pair < int , int > ii;


int32_t main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int a[n];
        for(int i = 0;i<n;i++){
            cin>>a[i];
        }
        sort(a , a+n);
        reverse(a, a+n);
        int ans = 1;
        for(int i = 0;i<n;i++){
            if(a[i] < ans) break;
            ans++;
        }
        cout<<ans - 1<<endl;
    }

    return 0;

}
