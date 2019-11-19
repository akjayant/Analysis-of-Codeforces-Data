//Author - Rahil Malhotra
#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long
#define double long double

int32_t main()
{
    IOS;
    int n;
    cin>>n;
    int arr[n];
    int sumtot=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sumtot+=arr[i];
    }
    sort(arr,arr+n);
    int ct=0;
    int s1=0;
    for(int i=n-1;i>=0;i--)
    {
        s1+=arr[i];
        ct++;
        if(ct*2>=n)
            break;
    }
    int s2=sumtot-s1;
    cout<<s1*s1+s2*s2;
}