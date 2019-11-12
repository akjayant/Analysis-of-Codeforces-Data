#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

const int maxn=100;
char a[maxn];
char b[maxn];
int num1[maxn];
int num2[maxn];
int cnt;

int num[30];

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        getchar();
        scanf("%s%s",a,b);

        for(int i=0;i<26;i++)num[i]=0;
        for(int i=0;i<n;i++){
            num[a[i]-'a']++;
            num[b[i]-'a']++;
        }
        int o=0;
        for(int i=0;i<26;i++){
            if(num[i]%2==1){
                o=1;
            }
        }
        if(o){
            printf("No\n");
            continue;
        }
        else printf("Yes\n");

        cnt=0;
        for(int i=0;i<n;i++){
            if(a[i]!=b[i]){
                int jj=-1;
                for(int j=i+1;j<n;j++){
                    if(a[j]==a[i]){
                        jj=j;
                        //printf("%d ...",jj);
                        break;
                    }
                }
                if(jj!=-1){
                    swap(a[jj],b[i]);
                    num1[cnt]=jj;
                    num2[cnt]=i;
                    cnt++;
                }else{
                    for(int j=i+1;j<n;j++){
                        if(b[j]==a[i]){
                            jj=j;
                            break;
                        }
                    }
                    swap(a[i+1],b[jj]);
                    num1[cnt]=i+1;
                    num2[cnt]=jj;
                    cnt++;
                    swap(a[i+1],b[i]);
                    num1[cnt]=i+1;
                    num2[cnt]=i;
                    cnt++;
                }
            }
        }
        printf("%d\n",cnt);
        for(int i=0;i<cnt;i++){
            printf("%d %d\n",num1[i]+1,num2[i]+1);
        }
    }
    return 0;
}