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

    ll deadline_sum = 0, finish_time_sum = 0;
    vector<int> duration(n);
    for (int i = 0; i < n; ++i) {
        int a,d;
        cin >> a >> d;

        deadline_sum += d;
        duration[i] = a;
    }

    sort(duration.begin(), duration.end());
    ll cur_time = 0;
    for (int i = 0; i < n; ++i) {
        cur_time += duration[i];
        finish_time_sum += cur_time;
    }

    cout << deadline_sum - finish_time_sum;
    return 0;
}