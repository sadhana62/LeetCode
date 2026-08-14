class Node {
   public:
    int key,val;
    Node* next;
    Node* prev;
    Node(int key, int val) {
        this->key = key;
        this->val = val;
        next = NULL;
        prev = NULL;  
    }
};

class LRUCache {
    unordered_map<int, Node*> mp;
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    int capacity;
public:
    void deleteNode(Node* n) {
        Node* nextNode = n->next;
        Node* prevNode = n->prev;
        nextNode->prev = prevNode;
        prevNode->next = nextNode;
    }
    void insertAfterHead (Node* n) {
       Node* temp  = head->next;
       n->next = temp;
       temp->prev = n;
       head->next = n;
       n->prev = head;
    }
    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        Node* n =mp[key];
        deleteNode(n);
        insertAfterHead(n);
        return n->val;
        
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* n = mp[key];
            n->val = value;
            deleteNode(n);
            insertAfterHead(n);
        }
         else {
            if (mp.size() == capacity) {
                Node *nd = tail->prev;
                deleteNode(nd);
                mp.erase(nd->key);
                Node* nn =  new Node(key,value);
                insertAfterHead(nn);
                mp[key] = nn;
            } else {
                Node* nn = new Node(key,value);
                insertAfterHead(nn);
                 mp[key] = nn;
            }
         }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */