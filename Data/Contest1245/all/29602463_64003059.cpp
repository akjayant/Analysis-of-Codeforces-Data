#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn=1e5+5;

char ch[maxn];
int a[maxn],ac[maxn];

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n+1;i++)ac[i]=0;
        int a1,a2,a3,b1,b2,b3;
        a1=a2=a3=0;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&b1,&b2,&b3);
        }
        scanf("%s",ch);
        for(int i=0;i<n;i++){
            if(ch[i]=='S')a1++;
            else if(ch[i]=='R')a2++;
            else a3++;
        }
        int ans=min(a1,b1)+min(a2,b2)+min(a3,b3);
        if(n-n/2<=ans){
            printf("YES\n");
            for(int i=0;i<n;i++){
                if(ch[i]=='S'){
                    if(b1){
                        b1--;
                        ac[i]=1;
                    }
                }
                else if(ch[i]=='R'){
                    if(b2){
                        b2--;
                        ac[i]=2;
                    }
                }
                else{
                    if(b3){
                        b3--;
                        ac[i]=3;
                    }
                }
            }
            for(int i=0;i<n;i++){
                if(ac[i]==0){
                    if(b1){
                        b1--;
                        ac[i]=1;
                    }
                    else if(b2){
                        b2--;
                        ac[i]=2;
                    }
                    else{
                        b3--;
                        ac[i]=3;
                    }
                }
            }
            for(int i=0;i<n;i++){
                if(ac[i]==1)printf("R");
                else if(ac[i]==2)printf("P");
                else printf("S");
            }
            printf("\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}
