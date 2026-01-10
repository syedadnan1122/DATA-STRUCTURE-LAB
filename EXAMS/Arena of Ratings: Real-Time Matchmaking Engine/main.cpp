#include <iostream>
#include <string>
using namespace std;

struct Player {
    int rating;
    string name;
    long long hp;
    Player* left;
    Player* right;

    Player(int r, string n, long long h) {
        rating = r;
        name = n;
        hp = h;
        left = right = nullptr;
    }
};

class ArenaTree {
public:
    Player* root;
    int size;

    ArenaTree() {
        root = nullptr;
        size = 0;
    }

    // ---------- FIND ----------
    Player* findPlayer(Player* node, int r) {
        if (!node) return nullptr;
        if (node->rating == r) return node;
        if (r < node->rating) return findPlayer(node->left, r);
        return findPlayer(node->right, r);
    }

    // ---------- INSERT ----------
    Player* addPlayer(Player* node, int r, string n, long long h, bool &added) {
        if (!node) {
            added = true;
            return new Player(r, n, h);
        }

        if (r < node->rating)
            node->left = addPlayer(node->left, r, n, h, added);
        else if (r > node->rating)
            node->right = addPlayer(node->right, r, n, h, added);
        else
            added = false;

        return node;
    }

    // ---------- MIN ----------
    Player* minNode(Player* node) {
        while (node && node->left)
            node = node->left;
        return node;
    }

    // ---------- DELETE ----------
    Player* deletePlayer(Player* node, int r, bool &deleted) {
        if (!node) return nullptr;

        if (r < node->rating)
            node->left = deletePlayer(node->left, r, deleted);
        else if (r > node->rating)
            node->right = deletePlayer(node->right, r, deleted);
        else {
            deleted = true;

            if (!node->left) {
                Player* t = node->right;
                delete node;
                return t;
            }
            if (!node->right) {
                Player* t = node->left;
                delete node;
                return t;
            }

            Player* t = minNode(node->right);
            node->rating = t->rating;
            node->name = t->name;
            node->hp = t->hp;
            node->right = deletePlayer(node->right, t->rating, deleted);
        }
        return node;
    }

    // ---------- SUCCESSOR ----------
    Player* successor(Player* node, int x) {
        Player* res = nullptr;
        while (node) {
            if (node->rating > x) {
                res = node;
                node = node->left;
            } else
                node = node->right;
        }
        return res;
    }

    // ---------- PREDECESSOR ----------
    Player* predecessor(Player* node, int x) {
        Player* res = nullptr;
        while (node) {
            if (node->rating < x) {
                res = node;
                node = node->right;
            } else
                node = node->left;
        }
        return res;
    }

    // ---------- RANGE ----------
    void printRange(Player* node, int L, int R, bool &printed) {
        if (!node) return;

        if (node->rating > L)
            printRange(node->left, L, R, printed);

        if (node->rating >= L && node->rating <= R) {
            cout << node->rating << " " << node->name << " " << node->hp << "\n";
            printed = true;
        }

        if (node->rating < R)
            printRange(node->right, L, R, printed);
    }

    // ---------- COUNT ----------
    int countNodes(Player* node) {
        if (!node) return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    // ---------- RANK ----------
    int getRank(Player* node, int x) {
        if (!node) return 0;
        if (node->rating >= x)
            return getRank(node->left, x);
        return 1 + countNodes(node->left) + getRank(node->right, x);
    }

    // ---------- KTH ----------
    Player* kthPlayer(Player* node, int k) {
        if (!node) return nullptr;

        int leftSize = countNodes(node->left);
        if (k == leftSize + 1) return node;
        if (k <= leftSize) return kthPlayer(node->left, k);
        return kthPlayer(node->right, k - leftSize - 1);
    }

    // ---------- HEIGHT ----------
    int treeHeight(Player* node) {
        if (!node) return -1;
        return 1 + max(treeHeight(node->left), treeHeight(node->right));
    }

    // ---------- LEAVES ----------
    int leafCount(Player* node) {
        if (!node) return 0;
        if (!node->left && !node->right) return 1;
        return leafCount(node->left) + leafCount(node->right);
    }

    // ---------- DUEL ----------
    Player* lowestCommonAncestor(Player* node, int a, int b) {
        if (!node) return nullptr;
        if (node->rating > a && node->rating > b)
            return lowestCommonAncestor(node->left, a, b);
        if (node->rating < a && node->rating < b)
            return lowestCommonAncestor(node->right, a, b);
        return node;
    }

    int distanceFrom(Player* node, int x) {
        if (node->rating == x) return 0;
        if (x < node->rating) return 1 + distanceFrom(node->left, x);
        return 1 + distanceFrom(node->right, x);
    }

    int duelDistance(Player* node, int a, int b) {
        Player* lca = lowestCommonAncestor(node, a, b);
        return distanceFrom(lca, a) + distanceFrom(lca, b);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ArenaTree arena;
    int Q;
    cin >> Q;

    while (Q--) {
        string cmd;
        cin >> cmd;

        if (cmd == "JOIN") {
            int r; string n; long long h;
            cin >> r >> n >> h;
            bool added = false;
            arena.root = arena.addPlayer(arena.root, r, n, h, added);
            if (added) { cout << "JOINED\n"; arena.size++; }
            else cout << "DUPLICATE\n";
        }

        else if (cmd == "LEAVE") {
            int r; cin >> r;
            bool deleted = false;
            arena.root = arena.deletePlayer(arena.root, r, deleted);
            if (deleted) { cout << "LEFT\n"; arena.size--; }
            else cout << "NOT FOUND\n";
        }

        else if (cmd == "STATUS") {
            int r; cin >> r;
            Player* p = arena.findPlayer(arena.root, r);
            if (!p) cout << "NOT FOUND\n";
            else cout << p->rating << " " << p->name << " " << p->hp << "\n";
        }

        else if (cmd == "DAMAGE") {
            int r; long long a;
            cin >> r >> a;
            Player* p = arena.findPlayer(arena.root, r);
            if (!p) cout << "NOT FOUND\n";
            else {
                p->hp = max(0LL, p->hp - a);
                cout << "DAMAGED " << p->hp << "\n";
            }
        }

        else if (cmd == "HEAL") {
            int r; long long a;
            cin >> r >> a;
            Player* p = arena.findPlayer(arena.root, r);
            if (!p) cout << "NOT FOUND\n";
            else {
                p->hp += a;
                cout << "HEALED " << p->hp << "\n";
            }
        }

        else if (cmd == "NEXT") {
            int x; cin >> x;
            Player* p = arena.successor(arena.root, x);
            if (!p) cout << "NONE\n";
            else cout << p->rating << " " << p->name << " " << p->hp << "\n";
        }

        else if (cmd == "PREV") {
            int x; cin >> x;
            Player* p = arena.predecessor(arena.root, x);
            if (!p) cout << "NONE\n";
            else cout << p->rating << " " << p->name << " " << p->hp << "\n";
        }

        else if (cmd == "MATCH") {
            int x; cin >> x;
            if (!arena.root) {
                cout << "EMPTY\n";
                continue;
            }
            Player* p = arena.predecessor(arena.root, x);
            Player* s = arena.successor(arena.root, x);

            if (!p && s) cout << s->rating << " " << s->name << " " << s->hp << "\n";
            else if (p && !s) cout << p->rating << " " << p->name << " " << p->hp << "\n";
            else {
                if (abs(x - p->rating) <= abs(s->rating - x))
                    cout << p->rating << " " << p->name << " " << p->hp << "\n";
                else
                    cout << s->rating << " " << s->name << " " << s->hp << "\n";
            }
        }

        else if (cmd == "RANGE") {
            int L, R; cin >> L >> R;
            bool printed = false;
            arena.printRange(arena.root, L, R, printed);
            if (!printed) cout << "EMPTY\n";
        }

        else if (cmd == "RANK") {
            int x; cin >> x;
            cout << arena.getRank(arena.root, x) << "\n";
        }

        else if (cmd == "KTH") {
            int k; cin >> k;
            if (k < 1 || k > arena.size)
                cout << "OUT OF RANGE\n";
            else {
                Player* p = arena.kthPlayer(arena.root, k);
                cout << p->rating << " " << p->name << " " << p->hp << "\n";
            }
        }

        else if (cmd == "DUEL") {
            int a, b; cin >> a >> b;
            if (!arena.findPlayer(arena.root, a) || !arena.findPlayer(arena.root, b))
                cout << "NOT FOUND\n";
            else
                cout << "DIST " << arena.duelDistance(arena.root, a, b) << "\n";
        }

        else if (cmd == "STATS") {
            cout << "PLAYERS " << arena.size << "\n";
            if (!arena.root) {
                cout << "MIN NONE\nMAX NONE\nHEIGHT -1\nLEAVES 0\n";
            } else {
                cout << "MIN " << arena.minNode(arena.root)->rating << "\n";
                Player* t = arena.root;
                while (t->right) t = t->right;
                cout << "MAX " << t->rating << "\n";
                cout << "HEIGHT " << arena.treeHeight(arena.root) << "\n";
                cout << "LEAVES " << arena.leafCount(arena.root) << "\n";
            }
        }
    }
    return 0;
}
