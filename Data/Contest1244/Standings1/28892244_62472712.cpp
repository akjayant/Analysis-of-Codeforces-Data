#include <bits/stdc++.h>
using namespace std;
int T,l;
string a;
int main()
{
    scanf("%d",&T);
    while(T--){
        scanf("%d",&l);
        cin>>a;
        int sol=0;
        for(int i=0;i<l;i++){
            if(a[i]=='1'){
                sol=max(sol,max(2*(i+1),2*(l-i)));
            }
        }
        if(sol==0){
            printf("%d\n",l);
        }
        else{
            printf("%d\n",max(sol,l+1));
        }
    }

    return 0;
}
