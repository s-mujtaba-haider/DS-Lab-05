#include <iostream>
using namespace std;

template<class T>
class LinkedList {
    class Node {
    public:
        T data;
        Node* next;
        Node* prev;
    };
    Node* head;
    Node* tail;
    class iterator {
    public:
        Node* curr;
        iterator() {
            curr = nullptr;
        }
        iterator(Node* n)
        {
            curr = n;
        }
        iterator(const iterator& i)
        {
            this->curr = i.curr;
        }
        bool operator== (const iterator& i)
        {
            return this->curr == i.curr;
        }
        bool operator!= (const iterator& i)
        {
            return this->curr != i.curr;
        }
        iterator& operator-- ()
        {
            curr = curr->prev;
            return *this;
        }
        iterator& operator-- (int)
        {
            curr = curr->prev;
            return *this;
        }
        T operator* ()
        {
            return curr->data;
        }
        iterator& operator++ ()
        {
            curr = curr->next;
            return *this;
        }
        iterator& operator++ (int)
        {
            curr = curr->next;
            return *this;
        }
        T operator[] (int index)
        {
            for (int i = 0; i < index; i++)
                curr = curr->next;
            return curr->data;
        }
    };
public:
    LinkedList() {
        head = CreateNode(-1);
        tail = CreateNode(-1);
        head->next = tail;
        head->prev = tail;
        tail->next = head;
        tail->prev = head;
    }
    Node* CreateNode(T val) {
        Node* temp = new Node();
        temp->data = val;
        temp->next = nullptr;
        temp->prev = nullptr;
        return temp;
    }
    void size() {
        iterator i;
        int count = 0;
        for (i = Begin(); i != End(); ++i) {
            count += 1;
        }
        cout << "Size = " << count << endl;
    }
    bool IsEmpty() {
        iterator i;
        int count = 0;
        for (i = Begin(); i != End(); ++i) {
            count += 1;
        }
        if (count == 0) {
            cout << "Linked List is Empty." << endl;
            return true;
        }
        else {
            cout << "Linked List is NOT Empty." << endl;
            return false;
        }
    }
    bool Search(T val) {
        iterator i;
        cout << "Searched : " << val << " | ";
        for (i = Begin(); i != End(); ++i) {
            if (i.curr->data == val) {
                cout << val << " is Present. " << endl;
                return true;
            }
        }
        cout << val << " is not Present. " << endl;
        return false;
    }
    void DeleteElement(T val) {
        Node* ptr = head;
        while (ptr != tail && ptr->next->data != val)
            ptr = ptr->next;
        if (ptr != tail) {
            Node* temp = ptr->next;
            ptr->next = temp->next;
            temp->next->prev = ptr;
            delete temp;
            cout << "Deleted\n";
        }
        else
            cout << "Not Found\n";
    }
    void InsertAtTail(T const val) {
        iterator i;
        i = End();
        i.curr->next = CreateNode(-1);
        i.curr->data = val;
        i.curr->next->prev = tail;
        tail = tail->next;
    }
    iterator Begin() {
        return iterator(head->next);
    }
    iterator RBegin() {
        return iterator(tail->prev);
    }
    iterator End() {
        return iterator(tail);
    }
    iterator REnd() {
        return iterator(head);
    }
    void Push(T val) {
        tail->data = val;
        tail->next = CreateNode(-1);
        tail->next->prev = tail;
        tail = tail->next;
        tail->next = head;
    }
    T Pop(void) {
        if (head->next != tail) {
            Node* temp = head->next;
            T val = temp->data;
            head->next = temp->next;
            temp->next->prev = head;
            delete temp;
            return val;
        }
        return -1;
    }
    void DeleteEven() {
        iterator i;
        for (i = Begin(); i != End(); ++i) {
            int n = i.curr->data;
            int sum = 0;
            int num = 0;
            while (n > 0) {
                num = n % 10;
                n /= 10;
                sum += num;
            }
            if (sum % 2 == 0) {
                i.curr->prev->next = i.curr->next;
                i.curr->next->prev = i.curr->prev;
            }
        }
    }
    void Sum() {
        iterator i;
        int sum = 0;
        for (i = Begin(); i != End(); ++i) {
            int n = i.curr->data;
            sum += n;
        }
        cout << "Sum = " << sum << endl;
    }
    void Swap(Node* a, Node* b) {
        Node* temp = new Node();
        temp = a;
        a = b;
        b = temp;
        delete temp;
    }
    void Product() {
        iterator i;
        int sum = 1;
        for (i = Begin(); i != End(); ++i) {
            int n = i.curr->data;
            sum *= n;
        }
        cout << "Product = " << sum << endl;
    }
    void MoveOccurence(T keyvalue) {

    }
    bool IsPalindrome() {
        iterator i, j;
        for (i = Begin(); i != End();) {
            j = End();
            if (i.curr == j.curr) {
                cout << "Linked List is Palindrome." << endl;
                return true;
            }
            i++;
            j++;
        }
        cout << "Linked List is NOT Palindrome." << endl;
        return false;
    }
    void Print(void) {
        Node* ptr = head->next;
        cout << "Data";
        while (ptr != tail) {
            cout <<" -> " << ptr->data;
            ptr = ptr->next;
        }
        cout << endl;
    }
    void PrintReverse(void) {
        Node* ptr = tail->prev;
        cout << "Data";
        while (ptr != head) {
            cout << " -> " << ptr->data;
            ptr = ptr->prev;
        }
        cout << endl;
    }
    ~LinkedList() {

    }
};
int main() {
    LinkedList<int> l1;
    l1.Push(9); l1.Push(11); l1.Push(34); l1.Push(6); l1.Push(13); l1.Push(21);
    cout << "Given Array :- " << endl << endl;;
    l1.Print();
    cout << endl;
    cout << "Even Numbers Deleted Array :- " << endl << endl;
    l1.DeleteEven();
    l1.Print();
    cout << endl;
    cout << "Reversed Array :- " << endl << endl;
    l1.PrintReverse();
    cout << endl;
    l1.Search(34);
    cout << endl;
    l1.size();
    cout << endl;
    l1.Product();
    cout << endl;
    l1.Sum();
    cout << endl;
    l1.IsEmpty();
    cout << endl;
    cout << endl;
    //l1.Swap();
    l1.IsPalindrome();
    cout << endl;
    cout << endl << endl << endl;
    return 0;
}