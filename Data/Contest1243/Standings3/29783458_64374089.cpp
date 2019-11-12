#include <bits/stdc++.h>

using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> ar(n);
        for(int i = 0;i<n;i++)
        {
            cin>>ar[i];
        }
        sort(ar.begin(),ar.end());
        int num = 1;
        int ans = 0;
        for(int i = n-1;i>=0;i--)
        {
            if(ar[i]>=num)
                ans++;
            else
                break;
            num++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
