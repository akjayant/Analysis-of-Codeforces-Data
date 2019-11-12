#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n,data[1050]={0};
        cin>>n;
        for (int i=0;i<n;i++)
            cin>>data[i];
        sort(data,data+n);

        for (int i=0;i<n;i++)
        {
            if (data[i]>=n-i)
            {
                cout<<n-i<<endl;
                break;
            }
        }
    }

    return 0;
}
