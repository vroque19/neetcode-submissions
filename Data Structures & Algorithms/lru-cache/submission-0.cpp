class LRUCache {
    struct Node {
        int val;
        int key;
        Node* prev;
        Node* next;
        Node(int v, int k): key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    Node* dummy; // points to LRU
    Node* tail; // points to MRU
    int cap;
    unordered_map<int, Node*> mp; // map each key to its node for O(1) access

    void insert(Node* node) {
        Node* prev = tail->prev;
        prev->next = node;
        node->prev = prev;
        node->next = tail;
        tail->prev = node;
    }

    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
        return;
    }


public:
    LRUCache(int capacity) {
        dummy = new Node(-1, -1);
        tail = new Node(-1, -1);
        dummy->next = tail;
        tail->prev = dummy;
        cap = capacity;
    }
    
    int get(int key) {
    // swap the curr node to the end of the linked list
        if(mp.find(key) == mp.end()) return -1;
        Node* node = mp[key];
        remove(node);
        insert(node);
        return node->val;
    }
    
    void put(int key, int value) {
        // update the linked list
        // update tail
        // 1. make a new node
        // 2. tail->next = new node
        // 3. new node->prev = tail
        // 4. tail = new_node
        // 5. len++
        if(mp.find(key) != mp.end()) {
            remove(mp[key]);
            Node* existing = mp[key];
            existing->val = value;
            remove(existing);
            insert(existing);
            return;
            // remove if already found
        }

        // // update the map to add key: node pair
        // // if at capacity, delete the head of the linked list
        // // update the value in the hashmap
        if(mp.size() == cap) {
            cout << "LRU is full \n";
            Node* tmp = dummy->next;
            mp.erase(tmp->key);
            remove(tmp);
            delete tmp;
        }
        // Add new node
        Node* newNode = new Node(value, key);
        mp[key] = newNode;
        insert(newNode);
        

    return;

    }
};
