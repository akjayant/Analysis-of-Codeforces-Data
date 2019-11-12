#include<bits/stdc++.h>
#define ll long long
using namespace std;

char s1[10100];
char s2[10100];
int main() {
    int k; scanf("%d",&k);
    while(k--){
        int n;
        scanf("%d",&n);
        scanf("%s",s1);
        scanf("%s",s2);
        int num=0;
        char a1,a2;
        char c1,c2;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                num++;
                if(num==1){
                    a1=s1[i];
                    c1=s2[i];
                }
                if(num==2){
                    a2=s1[i];
                    c2=s2[i];
                }
                
            }
        }
        if(num!=2) {
            printf("No\n");
            continue;
        }else{
            if(a1!=a2 || c1!=c2){
                printf("No\n");
                continue;
            }
            else{
                printf("Yes\n");
                continue;
            }
        }
    }
    return 0;
}