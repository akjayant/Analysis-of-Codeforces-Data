#include<bits/stdc++.h>
using namespace std;
const int MAX_N=1e5+10;
int n,t,a[MAX_N];
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=1000;i>=1;i--){
            int cnt=0;
            for(int j=0;j<n;j++){
                cnt+=(a[j]>=i);
            }
            if(cnt>=i){
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}