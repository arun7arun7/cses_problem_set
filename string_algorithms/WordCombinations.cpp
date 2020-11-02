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

class Trie {
private:

public:
    struct Key {
        char c;

        Key(char ch) {
            c = ch;
        }

        bool operator==(const Key & key) const {
            return c == key.c;
        }
    };

    struct KeyHasher {
    public:
        size_t operator()(const Key& k) const
        {
            return hash<char>()(k.c);
        }
    };

    struct Node {
        Key* key;
        unordered_map<Key,struct Node*,KeyHasher> children;
        bool isEndWord;

        Node(Key* key) {
            this->key = key;
            this->children.reserve(26);
            this->children.max_load_factor(0.25);
            this->isEndWord = false;
        }

        Node* findChild(Key& k) {
            if (children.find(k) != children.end()) {
                return children[k];
            }
            return nullptr;
        }

        void addChild(Node* node) {
            Key* k = node->key;
            children[*k] = node;
        }

    };

    Node* root;

    Trie() {
        root = new Node(new Key('\0'));
    }

    /** Inserts a word into the trie. */
    void insert(const string& word) {
        root = insert(root, 0, word);
    }

    Node* insert(Node* cur, unsigned int index, const string& word) {
        Node* newChildNode;
        Key key(word[index]);
        Node* matchingChild = cur->findChild(key);
        if (matchingChild != nullptr) {
            if (index == word.length()-1) {
                matchingChild->isEndWord = true;
                cur->addChild(matchingChild);
                return cur;
            }
            newChildNode = insert(matchingChild, index+1, word);
            cur->addChild(newChildNode);
        }
        else {
            newChildNode = new Node(&key);
            if (index == word.length()-1) {
                newChildNode->isEndWord = true;
                cur->addChild(newChildNode);
                return cur;
            }
            cur->addChild(insert(newChildNode, index+1, word));
        }
        return cur;
    }

    /** Returns if the word is in the trie. */
    bool search(const string& word) const {
        Node* cur = root;
        for (unsigned int i = 0; i < word.length(); i++) {
            Key key(word[i]);
            Node* child = cur->findChild(key);
            if (child == nullptr) {
                return false;
            }
            cur = child;
        }
        return cur->isEndWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(const string& prefix) const {
        Node *cur = root;
        for (unsigned int i = 0; i < prefix.length(); i++) {
            Key key(prefix[i]);
            Node *child = cur->findChild(key);
            if (child == nullptr) {
                return false;
            }
            cur = child;
        }
        return true;
    }
};

vector<ll> dp;
int mod;

ll fun(unsigned int i, Trie& trie, string& s) {
    if (i == s.length()) {
        return 1;
    }
    if (dp[i] != -1) {
        return dp[i];
    }
    ll ans = 0;
    Trie::Node* cur = trie.root;
    unsigned int j = i;
    while (j < s.length()) {
        Trie::Key key(s[j]);
        cur = cur->findChild(key);
        if (cur == nullptr) {
            break;
        }
        if (cur->isEndWord) {
            (ans += fun(j+1, trie,s)) %= mod;
        }
        j++;
    }
    dp[i] = ans;
    return dp[i];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    mod = 1e9+7;

    string s;
    cin >> s;

    int k;
    cin >> k;

    vector<string> arr(k);
    readArray(arr, k);

    Trie trie;
    for (int i = 0; i < k; ++i) {
        trie.insert(arr[i]);
    }
    dp.assign(s.length(), -1);
    cout << fun(0, trie, s);
    return 0;
}