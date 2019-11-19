#include <iostream>
#define Long long long int
using namespace std;

int n, m;
int odd1, odd2;
int even1, even2;

void read();
void clear();

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        read();
        Long p = odd1;
        Long q = even1;
        p *= odd2;
        q *= even2;
        cout << (p + q) << endl;
        clear();
    }
    return 0;
}

void read(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x % 2 == 0)
            even1++;
        else
            odd1++;
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        if(x % 2 == 0)
            even2++;
        else
            odd2++;
    }
}

void clear(){
    odd1 = 0;
    even1 = 0;
    odd2 = 0;
    even2 = 0;
}

