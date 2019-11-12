#include <bits/stdc++.h>

#define pb push_back
#define ll long long
#define ull unsigned long long
#define stop return cout << -1 << endl, false;

using namespace std;
/*
1
3
abc
bca
*/
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin>>t;

    while(t--)
    {
        int n, razl=0;
        cin>>n;
        string x,y;
        cin>>x>>y;
        char a[100], b[100];
        bool bad = false;
        vector <pair<int,int>> swaps;

        for(int i=0;i!=n;i++)
        {
            a[i]=x[i];
        }
        for(int i=0;i!=n;i++)
        {
            b[i]=y[i];
        }
        for(int i=0;i!=n;i++)
        {
            if(a[i] != b[i])
            {

                for(int j=i+1; j!=n; j++)
                {
                    if(a[j]==a[i])
                    {
                        swap(a[j],b[i]);
                        //cout<<"swapped "<<j<<" and "<<i<<endl;
                        swaps.pb({j,i});
                        j=n-1;
                    }
                }
                if(a[i] != b[i])
                {
                    for(int j=i+1; j!=n; j++)
                    {
                        if(b[j]==a[i])
                        {
                            swap(b[j],a[j]);
                            //cout<<"swapped "<<j<<" and "<<j<<endl;
                            swaps.pb({j,j});
                            swap(a[j],b[i]);
                            //cout<<"swapped "<<j<<" and "<<i<<endl;
                            swaps.pb({j,i});
                            j=n-1;
                        }
                    }
                }

                if(a[i]!=b[i])
                {
                    bad=true;
                    break;
                }
            }
        }
        if(bad)
        {
            cout<<"No"<<endl;
        }
        else
        {
            cout<<"Yes"<<endl;
            cout<<swaps.size()<<endl;
            for(auto it : swaps)
            {
                cout<<it.first+1<< " "<<it.second+1<<endl;
            }
        }
    }



    return 0;
}
