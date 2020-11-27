#include <bits/stdc++.h>

using namespace std;

void fastscan(int &x)
{
    bool neg=false;
    register int c;
    x =0;
    c=getchar();
    if(c=='-')
    {
        neg = true;
        c=getchar();
    }
    for(;(c>47 && c<58);c=getchar())
        x = (x<<1) + (x<<3) +c -48;
    if(neg)
        x *=-1;
}

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

    int n;
    cin >> n;
    vector<int> arr(n);
    readArray(arr,n);

    int j = 0, ans = 0;
    unordered_set<int> s;
    s.reserve(n);
    s.max_load_factor(0.1);
    for (int i = 0; i < n; ++i) {
        while (j < n && s.find(arr[j]) == s.end()) {
            s.insert(arr[j]);
            j++;
        }
        ans = max(ans, j-i);
        s.erase(arr[i]);
    }
    cout << ans;
    return 0;
}