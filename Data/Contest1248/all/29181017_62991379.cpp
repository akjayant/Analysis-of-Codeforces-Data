#include<bits/stdc++.h>
using namespace std;
int T,n,x,m,o1,j1,o2,j2;
int a[100010];
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        o1=j1=o2=j2=0;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++){
            if(i==1||a[i]!=a[i-1]){
                if(a[i]&1) j1++;
                else o1++;
            }
        }
        cin>>m;
        for(int i=1;i<=m;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+m+1);
        for(int i=1;i<=m;i++){
            if(i==1||a[i]!=a[i-1]){
                if(a[i]&1) j2++;
                else o2++;
            }
        }
        cout<<1ll*j1*j2+1ll*o1*o2<<endl;
    }
}
