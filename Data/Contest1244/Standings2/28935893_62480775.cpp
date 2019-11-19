#include <iostream>

using namespace std;

long long n,p, w,d;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n>>p>>w>>d;
    for (long long y=0; y<=100000 && p>=y*d; y++) {
        if ((p-y*d)%w == 0 && y + (p-y*d)/w <= n) {
            long long x = (p-y*d)/w;
            cout<< x <<' '<< y <<' '<< n-x-y <<'\n';
            return 0;
        }
    }
    cout<<"-1\n";

    return 0;
}
