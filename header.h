#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>
#include "Student.h"
#pragma once

using namespace std;


class Node{
public:
    Student data;
    Node *next = NULL;
    Node *prev = NULL;
};
// 1 string[] quản lí các tên lớp để truy cập các lớp dễ dàng xài vector hoặc con trỏ
// 1 list ~~ 1 class (CNTT/HOH/CSH/....)
class List{
public:
    Node *head;
    Node *tail;

    bool isEmtpy();
    Node *createNode(Student data);
    void addFirst(Student data);
    void insertAmongList(Student data, int index);
    void deleteFirst();    
    void printList();
    
    List *createList();

    Node *merge(Node *first, Node *second);
    Node *mergeSort(Node *head);
    Node *split(Node *head);
    
    ~List();
}