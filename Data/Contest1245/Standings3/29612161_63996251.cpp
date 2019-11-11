#include <cstdio>

using namespace std;
int cmmdc (int a , int b){
    int r;
    while (b){
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}
int main()
{
    FILE *fin = stdin;
    FILE *fout = stdout;
    int t , a , b;
    fscanf (fin,"%d",&t);
    for (;t;t--){
        fscanf (fin,"%d%d",&a,&b);
        if (cmmdc ( a , b) == 1)
            fprintf (fout,"Finite\n");
        else fprintf(fout,"Infinite\n");
    }
    return 0;
}
