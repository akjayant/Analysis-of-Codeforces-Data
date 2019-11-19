#include <cstdio>


using namespace std;


int main(){
    int tcc;
    scanf("%d", &tcc);
    for(int tc=0;tc<tcc;++tc){
        int n,m;
        scanf("%d", &n);
        long long a[2] = {0,0};
        for(int i=0;i<n;++i){
            int x;
            scanf("%d", &x);
            a[x%2]++;
        }
        scanf("%d", &m);
        long long b[2] = {0,0};
        for(int i=0;i<m;++i){
            int x;
            scanf("%d", &x);
            b[x%2]++;
        }
        printf("%lld\n", a[1]*b[1]+a[0]*b[0]);
    }

}
