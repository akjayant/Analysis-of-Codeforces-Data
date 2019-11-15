#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <stack>
#define ls root<<1
#define rs root<<1|1
using namespace std;
const int maxn=1e5+7;
const double eps=1e-6;
typedef long long ll;
char arr[maxn],ans[maxn];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b,c;//R,P,S
        int n;
        memset(ans,0,sizeof ans);
        scanf("%d",&n);
        scanf("%d%d%d",&a,&b,&c);
        int r=0,p=0,s=0;
        scanf("%s",arr);
        int num=0;
        for(int i=0;i<n;i++){
            if(arr[i]=='R'){
                if(b){
                    b--;
                    ans[i]='P';
                    num++;
                }
            }
            if(arr[i]=='P'){
                if(c){
                    ans[i]='S';
                    num++;
                    c--;
                }
            }
            if(arr[i]=='S'){
                if(a){
                    ans[i]='R';
                    num++;
                    a--;
                }
            }
        }
        if(num>=(n+1)/2){
            printf("YES\n");
            //printf("%s\n",ans);
            //cout<<a<<' '<<b<<' '<<c<<endl;
            for(int i=0;i<n;i++){
                if(ans[i]=='P' || ans[i]=='R' || ans[i]=='S'){
                    printf("%c",ans[i]);
                }
                else {
                    if(a) printf("R"),a--;
                    else if(b) printf("P"),b--;
                    else if(c) printf("S"),c--;
                }

            }
            printf("\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}
