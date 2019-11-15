#include<bits/stdc++.h>

using namespace std;
const int N = 3000;
int a[N];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+n+1,cmp);
        int ans=0;int minn=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,min(i,a[i]));
        }
        cout<<ans<<endl;
    }
    return 0;
}