#include<iostream>
#include<list>

using namespace std;

//Find the middle element of the Linked List
class Node{
    public:
        int data;
        Node* next;
};
/*
class LinkedList{
    Node* head;
    public:
        LinkedList(){
            head = NULL;
        }
        int calSize();
        int findElement();
        void createLL(int data);
};

int LinkedList::calSize(){
    Node* temp = head;
    int size = 0;
    while(temp != NULL){
        temp = temp->next;
        size++;
    }
    return size/2;
}

void LinkedList::createLL(int data){//Push to rear
    Node* newnode = new Node();
    newnode->data = data;
    newnode->next = NULL;

    if(head == NULL){
        head = newnode;
        return;
    }

    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;
}

int LinkedList::findElement(){
    if(head == NULL) return -1;
    int middleIndex = calSize();

    Node* temp = head;
    int index = 0;

    while(temp != NULL){
        if(middleIndex == index){
            return temp->data;
        }
        temp = temp->next;
        ++index;
    }
    return -1;
}

*/
/*
//Practice Question 2: Find the k'th node from the last of the Linked list

class LinkedList{
    Node* head;
    public:
        LinkedList(){
            head = NULL;
        }
        int calSize();
        void createLL(int data);
        int findKthFromLast(int k);
};

int LinkedList::calSize(){
    Node* temp = head;
    int size = 0;
    while(temp != NULL){
        temp = temp->next;
        size++;
    }
    return size;
}

void LinkedList::createLL(int data){//Push to rear
    Node* newnode = new Node();
    newnode->data = data;
    newnode->next = NULL;

    if(head == NULL){
        head = newnode;
        return;
    }

    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;
}

int LinkedList::findKthFromLast(int k){
    int len = calSize();
    if(k > len || k <= 0) return -1;

    Node* temp = head;
    for(int i=0; i< len - k; ++i){
        temp = temp->next;
    }

    return temp ? temp->data : -1;
}
*/

//practice Question 3: Check whether the linked list is palindrome or not?
class LinkedList{
    Node* head;
    public:
        LinkedList(){
            head = NULL;
        }
        Node* reverse(Node* head);
        void createLL(int data);
        bool checkPalindrome();
};
//Reverse a LL
Node* LinkedList::reverse(Node* head){
    Node* prev = NULL;
    Node* temp = head;
    while(temp != NULL){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

void LinkedList::createLL(int data){//Push to rear
    Node* newnode = new Node();
    newnode->data = data;
    newnode->next = NULL;

    if(head == NULL){
        head = newnode;
        return;
    }

    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;
}

//Slow-Fast Approach..

bool LinkedList::checkPalindrome(){
    if(!head || !head->next) return true;

    Node* slow = head;
    Node* fast = head;

    //Find the middle
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    //Reverse the second half of LL
    Node* newHead = reverse(slow->next);

    //Compare
    Node* first = head;
    Node* second = newHead;
    while(second != NULL){
        if(first->data != second->data){
            reverse(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    return true;
    reverse(newHead);
}


int main(){


    LinkedList ll;

    ll.createLL(10);
    ll.createLL(20);
    ll.createLL(30);
    ll.createLL(20);
    ll.createLL(10);

    // cout<<"Middle Element: "<<ll.findElement()<<endl;

    // cout<<"Searched element is: "<<ll.findKthFromLast(2)<<endl;
    
    if(ll.checkPalindrome()){
        cout<<"The LL is a Palindrome.."<<endl;
    } else
        cout<<"Not a Palindrome..!"<<endl;
    return 0;
}
