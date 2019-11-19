#include <cstdio>
#include <iostream>
#include <algorithm>
#define DIMN 2010
using namespace std;
pair <unsigned long long , pair <int,int> > mch[DIMN *DIMN];
struct pct {
    unsigned long long x , y;
} v[DIMN];
unsigned long long c[DIMN] , k[DIMN] , c2[DIMN];
int tt[DIMN] , f[DIMN] , prov[DIMN] ,fm[DIMN *DIMN];
unsigned long long modul (unsigned long long x){

    if ( x > 0)
        return x;
    return -x;
}
int rad (int x){
    while (tt[x]>0)
        x=tt[x];
    return x;
}
int main()
{
    FILE *fin = stdin;
    FILE *fout = stdout;
    int n , i , m , j , x , y , rx , ry , poz;
    unsigned long long sol , curr=0;
    fscanf(fin,"%d",&n);
    for (i=1;i<=n;i++){
        fscanf(fin,"%llu%llu",&v[i].x,&v[i].y);
    }
    for(i=1;i<=n;i++){
        fscanf(fin,"%llu",&c[i]);
        curr += c[i];
    }
    for(i=1;i<=n;i++){
        fscanf(fin,"%llu",&k[i]);
    }
    m = 0;
    for (i=1;i<=n;i++){
        tt[i] = -1;
        for (j=i+1;j<=n;j++){
            m++;
            mch[m].first = (max(v[i].x , v[j].x) - min(v[i].x , v[j].x)  +
                            max(v[i].y , v[j].y) - min(v[i].y , v[j].y)) * (k[i] + k[j]);
            mch[m].second.first = i;
            mch[m].second.second = j;
        }
    }
    sort (mch+1,mch+m+1);
    for (i=1;i<=n;i++){
        c2[i] = c[i];
    }
    sol=curr;
    poz = 0;
    int pus = 0;
    for (i=1;i<=m;i++){
        x=mch[i].second.first;
        y=mch[i].second.second;
        rx=rad(x);
        ry=rad(y);
        if (rx!=ry){
            // trb sa le unesc pe x si y
            if (curr + mch[i].first - max(c[rx] , c[ry]) <= curr){
                curr+=mch[i].first - max(c[rx] , c[ry]);
                fm[i] = 1;
                pus++;
                if (tt[rx]<tt[ry]){
                    tt[rx]+=tt[ry];
                    tt[ry]=rx;
                    c[rx] = min(c[rx] , c[ry]);
                }
                else {
                    tt[ry]+=tt[rx];
                    tt[rx]=ry;
                    c[ry] = min(c[rx] , c[ry]);
                }
            }
        }
        if (sol > curr){
            sol = curr;
            poz = i;
        }
    }
    fprintf (fout,"%llu\n",sol);
    curr = 0;
    for (i=1;i<=n;i++){
        tt[i] = -1;
        prov[i] = i;
        curr+=c2[i];
    }
    for (i=1;i<=poz;i++){
        x=mch[i].second.first;
        y=mch[i].second.second;
        rx=rad(x);
        ry=rad(y);
        if (rx!=ry){
            // trb sa le unesc pe x si y
            if (curr + mch[i].first - max(c2[rx] , c2[ry]) <= curr){
                curr+=mch[i].first - max(c2[rx] , c2[ry]);
                if (tt[rx]<tt[ry]){
                    tt[rx]+=tt[ry];
                    tt[ry]=rx;
                    if (c2[rx] > c2[ry])
                        prov[rx] = prov[ry];
                    c2[rx] = min(c2[rx] , c2[ry]);
                }
                else {
                    tt[ry]+=tt[rx];
                    tt[rx]=ry;
                    if (c2[ry] > c2[rx])
                        prov[ry] = prov[rx];
                    c2[ry] = min(c2[rx] , c2[ry]);
                }
            }
        }
    }

    fprintf(fout,"%d\n",n-pus);

    for (i=1;i<=n;i++){
        rx = rad(i);
        if (!f[rx])
            fprintf(fout,"%d ",prov[rx]);
        f[rx] = 1;
    }
    fprintf(fout,"\n");

    fprintf (fout,"%d\n",pus);
    for (i=1;i<=m;i++)
        if (fm[i])
            fprintf (fout,"%d %d\n",mch[i].second.first , mch[i].second.second);
    return 0;
}
