#include <iostream>
#define Long long long int
using namespace std;

int Mod = 1e9 + 7;
int n, m;

Long f(int);

int main(){
    cin >> n >> m;
    cout << ((f(n) - 2 + f(m)) % Mod) << endl;
    return 0;
}

Long f(int p){
    if(p == 1)
        return 2;
    else if(p == 2)
        return 4;
    else{
        Long prev = 2;
        Long next = 4;
        for(int i = 3; i <= p; i++){
            Long newValue = (next + prev) % Mod;
            prev = next;
            next = newValue;
        }
        return next;
    }
}

