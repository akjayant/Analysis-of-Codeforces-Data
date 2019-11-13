#include <cstdio>
#include <iostream>
using namespace std;
char semn[110];
int main()
{
    FILE *fin = stdin;
    FILE *fout = stdout;
    int t , a , b , c, a1,b1,c1,n,r,p,s,i,wr,ws,wp,x,y,z,points;
    fscanf (fin,"%d",&t);
    for (;t;t--){
        fscanf(fin,"%d%d%d%d\n",&n,&a,&b,&c);
        a1 = a;
        b1 = b;
        c1 = c;
        r = p = s = 0;
        for (i=1;i<=n;i++){
            semn[i] = fgetc(fin);
            if (semn[i] == 'R')
                r++;
            else if (semn[i] == 'P')
                p++;
            else s++;
        }
        points = min(a , s) + min (b , r) + min(c , p);
        wr = min(a , s);
        wp = min(b,r);
        ws = min(c,p);
        x = min(a,s);
        y = min(b,r);
        z= min(c,p);
        a-=x; s-=x;
        b-=y; r-=y;
        c-=z; p-=z;

       /* x = min(a,r);
        y = min(b,p);
        z = min(c,s);*/

        if (points >= n/2 + n%2){
            fprintf(fout,"YES\n");
            for (i=1;i<=n;i++){
                if (semn[i]=='R'){
                    if (wp){
                        fprintf(fout,"P");
                        wp--;
                    }
                    /*else if (x){
                        fprintf(fout,"R");
                        x--;
                    }*/
                    else if (a){
                        fprintf(fout,"R");
                        a--;
                    }
                    else fprintf(fout,"S");
                }
                else if (semn[i] == 'P'){
                    if (ws){
                        fprintf(fout,"S");
                        ws--;
                    }
                    /*else if (x){
                        fprintf(fout,"R");
                        x--;
                    }*/
                    else if (b){
                        fprintf(fout,"P");
                        b--;
                    }
                    else fprintf(fout,"R");
                }
                else {
                    if (wr){
                        fprintf(fout,"R");
                        wr--;
                    }
                    /*else if (x){
                        fprintf(fout,"R");
                        x--;
                    }*/
                    else if (c){
                        fprintf(fout,"S");
                        c--;
                    }
                    else fprintf(fout,"P");
                }
            }
            fprintf (fout,"\n");
        }
        else fprintf(fout,"NO\n");

    }
    return 0;
}
