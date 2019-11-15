#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
       int n;
       char arr[10101],brr[10101];
       int flag=0,cnt=0;
       pair <char,char> p;
       scanf("%d",&n);
       scanf("%s%s",arr,brr);
       int ans=1;
       for(int i=0;i<n;i++){
            if(arr[i]!=brr[i]){
                cnt++;
                if(cnt>2){
                    ans=0;
                    break;
                }
                if(!flag){
                    p={arr[i],brr[i]};
                    flag=1;
                }
                else{
                    flag=0;
                    if(p.first!=arr[i]||p.second!=brr[i])
                        ans=0;
                }
            }
       }
       if(ans&&!flag)puts("Yes");
       else puts("No");
    }
}
