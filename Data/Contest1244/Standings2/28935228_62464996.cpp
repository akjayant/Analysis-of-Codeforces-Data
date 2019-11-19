#include <bits/stdc++.h>

using namespace std;

#define int long long 

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int a, b, c, d, k;
        cin>>a>>b>>c>>d>>k;

        int valid = 0;
        for(int i=0;i<=100;i++)
        {
            for(int j=0;j<=100;j++)
            {
                if( i+j > k || valid == 1)
                    continue;
                
                int x = c*i;
                int y = d*j;

                if(x>= a && y>= b)
                {
                    cout<<i<<" "<<j<<endl;
                    valid = 1;
                    continue;
                }
            }
        }

        if(valid==0)
            cout<<"-1"<<endl;
    }
    

    return 0;
}
