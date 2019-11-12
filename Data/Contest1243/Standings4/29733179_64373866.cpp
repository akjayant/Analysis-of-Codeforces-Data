#include<bits/stdc++.h>

using namespace std;
int a[1005];
void solve(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    int cnt=0;
    for(int i=n-1;i>=0;i--){
        if(a[i] >= cnt+1) cnt++;
        else break;
    }
    printf("%d\n",cnt);
}
int main(){
    int k,n;
    scanf("%d",&k);
    while(k--){
        solve();
    }

}
