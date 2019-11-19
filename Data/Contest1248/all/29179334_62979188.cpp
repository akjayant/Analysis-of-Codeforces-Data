#include<bits/stdc++.h>
#include<set>
using namespace std;
typedef long long ll;
#define pb push_back
#define ull unsigned long long
#define mp make_pair
const int maxn=1e5+5;
const ll inf=1e9+7;
ll mod=1e9+7;
inline int read() {
    char ch = getchar(); int x = 0, f = 1;
    while(ch < '0' || ch > '9') {
        if(ch == '-') f = -1;
        ch = getchar();
    } while('0' <= ch && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    } return x * f;
}
int n,m;

int main(){
    int T;
    cin>>T;
    while(T--){
        ll cnt[4]={0,0,0,0};
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            if(x&1)cnt[1]++;
            else cnt[0]++;
        }

        scanf("%d",&m);
        for(int i=1;i<=m;i++){
            int x;
            scanf("%d",&x);
            if(x&1)cnt[3]++;
            else cnt[2]++;
        }

        printf("%I64d\n",cnt[0]*cnt[2]+cnt[1]*cnt[3]);
    }


    return 0;
}

/*

*/
