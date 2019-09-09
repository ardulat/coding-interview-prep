// https://leetcode.com/problems/design-linked-list/

class MyLinkedList {
private:
    struct Node {
        int val;
        Node *next;
        Node(int x): val(x), next(NULL) {}
    };
    
    Node *head;
    int size;
    
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = NULL;
        size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        cout << "get\t" << "size = " << size << endl;
        if (index >= size || index < 0)
            return -1;
        
        int idx = 0;
        Node *temp = head;
        while (idx < index) {
            temp = temp->next;
            idx++;
        }
        
        return temp->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        cout << "addAtHead\t" << "size = " << size << endl;
        Node *temp = new Node(val);
        temp->next = head;
        head = temp;
        size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        cout << "addAtTail\t" << "size = " << size << endl;
        addAtIndex(size, val);
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        cout << "addAtIndex\t" << "size = " << size << endl;
        if (index <= 0) {
            addAtHead(val);
            return;
        }
        else if (index > size)
            return;
        
        Node *prev = head;
        int idx = 0;

        while (idx < index-1) {
            prev = prev->next;
            idx++;
        }

        Node *temp = new Node(val);
        temp->next = prev->next;
        prev->next = temp;
        
        size++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        cout << "deleteAtIndex\t" << "size = " << size << endl;
        if (index < 0 || index >= size)
            return;
        if (index == 0) {
            head = head->next;
            return;
        }
        
        Node *prev = head;
        int idx = 0;
        while (idx < index-1) {
            prev = prev->next;
            idx++;
        }
        
        prev->next = prev->next->next;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */