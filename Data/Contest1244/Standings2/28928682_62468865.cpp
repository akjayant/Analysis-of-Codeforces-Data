#include<bits/stdc++.h>
using namespace std;
#define maxn 1008
int t;
char ch[maxn];
int main(){
    scanf("%d",&t);
    while(t--){
        int n;scanf("%d",&n);
        scanf("%s",ch+1);
        int ans=n;
        for(int i=1;i<=n;i++){
            if(ch[i]=='1'){
                ans=max(ans,2*max(i,n-i+1));
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}