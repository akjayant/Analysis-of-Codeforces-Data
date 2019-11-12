#include <bits/stdc++.h>

using namespace std;

char s[100005],t[100005];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,num=0;
        char ss,tt;
        scanf("%d",&n);
        scanf("%s",s);
        scanf("%s",t);
        for(int i=0;i<n;i++){
            if(s[i]!=t[i]){
                ss=s[i];
                tt=t[i];
                num++;
            }
        }
        if(num==2){
            for(int i=0;i<n;i++){
                if(s[i]!=t[i]){
                    if(s[i]==ss&&t[i]==tt){
                        printf("Yes\n");
                    }
                    else{
                        printf("No\n");
                    }
                    break;
                }
            }
        }
        else printf("No\n");
    }
    return 0;
}
