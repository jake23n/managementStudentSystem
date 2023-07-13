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
