#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<stdlib.h>
using namespace std;

int t,n;
char a[50+5];
char b[50+5];

int main(){
    scanf("%d",&t);
    while(t--){
        bool flag=true;
        int occ[26+5];
        memset(occ,0,sizeof(occ));
        scanf("%d",&n);
        scanf("%s%s",a+1,b+1);
        for(int i=1;i<=n;i++){
            int pos=a[i]-'a'+1;
            occ[pos]++;
            pos=b[i]-'a'+1;
            occ[pos]++;
        }
        for(int i=1;i<=26;i++){
            if(occ[i]%2==1)flag=false;
        }

        if(flag){
            int lenans=0;
            struct node{int x;int y;};
            node ans[100+5];
            for(int i=1;i<=n-1;i++){
                if(a[i]!=b[i]){
                    int pos=0;

                    for(int j=i+1;j<=n;j++){//找上方一致
                        if(a[i]==a[j]){pos=j;break;}
                    }
                    if(pos){
                        char temp=a[pos];
                        a[pos]=b[i];
                        b[i]=temp;
                        ans[++lenans].x=pos;
                        ans[lenans].y=i;
                    }else{
                        for(int j=i+1;j<=n;j++){//找下方一致
                            if(a[i]==b[j]){pos=j;break;}
                        }
                        char temp=a[i+1];
                        a[i+1]=b[pos];
                        b[pos]=temp;
                        ans[++lenans].x=i+1;
                        ans[lenans].y=pos;

                        temp=a[i+1];
                        a[i+1]=b[i];
                        b[i]=temp;
                        ans[++lenans].x=i+1;
                        ans[lenans].y=i;
                    }
                }
            }
            printf("Yes\n");
            printf("%d\n",lenans);
            for(int i=1;i<=lenans;i++){
                printf("%d %d\n",ans[i].x,ans[i].y);
            }
        }else{
            printf("No\n");
        }
    }
    return 0;
}
