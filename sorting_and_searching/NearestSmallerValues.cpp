#include <bits/stdc++.h>

using namespace std;

template <typename T>
vector<T> readArray(int s) {
    vector<T> arr(s);
    for (int i = 0; i < s; i++) {
        cin >> arr[i];
    }
    return arr;
}

template <typename T>
void printArray(vector<T> arr, char delimitter) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << delimitter;
    }
    cout << endl;
}

typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr = readArray<int>(n);
    vector<int> ans(n);
    stack<pair<int,int>> st;
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && st.top().first >= arr[i]) {
            st.pop();
        }
        if (st.empty()) {
            ans[i] = 0;
        } else{
            ans[i] = st.top().second;
        }
        st.push(make_pair(arr[i], i+1));
    }
    printArray(ans, ' ');
    return 0;
}