#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5+7;
const ll mod = 1e9 + 7;
#define afdafafafdafaf y1;
int ar[maxn], n, m;
char ch1[maxn], ch2[maxn];
int main()
{
    int t;scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        int a,b,c;
        scanf("%d%d%d", &a, &b, &c);
        scanf("%s", ch1);
        int ins = 0;
        for(int i=0;i<n;i++)ch2[i] = '0';
        for(int i=0;i<n;i++){
            if(ch1[i] == 'R' && b > 0){
                b--;
                ch2[i] = 'P';
                ins++;
            }
            if(ch1[i] == 'P' && c > 0){
                c--;
                ch2[i] = 'S';
                ins++;
            }
            if(ch1[i] == 'S' && a > 0){
                a--;
                ch2[i] = 'R';
                ins++;
            }
        }
        for(int i=0;i<n;i++){
            if(ch1[i] == 'R' && a > 0 && ch2[i] == '0'){
                a--;
                ch2[i] = 'R';
            }
            if(ch1[i] == 'P' && b > 0 && ch2[i] == '0'){
                b--;
                ch2[i] = 'P';
            }
            if(ch1[i] == 'S' && c > 0 && ch2[i] == '0'){
                c--;
                ch2[i] = 'S';
            }
        }
        for(int i=0;i<n;i++){
            if(ch2[i] == '0'){
                if(a > 0)ch2[i] = 'R', a--;
                else if(b > 0)ch2[i] = 'P', b--;
                else{
                    assert(c > 0);
                    c--;
                    ch2[i] = 'S';
                }
            }
        }
        if(ins * 2 >= n){
            printf("YES\n");
            ch2[n] = '\0';
            printf("%s\n", ch2);
        }
        else{
            printf("NO\n");
        }

    }


    return 0;
}
