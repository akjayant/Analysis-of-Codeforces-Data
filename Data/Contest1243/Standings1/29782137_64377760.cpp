#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{   
    int k;
    cin>>k;

    while(k--)
    {
        int n;
        cin>>n;

        string s, t;
        cin>>s>>t;

        int count = 0, valid = 1;
        int ind1 = -1;
        int ind2 = -1;
        for(int i=0;i<n;i++)
        {
            if(s[i]!=t[i])
            {
                if(ind1==-1)
                {
                    ind1 = i;
                }
                else
                {
                    ind2 = i;
                }
                count++;
            }
        }

        if( ind1 >=0 && ind2 >=0 )
        {
            swap(s[ind1], t[ind2]);
            if(s!=t)
                valid = 0;
        }



        if( count > 2 || valid == 0 || (ind1!=-1 && ind2==-1))
        {
            cout<<"No"<<endl;
            continue;
        }
        cout<<"YeS"<<endl;
        
    }

    return 0;
}