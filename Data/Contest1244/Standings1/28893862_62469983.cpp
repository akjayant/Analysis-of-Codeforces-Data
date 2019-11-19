#include <bits/stdc++.h>
#define F first
#define S second
#define all(a) a.begin(),a.end()
#define setDP(arr) memset(arr,-1,sizeof arr)
#define oo 2000000000
#define inf 1000000000000000LL
#define M 1000000007
typedef long long ll;
using namespace std;
const int N = 305001;

int t;
int n;
char s[N];
vector<int> v;
signed main(){
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif
    cin >> t;
    while(t--){
        scanf("%d %s",&n,s);
        v.clear();
        for(int i = 0 ; i < n ; i++){
            if(s[i]=='1')v.push_back(i);
        }
        if(v.size()==0){
            printf("%d\n",n);
            continue;
        }
        int ans = (n+v.back()-v[0]+1);
        ans = max(ans,(n-v[0])*2);
        ans = max(ans,(v.back()+1)*2);
        printf("%d\n",ans);

    }



    return 0;
}
