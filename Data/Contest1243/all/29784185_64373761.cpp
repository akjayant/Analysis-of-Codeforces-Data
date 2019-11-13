#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
	int t;scanf("%d",&t);
    while(t--){
        int n;scanf("%d",&n);
        int a[1111];for (int i=0;i<n;i++)scanf("%d",&a[i]);
        sort(a,a+n,greater<int>());
        int ans=n;
        for (int i=0;i<n;i++){
            if (a[i]<i+1){ans=i;break;}
        }
        printf("%d\n",ans);
    }
}