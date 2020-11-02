#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

template <typename T>
vector<T> readArray(int s) {
    vector<T> arr(s);
    for (int i = 0; i < s; i++) {
        cin >> arr[i];
    }
    return arr;
}

int main()
{
    ll n;
    cin >> n;

    vector<int> arr = readArray<int>(n-1);
    ll sum = 0;
    for (int i = 0; i < n-1; i++) {
        sum += arr[i];
    }
    int missing = ((n*(n+1))/2) - sum;
    cout << missing;
    return 0;
}

