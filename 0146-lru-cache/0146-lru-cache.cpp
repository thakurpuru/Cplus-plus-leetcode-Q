class Node{
    public:
    int value;
    int key;
    Node*prev,*next;
    Node(int k,int val){
        key=k;
        value=val;
        prev=NULL;
        next=NULL;
    }
};
class LRUCache {

public:
    int cap;
    unordered_map<int,Node*> cache;
    Node *old;
    Node *lest;
    void insert(Node *node){
        Node* pre=lest->prev;
        pre->next=node;
        node->next=lest;
        lest->prev=node;
        node->prev=pre;
    }
    void remove(Node *node){
        Node* temp=node->prev;
        temp->next=node->next;
        node->next->prev=temp;
        node->next=NULL;
        node->prev=NULL;
    }
    LRUCache(int capacity) {
        cap=capacity;
        old=new Node(0,0);
        lest=new Node(0,0);
        old->next=lest;
        lest->prev=old;
    }
    
    int get(int key) {
        if(cache.count(key)){
            Node *temp=cache[key];
            remove(temp);
            insert(temp);
            return temp->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        Node *temp=new Node(key,value);
        if(cache.count(key)){
            remove(cache[key]);
        }

        cache[key]=temp;
        insert(temp);


        if(cache.size()>cap){
            Node* pre=old->next;
            remove(pre);
            cache.erase(pre->key);

        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */