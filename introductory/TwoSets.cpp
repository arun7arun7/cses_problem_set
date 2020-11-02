#include <bits/stdc++.h>

using namespace std;

template <typename T>
vector<T> readArray(int s) {
    vector<T> arr(s);
    for (unsigned int i = 0; i < s; i++) {
        cin >> arr[i];
    }
    return arr;
}

template <typename T>
void printArray(vector<T> arr, char delimitter) {
    for (unsigned int i = 0; i < arr.size(); i++) {
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

    ll sum = (ll)n*(n+1)/2;
    if (sum%2 != 0) {
        cout << "NO";
        return 0;
    }
    ll req = sum/2, dup = n;
    unordered_set<int> first_set;
    while (req > 0) {
        if (req >= dup) {
            req -= dup;
            first_set.insert(dup);
        }
        dup--;
    }
    vector<int> set1, set2;
    for (int i = 1; i <= n; i++) {
        if (first_set.find(i) != first_set.end()) {
            set1.push_back(i);
        } else{
            set2.push_back(i);
        }
    }
    cout << "YES" << endl;
    cout << set1.size() << endl;
    printArray(set1, ' ');
    cout << set2.size() << endl;
    printArray(set2, ' ');
    return 0;
}