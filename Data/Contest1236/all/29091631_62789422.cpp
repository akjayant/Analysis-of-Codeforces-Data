#include<bits/stdc++.h>
using namespace std;
mt19937 rng(0);
typedef long long ll;
const ll mod=1e9+7;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        int op=0;
        for(int i=0;i<=min(a,b/2);i++){
            op=max(op,i+min(b-i*2,c/2));
        }
        printf("%d\n",op*3);
    }
}