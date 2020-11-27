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

    string s;
    cin >> s;

    const int p = 31, m = 1e9+9;
    int n = s.size();
    vector<ll> hash(n+1,0);
    vector<ll> p_pow(n+1);
    p_pow[0] = 1;
    for (int i = 1; i <= n; ++i) {
        p_pow[i] = (p_pow[i-1] * p) % m;
    }
    for (int i = 0; i < n; ++i) {
        hash[i+1] = (hash[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;
    }

    const int p2 = 53, m2 = 1e9+9;
    vector<ll> hash2(n+1,0);
    vector<ll> p_pow2(n+1);
    p_pow2[0] = 1;
    for (int i = 1; i <= n; ++i) {
        p_pow2[i] = (p_pow2[i-1] * p2) % m2;
    }
    for (int i = 0; i < n; ++i) {
        hash2[i+1] = (hash2[i] + (s[i] - 'a' + 1) * p_pow2[i]) % m2;
    }

    vector<int> ans;
    for (int l = 1; l < n; ++l) {
        ll suffix_hash = (hash[n] - hash[n-l] + m) % m;
        ll prefix_hash = (hash[l] * p_pow[n-l]) % m;

        ll suffix_hash_2 = (hash2[n] - hash2[n-l] + m2) % m2;
        ll prefix_hash_2 = (hash2[l] * p_pow2[n-l]) % m2;

        if (suffix_hash == prefix_hash && suffix_hash_2 == prefix_hash_2) {
            ans.push_back(l);
        }
    }
    printArray(ans, ' ');
    return 0;
}