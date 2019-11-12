#include <bits/stdc++.h>
using namespace std;

int main() {
    int k;
    cin>>k;
    while(k--){
        int n;
        cin>>n;
        int arr[n];
        for (int i=0; i<n; i++){
            cin>>arr[i];
        }
        sort(arr, arr+n);
        int mx = -1;
        for (int i=n-1; i>=0; i--){
            int rs = min(arr[i], n-i);
            mx = max(rs, mx);
        }
        cout<<mx<<endl;
    }
    return 0;
}
