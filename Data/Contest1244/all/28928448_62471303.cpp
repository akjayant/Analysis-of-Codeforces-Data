#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 10005
struct edge{
    int des; int next;
};

int cas; int n; char s[N]; int ans;

int main(){
    scanf("%d",&cas);
    while(cas--){
        scanf("%d",&n);
        ans=n;
        scanf("%s",s+1);
        for(int i=1;i<=n;++i){
            if(s[i]=='1') ans=max(ans, 2*max(i,n-i+1) );
        }
        printf("%d\n",ans);
    }
    return 0;
}













