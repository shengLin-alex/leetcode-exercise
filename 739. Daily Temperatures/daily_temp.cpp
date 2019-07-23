// Given a list of daily temperatures T, return a list such that, for each day in the input, tells you how many days you
// would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.

// For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2,
// 1, 1, 0, 0].

// Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range
// [30, 100].

#include <stack>
#include <vector>

using namespace std;

vector<int> dailyTemperatures(vector<int> &T) {
    int len = T.size();
    vector<int> res(len, 0);
    stack<int> st;

    // 利用 stack 紀錄某溫度在第幾天
    for (int i = 0; i < len; i++) {
        while (!st.empty() && T[i] > T[st.top()]) {
            int idx = st.top();
            st.pop();

            res[idx] = i - idx;
        }

        st.push(i);
    }

    return res;
}

int main() {
    vector<int> t = {73, 74, 75, 71, 69, 72, 76, 73};

    auto res = dailyTemperatures(t);

    return 0;
}