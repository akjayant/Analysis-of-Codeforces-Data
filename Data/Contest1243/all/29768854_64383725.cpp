#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;
long long mod=1000000007;

int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        sort(arr,arr+n,greater<int>());
        int i=0;
        while(arr[i]>=i+1&&i<n)
        i++;
        cout<<i<<"\n";
        
    }
}