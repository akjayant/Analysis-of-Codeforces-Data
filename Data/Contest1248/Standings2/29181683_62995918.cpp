#include <iostream>
#include <vector>
#include <algorithm>
#include<cstring>
#include <cmath>

using namespace std;
#define  fr(i,x,y) for(int i=x;i<=y;i++)

typedef  long  long ll;
#define  N 100005

#define ms(x,y) memset(x,y,sizeof(x));
vector<int > aa;
int m,n;
int a[N],b[N];

void doit() {
    scanf("%d", &n);
    int x=0,y=0;
    fr(i, 1, n){
        scanf("%d", &a[i]);
        if (a[i] % 2 == 0)x++;
    }

    scanf("%d",&m);
    fr(i,1,m ) {
        scanf("%d", &b[i]);
        if (b[i] % 2 == 0)y++;
    }
    ll ans=ll(x)*y+ll(n-x)*(m-y);
    printf("%lld\n",ans);

}
int main(){
    int cas;
    scanf("%d",&cas);
    while (cas--)
        doit();
}