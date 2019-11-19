#include <bits/stdc++.h>
using namespace std;

int t;
int n;
int ans;
char s[1009];

int main(){
    scanf("%d\n",&t);
    while(t--){
        scanf("%d\n",&n);
        scanf("%s",s);
        int mm=0;
        bool has=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                mm=max(mm,max(i,n-i-1));
                has=1;
            }
        }
        if(has==0) printf("%d\n",n);
        else printf("%d\n",2+mm*2);
    }
    return 0;
}
