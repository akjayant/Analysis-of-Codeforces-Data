#include <iostream>
#define Long long long int
using namespace std;

Long n, p, w, d, x, y, z;

void read();
bool poss();
void print();
Long gcd(Long, Long);
Long f(Long, Long);

int main(){
    read();
    if(poss())
        print();
    else
        cout << -1 << endl;
    return 0;
}

void read(){
    cin >> n >> p >> w >> d;
}

bool poss(){
    Long g = gcd(w, d);
    if((p % g) != 0)
        return false;
    Long m = p / g;
    Long a = w / g;
    Long b = d / g;
    Long q = m / a;
    Long r = m % a;
    x = q;
    while(r > 0 && r % b != 0){
        //cerr << "r = " << r << endl;
        x--;
        r += a;
    }
    if(x < 0)
        return false;
    //cerr << "r = " << r << endl;
    y = r / b;
    z = n - x - y;
    return (z >= 0);
}

void print(){
    cout << x << ' ' << y << ' ' << z << endl;
}

Long gcd(Long a, Long b){
    if(a < b)
        return f(b, a);
    else
        return f(a, b);
}

Long f(Long a, Long b){
    if(b == 0)
        return a;
    else
        return f(b, a % b);
}

