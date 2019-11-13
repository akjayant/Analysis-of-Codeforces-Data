#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s1,s2;
        cin>>s1>>s2;
        int idx1 = -1;
        int idx2 = -1;
        int counter = 0;
        for(int i=0;i<s1.length();i++)
        {
            if(s1[i]!=s2[i])
            {
                if(idx1==-1)
                {
                    idx1=i;
                }
                else
                {
                    idx2=i;
                }
                counter++;
            }
        }
        if(counter!=2)
        {
            cout<<"No";
        }
        else
        {
            string s3 = s1;
            string s4 = s2;
            swap(s3[idx1], s4[idx2]);
            swap(s1[idx2], s2[idx1]);
            if(s1==s2 || s3==s4)
            {
                cout<<"Yes";
            }
            else
            {
                cout<<"No";
            }
        }
        cout<<'\n';
    }
}