#include <cstdio>
#include <algorithm>


using namespace std;

const int MAXN = 502;


int n;
char str[MAXN];

int count(){
    int d=0, md=1e9, mdc=0;
    for(int i=0;i<n;++i){
        if(str[i]=='('){
            d++;
        }else{
            d--;
        }
        if(d<md){
            md=d;
            mdc=1;
        }else if(d==md){
            mdc++;
        }
    }
    if(d) return 0;
    return mdc;
}

int main(){
    scanf("%d", &n);
    scanf("%s", str);
    int sol=0, s1=0, s2=0;
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            swap(str[i], str[j]);
            int tmp = count();
            if(tmp>sol){
                sol=tmp;
                s1=i;
                s2=j;
            }
            swap(str[i], str[j]);
        }
    }
    printf("%d\n%d %d\n", sol, s1+1, s2+1);
}
