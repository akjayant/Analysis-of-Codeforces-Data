#include<bits/stdc++.h>
using namespace std;
int arr[10101];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        fill(arr,arr+1010,0);
        for(int i=0;i<n;i++){
            int a;
            scanf("%d",&a);
            arr[a]++;
        }
        int opt=0;
        for(int i=n;i>0;i--){
            arr[i]+=arr[i+1];
            if(arr[i]>=i){
                opt=i;
                break;
            }
        }
        printf("%d\n",opt);
    }
}
