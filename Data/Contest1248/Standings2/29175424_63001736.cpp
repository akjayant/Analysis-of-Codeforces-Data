#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct action {
    long long time;
    int type, val;

    action(long long a, int b, int c) {
        time = a;
        type = b;
        val = c;
    }
};

bool operator<(const action &fir, const action &sec) {
    if (fir.time == sec.time && fir.type == 1 && sec.type == 1)
        return fir.val < sec.val;
    if (fir.time == sec.time && fir.type == 1 && sec.type == 2)
        return true;
    if (fir.time == sec.time && fir.type == 2 && sec.type == 1)
        return false;
    return fir.time < sec.time;
}

int main() {
    int n;
    long long p;

    cin >> n >> p;
    set<action> actions;
    for (int i = 0; i < n; ++i) {
        long long time;
        cin >> time;
        actions.emplace(time, 1, i);
    }

    vector<bool> used(n);
    vector<long long> ans(n);
    deque<int> realqueue_ordered;
    priority_queue<int, vector<int>, greater<>> realqueue, virtqueue;

    for (const action& act : actions) {
        if (act.type == 2) {
            used[realqueue_ordered[0]] = true;
            ans[realqueue_ordered[0]] = act.time;
            realqueue_ordered.pop_front();
            while (!realqueue.empty() && used[realqueue.top()])
                realqueue.pop();
            if ((!virtqueue.empty() && !realqueue.empty() && realqueue.top() > virtqueue.top()) ||
            (realqueue.empty() && !virtqueue.empty())) {
                realqueue.push(virtqueue.top());
                realqueue_ordered.push_back(virtqueue.top());
                virtqueue.pop();
            }
            if (!realqueue.empty())
                actions.emplace(act.time + p, 2, -1);
        } else {
            if (realqueue.empty()) {
                actions.emplace(act.time + p, 2, -1);
            }
            while (!realqueue.empty() && used[realqueue.top()])
                realqueue.pop();
            if ((!realqueue.empty() && realqueue.top() > act.val) || realqueue.empty()) {
                realqueue.push(act.val);
                realqueue_ordered.push_back(act.val);
            } else {
                virtqueue.push(act.val);
            }
        }
    }

    for (const auto& i : ans) cout << i << ' ';
    cout << endl;

    return 0;
}