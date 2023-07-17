#include "header.h"

bool List::isEmpty(){
    return (head == NULL && tail == NULL);
}

Node *List::createNode(Student data){
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void List::addFirst(Student data){
    Node *newNode = createNode(data);
    if(isEmpty) head = tail = newNode;
    else{
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void List::insertAmongList(Student data, int index){
    if(isEmpty()) addFirst(data);
    else{
        Node *newNode = createNode(data);
        if(index < 0) return;
        else if(index == 0) addFrist(data);
        else{
            Node *cur = head;
            for(int i = 0; i < index - 1 && cur != NULL;; i++){
                cur = cur->next;
            }
            newNode->next = cur->next;
            // nếu là vị trí cuối
            cur->next->prev = (cur->next == NULL) ? cur : newNode;
            cur->next = newNode;
            newNode->prev = cur;
            // không cần trỏ cur = newNode 
        }
    }
}

// pop
void List::deleteFirst(){
    if(isEmpty()) return;
    else {
        Node *temp = head;
        head = temp->next;
        if (head != NULL) head->prev = NULL;
        else tail = NULL;
        delete temp;
    }
}

List *List::createList(){
    List *newList = new List;
    newList->head = newList->tail = NULL;
    return newList;
}


// Nối node
Node *List::merge(Node *first, Node *second){
    if(!first) return second;
    if(!second) return first;

    if(first->data < second->data){
        first->next = merge(first->next, second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    } else [
        second->next = merge(first, second);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    ]
}

// Đệ quy đến khi còn 2 node thì so sánh và nối node 
Node *List::mergeSort(Node *head){
    if(!head || !head->next) return head;
    Node *second = split(head);

    head = mergeSort(head);
    second = mergeSort(second);

    return merge(head, second);
}

// Trỏ 1/2 danh sách 
Node *List::split(Node *head){
    Node *fast = head;
    Node *slow = head;

    while(!fast->next || !fast->next->next){
        fast = fast->next->nextj;
        slow = slow->next;
    }
    Node *temp = slow->next;
    slow->next = NULL;
    return temp;
}