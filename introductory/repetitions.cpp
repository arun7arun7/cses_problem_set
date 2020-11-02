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
void printArray(vector<T> arr, int len) {
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;

    char prev = str[0];
    int i = 1, ans = 1, cnt = 1;
    while (i < str.size()) {
        if (str[i] == prev) {
            cnt++;
        } else{
            ans = max(ans, cnt);
            prev = str[i];
            cnt = 1;
        }
        i++;
    }
    ans = max(ans, cnt);
    cout << ans;
    return 0;
}