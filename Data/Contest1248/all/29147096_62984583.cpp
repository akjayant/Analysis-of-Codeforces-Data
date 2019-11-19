#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mod 1000000007

int main() {
    int n;
    cin>>n;
    lli a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a, a+n);
    int i=0,j=n-1;
    lli sum1 = 0, sum2 = 0;
    int ch = 1;
    while(i <= j){
        if(ch == 1){
            sum1 += a[j];
            j--;
            ch = 2;
        }else{
            sum2 += a[i];
            i++;
            ch = 1;
        }
    }
    lli ans = sum1 * sum1 + sum2 * sum2;
    cout<<ans<<"\n";
    return 0;
}
