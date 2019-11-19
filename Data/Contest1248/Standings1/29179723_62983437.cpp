#include <cstdio>
#include <algorithm>


using namespace std;

const int MAXN = 100005;

int n;
int a[MAXN];

int main(){
    scanf("%d", &n);
    for(int i=0;i<n;++i){
        scanf("%d", &a[i]);
    }
    sort(a, a+n);
    long long dx=0, dy=0;
    for(int i=0;i<n/2;++i){
        dx+=a[i];
    }
    for(int i=n/2;i<n;++i){
        dy+=a[i];
    }
    printf("%lld\n", dx*dx+dy*dy);
}
