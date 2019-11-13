#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,a[100009],mx;
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        mx=0;
        sort(a,a+n);
        for(int i=0;i<n;i++){
            mx=max(mx,min(a[i],n-i));
        }
        cout<<mx<<endl;
    }
}
