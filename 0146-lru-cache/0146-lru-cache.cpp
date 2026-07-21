class LRUCache {
public:
    struct Node {
        Node* next;
        Node* prev;
        int key;
        int value;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    Node* head; // MRU
    Node* tail; // LRU

    void removeElement(Node* head) {
        if (head == nullptr)
            return;

        head->next->prev = head->prev;
        head->prev->next = head->next;
    }

    void addElement(Node* node){
        if(head==nullptr){
            head = node;
        }

        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    int capacity;
    unordered_map<int, Node*> cache;


    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);

        head -> next = tail;
        tail -> prev = head;
    }

    int get(int key) {
        if(cache.find(key) == cache.end()) return -1;
        Node* node = cache[key];
        removeElement(node);
        addElement(node);
        return node -> value;
    }

    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            Node* node = cache[key];
            node->value = value;
            removeElement(node);
            addElement(node);
        }else{
            if(cache.size() == capacity){
                Node* lru = tail->prev;
                cache.erase(lru -> key);
                removeElement(lru);
                delete lru;
            }

            Node* node = new Node(key, value);
            cache[key] = node;
            addElement(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */