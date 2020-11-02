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
int mod =  pow(10,9) + 7;

ll fast_modular_exponentiation(int a, int n) {
    ll ans = 1, prev = a;
    while (n > 0) {
        if (n % 2 != 0) {
            ans = (ans * prev) % mod;
        }
        prev = (prev * prev) % mod;
        n /= 2;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    cout << fast_modular_exponentiation(2, n);
    return 0;
}



