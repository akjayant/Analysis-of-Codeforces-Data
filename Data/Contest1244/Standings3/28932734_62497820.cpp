#include <iostream>

using namespace std;

int main()
{
    long long n, p, w, d;
    cin >> n >> p >> w >> d;

    bool solved = false;
    long long solW, solD, solL;

    for(long long draws = 0; draws <= min(n, (long long)1000000); draws++){
        if(d*draws > p)
            break;

        if((p - d*draws) % w == 0){
            long long posD = draws;
            long long posW = ((p - d*draws) / w);
            if(posW + posD > n)
                continue;

            long long posL = (n - (posD + posW));

            solved = true;
            solW = posW;
            solD = posD;
            solL = posL;
            break;
        }
    }

    if(solved)
        cout << solW << " " << solD << " " << solL << endl;
    else
        cout << -1 << endl;

    return 0;
}
