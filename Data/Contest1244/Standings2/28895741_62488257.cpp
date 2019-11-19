#include <bits/stdc++.h>
using namespace std;

long long int a[100007];
long long int pre[100007],suf[100007];
long long int n;

long long int check(long long int mid){
    long long int cnt=1000000000000000;
    for(int i=1;i<=n;i++){
        long long int temp=0;
        // cout << "YO " << a[i]+mid<< endl;
        int f = upper_bound(a,a+n+1,a[i]+mid)-a;
        if(f<=n){
            temp = temp+suf[f]-1ll*(n-f+1)*(a[i]+mid);
        }
        temp = temp+a[i]*(i-1)-pre[i-1];
        cnt=min(cnt,temp);
        // cout << "CHECKIN " << mid << " " << i << " " << f << " "  << temp << endl;
    }
    for(int i=n;i>0;i--){
        long long int temp=0;
        // cout << "YO " << a[i]-mid<< endl;
        int f = lower_bound(a,a+n+1,a[i]-mid)-a;
        if(f>0)
            temp = temp-pre[f-1]+1ll*(f-1)*(a[i]-mid);
        temp = temp-a[i]*(n-i)+suf[i+1];
        cnt=min(cnt,temp);
        // cout << "CHECKIN " << mid << " " << i << " " << f << " "  << temp << endl;
    }





    // cout << "MID " << mid << " " << cnt << endl;
    return cnt;
}

int main() {
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
 
    long long int k;
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);


    pre[0]=0;
    suf[n+1]=0;
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    for(int i=n;i>0;i--){
        suf[i]=suf[i+1]+a[i];
    }
    
    long long int low=0,high=a[n]-a[1];
    while(low<high){
        long long int mid = low + (high-low)/2;
        if(check(mid)<=k){
            high=mid;
        }
        else{
            low=mid+1;
        }
    }
    cout << low;
   
 
}