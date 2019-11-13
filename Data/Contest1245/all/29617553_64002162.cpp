#include<bits/stdc++.h>
#define ll long long
#define zp push_back
#define zm make_pair
#define zl lower_bound
#define z1 first
#define z2 second
using namespace std;
int z(){int z;scanf("%d",&z);return z;}
int Z(){long long Z;scanf("%I64d", &Z);return Z;}

const int M = 1e5+5;
int n;
char c[300], d[300];

void work(){
    int T;scanf("%d", &T);
    int a, b, C;
    while(T --){
        scanf("%d%d%d%d", &n, &a, &b, &C);
        scanf("%s", c+1);
        multiset<char> S;
        while(a --) S.insert('R');
        while(b --) S.insert('P');
        while(C --) S.insert('S');
        memset(d, 0, sizeof d);
        int num = 0;
        for(int i=1;i<=n;i++){
            if(c[i]=='S' && S.count('R')){
                d[i] = 'R';S.erase(S.find('R'));num ++;
            }
            if(c[i]=='R' && S.count('P')){
                d[i] = 'P';S.erase(S.find('P'));num++;
            }
            if(c[i]=='P' && S.count('S')){
                d[i] = 'S';S.erase(S.find('S'));num++;
            }
        }
        for(int i=1;i<=n;i++){
            if(d[i]==0){
                d[i] = *S.begin();
                S.erase(S.begin());
            }
        }
        if(num>=(n+1)/2){
            puts("YES");
            puts(d+1);
        }else{
        puts("NO");}
    }
}

int main(){
    work();
}
