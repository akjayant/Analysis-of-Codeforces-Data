#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ss second
#define ff first
#define pb push_back
#define mp make_pair

int main(){
    ios_base::sync_with_stdio(0);

    int t;
    cin>>t;
    while(t--){
        int n;
        int a[1101];
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a,a+n);
        reverse(a,a+n);
        int mn=1e8,mx=0;
        for(int i=0;i<n;i++){
            mn=min(mn,a[i]);
            if(mn>=i+1){mx=i+1;}
        }
        cout<<mx<<endl;
    }
    return 0;
    }

