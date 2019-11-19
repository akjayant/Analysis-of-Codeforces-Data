#include <cstdio>

using namespace std;

int main()
{
    FILE *fin = stdin;
    FILE *fout = stdout;
    int t,n,m,x,i;
    long long p00,p01,p10,p11;
    fscanf (fin,"%d",&t);
    for (;t;t--){
        p00=p01=p10=p11 = 0;
        fscanf (fin,"%d",&n);
        for (i=1;i<=n;i++){
            fscanf (fin,"%d",&x);
            if (x%2)
                p01++;
            else p00++;
        }
        fscanf (fin,"%d",&m);
        for (i=1;i<=m;i++){
            fscanf (fin,"%d",&x);
            if (x%2)
                p11++;
            else p10++;
        }
        fprintf (fout,"%lld\n", p11 * p01 + p00 * p10 );
    }
    return 0;
}
