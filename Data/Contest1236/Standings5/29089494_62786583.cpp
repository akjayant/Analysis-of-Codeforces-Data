#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 2e5+10;
int main() {
    int t;
    scanf("%d",&t);
    int a,b,c;
    while(t--){
        scanf("%d%d%d",&a,&b,&c);
        int ans=0;
        int sumc=c/2;
        if(sumc>=b){
            ans=b;
        }else{
            ans=sumc+min(a,(b-sumc)/2);
        }
        printf("%d\n",ans*3);
    }
    //freopen("in.txt","r",stdin);
    return 0;
}
