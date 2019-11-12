#include<bits/stdc++.h>
using namespace std;
char a[10010],b[10010];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        int len;
        scanf("%d",&len);
        scanf("%s",a);
        scanf("%s",b);
        vector<int>pos;
        for(int i=0;i<len;i++){
            if(a[i]!=b[i]){
                pos.push_back(i);
            }
        }
        if(pos.size()>=3||pos.size()==1){
            puts("No");
        }
        else if(pos.size()==0){
            puts("Yes");
        }
        else{
            int fipos=pos[0],sepos=pos[1];
            char A=a[fipos],B=a[sepos],C=b[fipos],D=b[sepos];
            if(A==B&&C==D)puts("Yes");
            else puts("No");
        }
    }
}
