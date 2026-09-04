#include <iostream>
#include <unordered_map>
#include <climits>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define ll long long

class BinomialNode
{
public:
    ll key;
    int degree;
    BinomialNode *parent;
    BinomialNode *child;
    BinomialNode *sibling;
    BinomialNode(ll x)
    {
        key = x;
        degree = 0;
        parent = nullptr;
        child = nullptr;
        sibling = nullptr;
    }
};

class BinomialHeap
{
    BinomialNode *head;                        // first root of the root list
    ll heapSize;                               // total nodes
    unordered_map<ll, BinomialNode *> address; // key->node -- fast lookup
public:
    BinomialHeap()
    {
        head = nullptr;
        heapSize = 0;
    }

    void LinkTrees(BinomialNode *x, BinomialNode *y)
    { // x-->small
        x->parent = y;
        x->sibling = y->child;
        y->child = x;
        y->degree++;
    }

    BinomialNode *merge_root_list(BinomialNode *head1, BinomialNode *head2)
    {
        if (head1 == nullptr)
            return head2;
        if (head2 == nullptr)
            return head1;

        BinomialNode *newhead;
        BinomialNode *tail;

        if (head1->degree <= head2->degree)
        {
            newhead = head1;
            head1 = head1->sibling; 
        }
        else
        {
            newhead = head2;
            head2 = head2->sibling;
        }
        tail = newhead;

        while (head1 != nullptr && head2 != nullptr)
        {
            if (head1->degree <= head2->degree)
            {
                tail->sibling = head1;
                head1 = head1->sibling;
            }
            else
            {
                tail->sibling = head2;
                head2 = head2->sibling;
            }
            tail = tail->sibling;
        }
        tail->sibling = (head1 != nullptr) ? head1 : head2;
        return newhead;
    }

    void consolidate(bool visualize = false)
    {
        if (head == nullptr)
            return;
        BinomialNode *prev = nullptr;
        BinomialNode *curr = head;
        BinomialNode *next = curr->sibling;
        
        int step = 1;
        bool link_occurred = false;
        
        if (visualize) {
            cout << "================================\n";
            cout << "STEP 2: LINKS (in order)\n";
            cout << "================================\n";
        }

        while (next != nullptr)
        {
            if (curr->degree != next->degree)
            {
                prev = curr;
                curr = next;
            }
            else if (next->sibling != nullptr && next->sibling->degree == curr->degree)
            {
                prev = curr;
                curr = next;
            }
            else
            {
                if (curr->key < next->key)
                {
                    if (visualize) {
                        cout << "  " << step++ << ") B" << curr->degree << " + B" << next->degree 
                             << " -> B" << curr->degree + 1 << " (roots " << curr->key << " and " << next->key << ")\n";
                        link_occurred = true;
                    }
                    curr->sibling = next->sibling;
                    LinkTrees(next, curr);
                }
                else
                {
                    if (visualize) {
                        cout << "  " << step++ << ") B" << curr->degree << " + B" << next->degree 
                             << " -> B" << next->degree + 1 << " (roots " << next->key << " and " << curr->key << ")\n";
                        link_occurred = true;
                    }
                    if (prev == nullptr)
                        head = next;
                    else
                        prev->sibling = next;
                    LinkTrees(curr, next);
                    curr = next;
                }
            }
            next = curr->sibling;
        }
        
        if (visualize && !link_occurred) {
            cout << "  (No links required)\n";
        }
    }

    void union_heap(BinomialHeap &heap, bool visualize = false)
    {
        head = merge_root_list(head, heap.head);
        heapSize += heap.heapSize;

        for (auto &entry : heap.address)
            address[entry.first] = entry.second;
        heap.address.clear();
        heap.head = nullptr;
        heap.heapSize = 0;

        consolidate(visualize);
    }

    void insert(ll x)
    {
        BinomialHeap temp;
        temp.head = new BinomialNode(x);
        temp.heapSize = 1;
        temp.address[x] = temp.head; 
        union_heap(temp);            
    }

