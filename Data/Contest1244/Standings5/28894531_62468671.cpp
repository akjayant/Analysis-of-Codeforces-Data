#include <cstdio>
#include <string.h>
#include <algorithm>
# define ll long long
using namespace std;
int n,m;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b,c,d,k;
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
        int x1=a/c;
        int x2=b/d;
        if(b%d){
            x2++;
        }
        if(a%c){
            x1++;
        }
        if(x1+x2<=k){
            printf("%d %d\n",x1,x2);
        }
        else{
            printf("-1\n");
        }
    }
}
