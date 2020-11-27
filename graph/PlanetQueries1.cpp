#include <bits/stdc++.h>

using namespace std;

template <typename T>
vector<T> readArray(vector<T>& arr, int s) {
    for (int i = 0; i < s; i++) {
        cin >> arr[i];
    }
    return arr;
}

template <typename T>
void printArray(vector<T>& arr, char delimitter) {
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

    int n,q;
    cin>>n>>q;
    vector<int> t(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> t[i];

    }

    vector<vector<int>> st(n+1, vector<int>(31));
    for (int i = 1; i <= n; ++i) {
        st[i][0] = t[i];
    }
    for (int j = 1; j <= 30; ++j) {
        for (int i = 1; i <= n; ++i) {
            st[i][j] = st[st[i][j-1]][j-1];
        }
    }

    vector<int> ans(q);
    for (int i = 0; i < q; ++i) {
        int x,k;
        cin >> x >> k;
        int res = x, j = 0;
        while (k > 0) {
            if ((k & 1) > 0) {
                res = st[res][j];
            }
            k = k >> 1;
            ++j;
        }
        ans[i] = res;
    }
    printArray(ans, '\n');
    return 0;
}