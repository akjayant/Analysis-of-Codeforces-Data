#include<bits/stdc++.h>
using namespace std;
int n,Q;
int main(){
    scanf("%d",&Q);
    while (Q--){
        scanf("%d",&n);
        long long a,b,c,d;
        a=b=c=d=0;
        for (int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            if (x&1)a++;
            else b++;
        }
        scanf("%d",&n);
        for (int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            if (x&1)c++;
            else d++;
        }
        cout<<a*c+b*d<<endl;
    }
    return 0;
}