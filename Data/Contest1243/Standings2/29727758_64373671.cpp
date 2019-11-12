#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n+1];
        for (int i=1; i<=n; i++) cin >> arr[i];
        sort(arr+1, arr+n+1);
        reverse(arr+1, arr+n+1);

        int resp = 0;
        for (int i=1; i<=n; i++){
            if (arr[i] < i) break;
            resp++;
        }
        cout << resp << endl;
    }
}