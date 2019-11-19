#include <iostream>

using namespace std;

int t,a,b,c,d,k;
int kella, kellb;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--) {
        cin>>a>>b>>c>>d>>k;
        kella = a/c;
        if (a > (a/c)*c) kella++;
        kellb = b/d;
        if (b > (b/d)*d) kellb++;
        if (kella + kellb > k) cout<<"-1\n";
        else cout<<kella<<' '<<kellb<<'\n';
    }

    return 0;
}
