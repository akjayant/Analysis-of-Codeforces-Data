#include <bits/stdc++.h>

#define input   std::cin
#define output  std::cout

#define MAXN    100005

#define llg     long long

struct event {
    llg time;
    int type;
    int idx;

    bool operator < (const event& other) const {
        if (time == other.time)
            if (type == other.type)
                return idx > other.idx;
            else return type > other.type;
        return time > other.time;
    }
};

int N;
llg P;
llg ans[MAXN];
std::priority_queue <event> queue;

#define zeros(i) (i&(-i))

int AIB[MAXN];
void update(int pos, int val) {
    for (int i=pos; i<=N; i += zeros(i))
        AIB[i] += val;
}
int query(int pos) {
    int sum = 0;
    for (int i=pos; i> 0; i -= zeros(i))
        sum += AIB[i];
    return sum;
}

std::set <int> waiting;
llg timeQueueIsFree;

int main()
{
    std::ios_base::sync_with_stdio(false);

    input >> N >> P;
    llg x;
    for (int i=1; i<=N; ++i)
        input >> x, queue.push({x, 2, i});

    while (!queue.empty()) {
        auto top = queue.top();
        //std::cout << top.type << ' ' << top.time << ' ' << top.idx << '\n';
        //std::cout << query(top.idx) << '\n';
        queue.pop();
        if (top.type == 2) {
            if (query(top.idx) == 0) {
                update(top.idx, 1);
                timeQueueIsFree = std::max(timeQueueIsFree + P, top.time + P);
                queue.push({timeQueueIsFree, 1, top.idx});
            }
            else {
                waiting.insert(top.idx);
            }
        }
        else {
            ans[top.idx] = top.time;
            update(top.idx, -1);
            auto it = waiting.begin();
            while (it != waiting.end()) {
                if (query(*it) == 0) {
                    //std::cout << "s-a bagat " << *it << '\n';
                    queue.push({top.time, 2, *it});
                    it = waiting.erase(it);
                    break;
                }   else break;
            }
        }
    }

    for (int i=1; i<=N; ++i)
        output << ans[i] << ' ';

    return 0;
}
