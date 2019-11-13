/* while(!cin.eof()) */
 
#include<bits/stdc++.h>
using namespace std; 
#define int long long 
#define mod (int)(1e9+7)
#define MAXI (int)(1e15+100)
#define N 100005
 
int power(int a,int m1)
{
    if(m1==0)return 1;
    else if(m1==1)return a;
    else if(m1==2)return (1LL*a*a)%mod;
    else if(m1&1)return (1LL*a*power(power(a,m1/2),2))%mod;
    else return power(power(a,m1/2),2)%mod;
}

// Driver code to test above functions
int32_t main()
{
    
 
    #ifndef ONLINE_JUDGE
    // for getting input from inpu.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    //freopen("output.txt", "w", stdout);
    #endif
     
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    int a[n][n];
    int i=0;
    int ans = n*n;
    for(int j=n-1;j>=0;j--)
    {
        if(i==0)
        {
            while(i<=n-1)
            {
                a[i][j] = ans;
                ans--;
                i++;
            }
            i=n-1;
        }
        else 
        {
            while(i>=0)
            {
                a[i][j] = ans;
                ans--;
                i--;
            }
            i=0;
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
 
    return 0;
    
} 