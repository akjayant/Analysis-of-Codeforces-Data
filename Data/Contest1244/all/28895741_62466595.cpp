#include <bits/stdc++.h>
using namespace std;


int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        int ans=n;
        int p1=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                p1=i;
            }
        }
        int p2=-1;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1'){
                p2=i;
            }
        }
        if(p1==-1){
            cout << n << endl;
        }
        else{
            cout << 2*max(p1+1,n-p2) << endl;
        }
    }
    







}