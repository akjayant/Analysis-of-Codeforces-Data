/* while(!cin.eof()) */
 
#include<bits/stdc++.h>
using namespace std; 
#define int long long 
#define mod (int)(1e9+7)
#define MAXI (int)(1e15+100)
#define N 100005
 


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
    while(n--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int ans = 0;
        while(b>=1 and c>=2)
        {
            ans+=3;
            b--;
            c-=2;
        }
        while(a>=1 and b>=2){
            ans+=3;
            a--;
            b-=2;
        }

        cout << ans << endl;
    }
 
    return 0;
    
} 