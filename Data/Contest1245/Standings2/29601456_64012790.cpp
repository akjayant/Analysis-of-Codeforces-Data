#include<bits/stdc++.h>
using namespace std;
#define mx 1009

char str[mx];
char res[mx];
int main()
{
    int t, a, b, c, n,x,y,z;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        scanf("%d %d %d",&a,&b,&c);

        scanf("%s",str);
        int wn = 0;
        memset(res,0,sizeof(res));
        x=0;y=0;z=0;
        for(int i=0;i<n;i++){
            switch(str[i]){
                case 'R':
                    x++;
                    break;
                case 'P':
                    y++;
                    break;
                case 'S':
                    z++;
                    break;
                default:
                    break;
            }
        }
        //printf("%d %d %d\n",x,y,z);
        wn = min(x,b)+ min(y,c) + min(z,a);
        if(wn*2 >= n)
        {
            puts("YES");
            for(int i=0;i<n;i++){
                if(str[i]=='R' && b){
                    res[i] = 'P'; b--;
                }
                else if(str[i]=='P' && c){
                    res[i] = 'S'; c--;
                }
                else if(str[i]=='S' && a){
                    res[i] = 'R'; a--;
                }
            }
            for(int i=0;i<n;i++){
                if(!res[i]){
                    if(a){ res[i]='R'; a--; }
                    else if(b){res[i]='P';b--;}
                    else{
                        res[i]='S';c--;
                    }
                }
            }
            printf("%s\n",res);
        }
        else{
            puts("NO");
        }
    }
    return 0;
}

