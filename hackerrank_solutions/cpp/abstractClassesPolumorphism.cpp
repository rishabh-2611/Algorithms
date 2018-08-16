#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache : public Cache {
    public:
        LRUCache(int v) {
            cp = v;
            head = tail = NULL;
            for (; v > 0; v--) {
                struct Node* node = new Node(0, 0);
                if (!head) head = node;
                if (!tail) tail = node;
                else {
                    tail->next = node;
                    node->prev = tail;
                    tail = node;
                }
            }
        }
        virtual void set(int key, int value) {
            // Overwrite old key
            if (mp[key]) moveToHead(mp[key]);
            // Add new key
            else moveToHead(tail);
            
            head->key = key;
            head->value = value;
            mp[key] = head;
            
            return;
        }
        virtual int get(int key) {
            // Key exist in map, and matches node's key
            if (mp[key] && mp[key]->key == key) {
                moveToHead(mp[key]);
                return mp[key]->value;
            } else {
                set(key, -1);
                return -1;
            }
        }
    protected:
        void moveToHead(struct Node* node) {
            if (node == head) return;
            if (node == tail) tail = node->prev;
            node->prev->next = node->next;
            if (node->next) node->next->prev = node->prev;
            node->next = head;
            node->prev = NULL;
            head->prev = node;
            head = node;
            return;
        }
};

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
