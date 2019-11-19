#include <cstdio>
#include <algorithm>
#define DIMN 510
#define MOD 1000000007
using namespace std;
int v[DIMN],w[DIMN];
pair <int,int> prefix[DIMN] , suffix[DIMN];
int main()
{
    FILE *fin = stdin;
    FILE *fout = stdout;
    int n,sol=0,rot,sx,sy,i,j,k,minpref,pref;
    char c;
    sx = sy = 1;
    fscanf (fin,"%d\n",&n);

    for (i=1;i<=n;i++){
        c = fgetc(fin);
        if (c=='(')
            v[i] = 1;
        else v[i] = -1;
    }

    for (i=1;i<=n;i++){
        for (j=i;j<=n;j++){

            for (k=1;k<=n;k++)
                w[k] = v[k];
            swap(w[i] , w[j]);
            //if (i == 7 && j == 8)
              //  printf ("%d ",rot);
            minpref = n;
            pref = 0;
            for (k=1;k<=n;k++){
                pref += w[k];
                minpref = min(minpref , pref);
                prefix[k] = make_pair(minpref , pref);
            }

            minpref = n;
            pref = 0;
            for (k=n;k;k--){
                pref += w[k];
                if (k == n)
                    minpref = w[k];
                else minpref = min (minpref + w[k] , w[k]);
                suffix[k] = make_pair(minpref , pref);
            }

            rot = 0;

            if (prefix[n].second == 0 && prefix[n].first >=0)
                rot++;

            for (k=1;k<n;k++){
                if (prefix[k].second + suffix[k+1].second == 0 && suffix[k+1].first>=0 && suffix[k+1].second + prefix[k].first >= 0)
                    rot++;
            }
            if (rot > sol){
                sol = rot;
                sx = i;
                sy = j;
            }

        }
    }
    fprintf (fout,"%d\n%d %d",sol,sx,sy);
    return 0;
}
