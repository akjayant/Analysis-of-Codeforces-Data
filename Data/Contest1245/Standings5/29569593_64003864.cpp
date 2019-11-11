#include<bits/stdc++.h>
using namespace std;

#define repi(i, a, b) for(int i = a; i <= b; i++)
#define repd(i, a, b) for(int i = a; i >= b; i--)
#define _end printf("\n")
#define dg(x) cout << #x << '=' << x << ' '
#define mem(a, b) memset(a, b, sizeof(a))

void _in(long long *a, ...){

    va_list arg_ptr;

    scanf("%I64d", a);
    long long *temp;

    va_start(arg_ptr, a);
    temp = va_arg(arg_ptr, long long*);

    while(temp){
        scanf("%I64d", temp);
        temp = va_arg(arg_ptr, long long*);
    }

    va_end(arg_ptr);
}

void _in(int *a, ...){
    va_list arg_ptr;

    scanf("%d", a);
    int *temp;

    va_start(arg_ptr, a);
    temp = va_arg(arg_ptr, int*);
    while(temp){
        scanf("%d", temp);
        temp = va_arg(arg_ptr, int*);
    }

    va_end(arg_ptr);
}

#define in(...) _in(__VA_ARGS__, 0)
typedef long long ll;

const int N = 500;

int bo[N], al[N];
char ans[N], a[N];

int main(){

    int t; in(&t);
    while(t--){
        int n, _a, b, c;
        in(&n, &_a, &b, &c);
        getchar();
        al['R'] = _a;
        al['P'] = b;
        al['S'] = c;
        bo['R'] = bo['P'] = bo['S'] = 0;
        repi(i, 1, n){
            char t = getchar();
            a[i] = t;
            bo[t]++;
        }
        int wins = min(al['R'], bo['S']);
        wins += min(al['P'], bo['R']);
        wins += min(al['S'], bo['P']);
        if(wins >= (n + 1) / 2){
            repi(i, 1, n) ans[i] = 0;
            repi(i, 1, n){
                if(a[i] == 'S' && al['R']){
                    ans[i] = 'R';
                    al['R']--;
                }
                else if(a[i] == 'R' && al['P']){
                    ans[i] = 'P';
                    al['P']--;
                }
                else if(a[i] == 'P' && al['S']){
                    ans[i] = 'S';
                    al['S']--;
                }
            }
            repi(i, 1, n){
                if(!ans[i]){
                    if(al['S']){
                        ans[i] = 'S';
                        al['S']--;
                    }
                    else if(al['R']){
                        ans[i] = 'R';
                        al['R']--;
                    }
                    else if(al['P']){
                        ans[i] = 'P';
                        al['P']--;
                    }
                }
            }
            printf("YES\n");
            repi(i, 1, n) printf("%c", ans[i]);
            printf("\n");
        }
        else{
            printf("NO\n");
        }
    }

    return 0;
}