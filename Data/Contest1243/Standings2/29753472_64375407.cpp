#include<bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<=c;a++)
#define per(a,b,c) for(int a=b;a>=c;a--)
#define pb push_back
#define mk make_pair
#define pii pair<int,int>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
typedef double db;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 5;
int n, m, k;
int a[N];

bool judge(int x){

    per(i,n,n-x+1) if(a[i] < x) return 0;
    return 1;
}

int main(){
    int T; scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        rep(i,1,n) scanf("%d", &a[i]);
        sort(a+1,a+1+n);
        int ans = n;
        for(; ans >= 1; ans--){
            if(judge(ans)) break;
        }
        printf("%d\n", ans);
    }
    //scanf("%d%d", &n, &m);

    return 0;
}
