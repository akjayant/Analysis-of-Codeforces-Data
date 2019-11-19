#include <iostream>
#include <algorithm>
#define Long long long int
using namespace std;

const int N = 1e5;
int n, x, y;
int ary[N];

void read();
Long ans();

int main(){
    read();
    cout << ans() << endl;
    return 0;
}

void read(){
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> ary[i];
}

Long ans(){
    sort(ary, ary + n);
    int i = n - 1;
    int j = 0;
    int t = 0;
    while(i >= j){
        if(t == 0){
            x += ary[i];
            i--;
        }
        else{
            y += ary[j];
            j++;
        }
        t = 1 - t;
    }
    Long p = x;
    Long q = y;
    p *= p;
    q *= q;
    return (p + q);
}

