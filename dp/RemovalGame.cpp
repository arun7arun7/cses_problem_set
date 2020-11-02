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

typedef long ll;
int n;
vector<int> arr;
pair<ll,ll> dp[5001][5001][2];
pair<ll,ll> null;

pair<ll,ll> fun(int i, int j, int player) {
    if (dp[i][j][player] != null) {
        return dp[i][j][player];
    }
    if (i == j) {
        int &element = arr[i];
        if (player == 0) {
            pair<ll,ll> pair(element, 0);
            dp[i][j][player] = pair;
        }
        else {
            pair<ll,ll> pair(0, element);
            dp[i][j][player] = pair;
        }
        return dp[i][j][player];
    }
    int& element_i = arr[i], element_j = arr[j];
    if (player == 0) {
        pair<ll,ll> take_beg = fun(i+1, j, 1);
        pair<ll,ll> take_end = fun(i, j-1, 1);
        ll beg = element_i + take_beg.first;
        ll end = element_j + take_end.first;
        if (beg > end) {
            pair<ll,ll> pair(beg, take_beg.second);
            dp[i][j][player] = pair;
        }
        else {
            pair<ll,ll> pair(end, take_end.second);
            dp[i][j][player] = pair;
        }
    }
    else {
        pair<ll,ll> take_beg = fun(i+1, j, 0);
        pair<ll,ll> take_end = fun(i, j-1, 0);
        ll beg = element_i + take_beg.second;
        ll end = element_j + take_end.second;
        if (beg > end) {
            pair<ll,ll> pair(take_beg.first, beg);
            dp[i][j][player] = pair;
        }
        else {
            pair<ll,ll> pair(take_end.first, end);
            dp[i][j][player] = pair;
        }
    }
    return dp[i][j][player];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    arr = readArray<int>(n);

    null = make_pair(-1,-1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < 2; ++k) {
                dp[i][j][k] = null;
            }
        }
    }
    cout << fun(0,n-1,0).first;
    return 0;
}