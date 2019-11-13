#include <bits/stdc++.h>

using namespace std;

int ase[1003];

int main(){
    
    int t;
    scanf("%d",&t);
    
    for(int i = 1; i<=t; ++i){
        int n;
        scanf("%d",&n);
        memset(ase,0,sizeof(ase));
        for(int k = 1; k<=n; ++k){
            int sz;
            scanf("%d",&sz);
            ase[sz]++;
        }
        for(int k = n; k>=1; --k){
            ase[k] = ase[k]+ase[k+1];
            //printf("%d: %d\n",k,ase[k]);
        }
        int ans = -1;
        for(int k = n; k>=1; --k){
            if(ase[k]>=k){
                ans = k;
                break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}