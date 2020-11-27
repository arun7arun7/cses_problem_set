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

struct Position {
    int position,type,index;

    // Position(int position, int type, int index) : position(position), type(type), index(index) {}

    bool operator<(const Position &rhs) const {
        if (position < rhs.position)
            return true;
        if (rhs.position < position)
            return false;
        if (type < rhs.type)
            return true;
        if (rhs.type < type)
            return false;
        return index < rhs.index;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<Position> positions(2*n);
    for (int i = 0; i < n; ++i) {
        int a,b;
        cin >> a >> b;
        positions[2*i] = {a,0,i};
        positions[2*i+1] = {b,1,i};
    }

    sort(positions.begin(), positions.end());
    int max_rooms = 0, cur_rooms = 0;
    vector<int> rooms(n);
    unordered_set<int> unfilled_rooms;
    for (int i = 0; i < 2 * n; ++i) {
        if (positions[i].type == 0) {
            cur_rooms++;
            if (cur_rooms > max_rooms) {
                max_rooms = cur_rooms;
                rooms[positions[i].index] = max_rooms;
            }
            else {
                auto begin = unfilled_rooms.begin();
                rooms[positions[i].index] = *begin;
                unfilled_rooms.erase(begin);
            }
        }
        else {
            cur_rooms--;
            unfilled_rooms.insert(rooms[positions[i].index]);
        }
    }
    cout << max_rooms << endl;
    printArray(rooms, ' ');
    return 0;
}