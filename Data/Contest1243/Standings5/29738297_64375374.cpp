#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define f(i,a,b) for(int i=a; i<b; i++)
#define pb push_back
#define vi vector<int>
#define vl vector<long long>
#define vii vector<vector<int>>
#define vll vector<vector<long long>>
using namespace std;

int main()
{
    IOS
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n], ans = 1;
        f(i, 0, n) cin>>a[i];
        sort(a, a+n);
        for(int i=n-1; i>=0; i--)
        {
        	if(a[i] >= n-i) ans = max(ans, n-i);
        }
	    cout<<ans<<endl;
    }
    return 0;
}