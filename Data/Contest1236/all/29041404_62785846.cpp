#include <bits/stdc++.h>
using namespace std;
int anss , tt , aa , bb , cc , dd ;
int F[1001];
int main()
{
  //  freopen("x.inp","r",stdin);
    cin>>tt;
    for (int i=1;i<=110;i++) F[i] += 2;
    for (int i=1;i<=110;i++) F[i] += 3;
    for (int i=1;i<=110;i++) F[i] += 4;
    for (int i=1;i<=110;i++) F[i] += 4;
    while ( tt-- )
    {
        cin>>aa>>bb>>cc;
        anss = 0 ;
        dd =  min( bb , cc/ 2)  ;
        anss +=  3 * dd;
        bb -= dd ;
        dd =  min( aa , bb/ 2)  ;
        anss += 3 * dd ;
        cout<<anss<<endl;
    }
    return 0;
}
