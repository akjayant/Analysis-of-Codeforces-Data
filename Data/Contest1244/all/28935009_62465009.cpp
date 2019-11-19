#include <bits/stdc++.h>

using namespace std;

int t, a, b, c, d, k;

int main()
{
    scanf("%d",&t);
    while (t--){
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
        int x = a/c + (a%c>0), y = b/d + (b%d>0);
        if (x+y>k){
            cout<<-1<<endl;
        }else {
            cout<<x<<' '<<y<<endl;
        }
    }
}
