#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{


    vector<ll>vec;
    ll n;
    cin>>n;
    if(n == 1  || n == 2) cout<<n<<endl;
    else{
    ll m = sqrt(n);
    for(int i = 2; i<=m; i++)
    {
        if(n%i == 0)
        {
            vec.push_back(i);
            while(n%i == 0)
                n/=i;
        }
    }
    if(n!=1)  vec.push_back(n);

    if(vec.size() == 1) cout<<vec[0]<<endl;
    else cout<<1<<endl;
    }

}
