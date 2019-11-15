#include<bits/stdc++.h>
using namespace std;
const int N=5e4+10;
typedef long long ll;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int m=min(b,c/2);
        b-=m;
        cout<<min(a,b/2)*3+m*3<<endl;
    }
    return 0;
}
