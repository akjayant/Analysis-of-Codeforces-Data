#include <cstdio>
#include <algorithm>
using namespace std;
int v[100010];
int main()
{
    FILE *fin = stdin;
    FILE *fout = stdout;
    int t,n,m,x,i;
    long long s1,s2;

        fscanf (fin,"%d",&n);

        for (i=1;i<=n;i++){
            fscanf (fin,"%d",&v[i]);
        }
        sort (v+1 , v+n+1);
        s1 = s2 = 0;
        for (i=1;i<=n/2;i++)
            s1+=v[i];
        for (i=n/2+1;i<=n;i++)
            s2+=v[i];
        fprintf (fout,"%lld",s1*s1 + s2*s2);

    return 0;
}
