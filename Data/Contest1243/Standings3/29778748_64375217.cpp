//Bismillahir rahmanir rahim
#include<bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define debug(x) cout << #x << ": " << x << "\n";
using namespace std;

int arr[1005];

int main()
{
    int k;
    scanf("%d",&k);
    while(k--){
        int n;
        scanf("%d",&n);
        for(int i = 0;i < n;i++){
            scanf("%d",&arr[i]);
        }
        sort(arr,arr+n);
        int mx = -1;
        for(int i = n-1;i >= 0;i--){
            mx = max(mx,min(n-i,arr[i]));
        }
        printf("%d\n",mx);
    }
    return 0;
}
