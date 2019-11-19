#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    long long n;
    cin>>n;

    int sum=0,ans=0;

        for (int i=2;i<=sqrt(n);i++)
        {
            if (n%i==0)
            {
                sum++;
                if (ans==0) ans=i;
                while (n%i==0) n=n/i;
                break;
            }
        }

    if (ans==0) cout<<n<<endl;
    else if (n==1) cout<<ans<<endl;
    else cout<<"1\n";


    return 0;
}
