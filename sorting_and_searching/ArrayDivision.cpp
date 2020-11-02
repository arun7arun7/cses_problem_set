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

    int n,k;
    cin >> n >> k;

    vector<int> arr = readArray<int>(n);
    ll sum = 0;
    for (int element : arr) {
        sum += element;
    }

    ll start = 1, finish = sum, ans;
    while (start <= finish) {
        ll mid = (start + finish)/2;
        int cnt = 0;
        ll localSum = 0;
        bool possible = true;
        for (int i = 0; i < n; i++) {
            if (arr[i] > mid) {
                possible = false;
                break;
            }
            if (arr[i] + localSum > mid) {
                cnt++;
                localSum = arr[i];
            } else{
                localSum += arr[i];
            }
        }
        cnt++;
        if (possible && cnt <= k) {
            ans = mid;
            finish = mid-1;
        } else{
            start = mid+1;
        }
    }
    cout << ans;
    return 0;
}
