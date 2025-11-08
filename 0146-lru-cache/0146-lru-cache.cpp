class Node{
public:
int key;
int val;
Node* prev;
Node* next;
Node(int key,int val):key(key), val(val), prev(nullptr), next(nullptr) {}
};

class LRUCache {
    private:
    int cap;
    unordered_map<int,Node*> cache;
    Node* oldest;
    Node* latest;
public:
    LRUCache(int capacity):cap(capacity) {
       oldest=new Node(0,0);
       latest=new Node(0,0);
       latest->prev=oldest;
       oldest->next=latest; 
    }
    
    int get(int key) {
        if(cache.find(key)!=cache.end()){
            Node* temp=cache[key];
            remove(temp);
            insert(temp);
            return temp->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end()){
            remove(cache[key]);
        }
        Node* newnode=new Node(key,value);
        cache[key]=newnode;
        insert(newnode);
        if(cache.size()>cap){
            Node* lru=oldest->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
    private:
    void insert(Node* node){
        Node* pre=latest->prev;
        latest->prev=node;
        node->prev=pre;
        pre->next=node;
        node->next=latest;

    }
    void remove(Node* node){
        Node* temp1=node->next;
        Node* temp2=node->prev;
        temp1->prev=temp2;
        temp2->next=temp1;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */