#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll test;
    for(cin>>test;test>0;test--) {
        int n;
        cin>>n;
        int arr[n];
        for(int i = 0;i<n;i++)
            cin>>arr[i];
        sort(arr,arr+n);
        int min = arr[n-1];
        int j = 1;
        for(int i = n-1;i>=0;i--,j++) {
            // cout<<arr[i]<<" "<<j<<endl;
            if(arr[i]>=j)
                continue;
            else {
                break;
            }
        }
        cout<<j-1<<endl;
    }
}