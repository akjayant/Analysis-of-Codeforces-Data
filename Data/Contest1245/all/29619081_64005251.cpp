#include <cstdio>

using namespace std;

const int MAXN = 100005;
const int MOD = 1e9+7;

char str[MAXN];
int sol[MAXN];

int ADD(long long a, long long b){
    return (a+b)%MOD;
}

int main(){
    scanf("%s", str);
    sol[0]=1;
    int i;
    for(i=1;str[i-1];++i){
        if(str[i-1]=='m' || str[i-1]=='w'){
            puts("0");
            return 0;
        }
        sol[i]=sol[i-1];
        if(i>=2 && str[i-1]=='u' && str[i-2]=='u') sol[i]=ADD(sol[i], sol[i-2]);
        if(i>=2 && str[i-1]=='n' && str[i-2]=='n') sol[i]=ADD(sol[i], sol[i-2]);
    }
    printf("%d\n", sol[i-1]);
}
