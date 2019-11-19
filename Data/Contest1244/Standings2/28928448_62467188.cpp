#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 100005
struct edge{
    int des; int next;
};

int cas;
int a; int b; int c; int d; int k;

int main(){
    scanf("%d",&cas);
    while(cas--){
        scanf("%d %d %d %d %d",&a,&b,&c,&d,&k);
        int sum=(int)ceil(1.0*a/c)+(int)ceil(1.0*b/d);
        if(k<sum) printf("-1\n");
        else{
            printf("%d %d\n",(int)ceil(1.0*a/c),(int)ceil(1.0*b/d));
        }
    }
    return 0;
}













