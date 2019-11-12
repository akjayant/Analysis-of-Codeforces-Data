#include<bits/stdc++.h>
using namespace std;
int n;
char a[10007],b[10007];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%s%s",&n,a,b);
        int ii,jj,bz=0;
        for(int i=0;i<n;i++){
            if(a[i]!=b[i]){
                bz++;
                if(bz==1)ii=i;
                if(bz==2)jj=i;
            }
        }
        if(bz==0||bz==2&&a[ii]==a[jj]&&b[jj]==b[ii]){
            puts("Yes");
        }
        else{
            puts("No");
        }
    }
}