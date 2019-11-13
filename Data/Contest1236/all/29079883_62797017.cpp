#include<bits/stdc++.h>
using namespace std;

const int N=5e4+10;


int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
            printf("%d ",j&1?(j-1)*n+i:j*n-i+1);
        puts("");
    }
    return 0;
}