    ll findMin()
    {
        if (head == nullptr) return LLONG_MAX;
        BinomialNode *curr = head;
        ll minimum = curr->key;

        while (curr != nullptr)
        {
            minimum = min(minimum, curr->key);
            curr = curr->sibling;
        }
        return minimum;
    }

    BinomialNode *reverseChildren(BinomialNode *child)
    {
        BinomialNode *prev = nullptr;

        while (child != nullptr)
        {
            BinomialNode *next = child->sibling;

            child->sibling = prev;
            child->parent = nullptr;

            prev = child;
            child = next;
        }
        return prev;
    }

    ll extractMin()
    {
        if (head == nullptr) return -1;
        BinomialNode *minimum = head;
        BinomialNode *prevOfminimum = nullptr;

        BinomialNode *prev = nullptr;
        BinomialNode *curr = head;

        while (curr != nullptr)
        {
            if (curr->key < minimum->key)
            {
                minimum = curr;
                prevOfminimum = prev;
            }
            prev = curr;
            curr = curr->sibling;
        }
        if (prevOfminimum == nullptr)
            head = minimum->sibling;
        else
            prevOfminimum->sibling = minimum->sibling;

        ll ans = minimum->key;
        address.erase(ans);

        BinomialNode *children = reverseChildren(minimum->child);
        delete minimum;

        BinomialHeap childHeap;
        childHeap.head = children;
        ll newSize = heapSize - 1; 
        heapSize = 0;              

        BinomialNode *tmp = children;
        while (tmp != nullptr)
        {
            childHeap.heapSize += (1LL << tmp->degree);
            tmp = tmp->sibling;
        }

        union_heap(childHeap); 
        heapSize = newSize;    
        return ans;
    }

    void swap_keys(BinomialNode *a, BinomialNode *b)
    {
        swap(a->key, b->key);
        address[a->key] = a;
        address[b->key] = b;
    }

    void decreaseKey(ll x, ll y)
    {
        if (address.find(x) == address.end()) return;
        BinomialNode *curr = address[x];
        address.erase(x);

        curr->key = y;
        address[y] = curr;
        while (curr->parent != nullptr && curr->key < curr->parent->key) 
        {
            swap_keys(curr, curr->parent);
            curr = curr->parent;
        }
    }

    void removeKey(ll x)
    {
        if (address.find(x) == address.end()) return;
        static ll sentinel = -2000000000LL; 
        decreaseKey(x, sentinel--);         
        extractMin();
    }

    void printTree(BinomialNode *root, ostream &out)
    { 
        out << "Binomial Tree, B" << root->degree << endl;

        queue<BinomialNode *> q;
        q.push(root);

        int lev = 0;

        while (q.size() > 0)
        {
            int count = q.size();
            vector<ll> keys;

            while (count--)
            {
                BinomialNode *curr = q.front();
                q.pop();
                keys.push_back(curr->key);
                BinomialNode *child = curr->child;
                while (child != nullptr)
                {
                    q.push(child);
                    child = child->sibling;
                }
            }
            sort(keys.begin(), keys.end());

            out << "Level " << lev << ":";
            for (ll x : keys)
                out << " " << x;
            out << "\n";
            lev++;
        }
    }
    
    void printHeap(int heapNumber, ostream &out)
    {
        out << "Printing Binomial Heap H" << heapNumber << "\n";
        out << "Heap size: " << heapSize << "\n";

        if (head == nullptr)
        {
            out << "Heap H" << heapNumber << " is empty.\n";
            return;
        }
        BinomialNode *curr = head;
        while (curr != nullptr)
        {
            printTree(curr, out);
            curr = curr->sibling;
        }
    }

    void visualizeNode(BinomialNode* node, string prefix, bool isLast, ll globalMin)
    {
        if (node == nullptr) return;

        cout << prefix;
        cout << (isLast ? "└─ " : "├─ ");
        cout << node->key << " [order " << node->degree << ", size " << (1LL << node->degree) << "]";

        if (node->parent == nullptr) cout << " (root)";
        else cout << " (child of " << node->parent->key << ")";
        
        if (node->parent == nullptr && node->key == globalMin) {
            cout << "  <-- *** GLOBAL MINIMUM ***";
        }
        cout << "\n";

        vector<BinomialNode*> children;
        BinomialNode* c = node->child;
        while(c) {
            children.push_back(c);
            c = c->sibling;
        }

        string newPrefix = prefix + (isLast ? "   " : "│  ");
        for(size_t i = 0; i < children.size(); ++i) {
            visualizeNode(children[i], newPrefix, i == children.size() - 1, globalMin);
        }
    }

