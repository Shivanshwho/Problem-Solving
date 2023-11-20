struct Node{
  Node* next;
  Node*prev;
  pair<int,int>keyValue;
    Node(int key,int value)
    {
        keyValue.first=key;
        keyValue.second=value;
        next=NULL;
        prev=NULL;
    }
};
class LRUCache {
public:
    Node*head= new Node(0,0);
    Node*tail = new Node(0,0);
    int maxSize;
    int currSize;
    map<int,Node*>mp;
    LRUCache(int capacity) {
       head->next=tail;
       head->prev=NULL;
       tail->prev=head;
       tail->next=NULL;
       maxSize= capacity;
       currSize=0;
    }
    
int get(int key) {
    if (mp.find(key) != mp.end()) {
        Node* temp = mp[key];
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        
        temp->next = head->next;
        head->next->prev = temp;
        temp->prev = head;
        head->next = temp;
        
        return temp->keyValue.second;
    } else {
        return -1;
    }
}

    
void put(int key, int value) {
    if (mp.find(key) != mp.end()) {
        Node* temp = mp[key];
        temp->keyValue.second = value;
        
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        temp->next = head->next;
        head->next->prev = temp;
        temp->prev = head;
        head->next = temp;
    } else {
        if (currSize == maxSize) {
            mp.erase(tail->prev->keyValue.first);
            tail->prev->prev->next = tail;
            tail->prev = tail->prev->prev;
            currSize--;
        }
        Node* temp = new Node(key, value);
        mp[key] = temp;
        temp->next = head->next;
        head->next->prev = temp;
        temp->prev = head;
        head->next = temp;
        currSize++;
    }
}

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */