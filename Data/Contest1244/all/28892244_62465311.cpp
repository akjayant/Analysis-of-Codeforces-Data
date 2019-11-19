#include <bits/stdc++.h>
using namespace std;
int t,a,b,c,d,k;
int ok=0;
int main()
{
    cin>>t;
    while(t--){
        cin>>a>>b>>c>>d>>k;
        ok=0;
        for(int i=0;i<=k;i++){
            if(i*c>=a && (k-i)*d>=b){
                ok=1;
                printf("%d %d\n",i,k-i);
                break;
            }
        }
        if(!ok){
            printf("-1\n");
        }
    }
    return 0;
}