    void visualizeHeap(string name)
    {
        cout << "Heap " << name << ":\n";
        if (head == nullptr) {
            cout << "Empty\n";
            return;
        }

        ll globalMin = findMin();
        BinomialNode* curr = head;

        while (curr != nullptr)
        {
            cout << "Binomial Tree B" << curr->degree << "\n";
            
            // Print Root explicitly first
            cout << curr->key << " [order " << curr->degree << ", size " << (1LL << curr->degree) << "] (root)";
            if (curr->key == globalMin) {
                 cout << "  <-- *** GLOBAL MINIMUM ***";
            }
            cout << "\n";

            // Print Children Trees
            vector<BinomialNode*> children;
            BinomialNode* c = curr->child;
            while(c) {
                children.push_back(c);
                c = c->sibling;
            }
            
            for(size_t i = 0; i < children.size(); ++i) {
                visualizeNode(children[i], "", i == children.size() - 1, globalMin);
            }
            curr = curr->sibling;
        }
    }

    void union_visualize(BinomialHeap &heap, string myName, string otherName)
    {
        cout << "================================\n";
        cout << "STEP 1: BEFORE UNION\n";
        cout << "================================\n";
        visualizeHeap(myName);
        heap.visualizeHeap(otherName);

        // Standard Union call, but flag 'visualize' as true
        union_heap(heap, true);

        cout << "================================\n";
        cout << "STEP 3: AFTER UNION -> " << myName << "\n";
        cout << "================================\n";
        visualizeHeap(myName);
    }
};

int main()
{
    ifstream input("input.txt");
    ofstream output("output.txt");

    if (!input.is_open()) {
        cout << "Error opening input.txt\n";
        return 1;
    }

    BinomialHeap H1;
    BinomialHeap H2;

    BinomialHeap *heap[3];
    heap[1] = &H1;
    heap[2] = &H2;

    char command;

    while (input >> command)
    {
        if (command == 'I') {
            int h;
            ll x;
            input >> h >> x;
            heap[h]->insert(x);
        }
        else if (command == 'F') {
            int h;
            input >> h;
            ll result = heap[h]->findMin();
            cout << "Find Min returned: " << result << "\n";
            output << "Find Min returned: " << result << "\n";
        }
        else if (command == 'E') {
            int h;
            input >> h;
            ll result = heap[h]->extractMin();
            cout << "Extract Min returned: " << result << "\n";
            output << "Extract Min returned: " << result << "\n";
        }
        else if (command == 'D') {
            int h;
            ll x, y;
            input >> h >> x >> y;
            heap[h]->decreaseKey(x, y);
        }
        else if (command == 'R') {
            int h;
            ll x;
            input >> h >> x;
            heap[h]->removeKey(x);
        }
        else if (command == 'U') {
            int h1, h2;
            input >> h1 >> h2;
            heap[h1]->union_heap(*heap[h2]);
        }
        else if (command == 'P') {
            int h;
            input >> h;
            heap[h]->printHeap(h, output);
            heap[h]->printHeap(h, cout);
        }
        // --- PART B CUSTOM COMMANDS ---
        else if (command == 'V') {
            int h;
            input >> h;
            cout << "\n--- VISUALIZING H" << h << " ---\n";
            heap[h]->visualizeHeap("H" + to_string(h));
            cout << "-----------------------\n\n";
        }
        else if (command == 'W') {
            int h1, h2;
            input >> h1 >> h2;
            cout << "\n";
            heap[h1]->union_visualize(*heap[h2], "H" + to_string(h1), "H" + to_string(h2));
            cout << "\n";
        }
    }

    input.close();
    output.close();

    return 0;
}