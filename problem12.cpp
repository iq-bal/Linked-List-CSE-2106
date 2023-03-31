/*
@author: _slytherin7
Write a C++ program to delete the last node of a Singly Linked List
*/
#include<iostream>

using namespace std;

class Node{
public:
    int data;
    Node *link; 
    Node(int e){
        data = e; 
        link = nullptr; 
    }
};

void createList(Node **head, int data){
    Node *ptr = new Node(data);
    if(*head==nullptr)  *head = ptr;
    else{
        Node *temp = *head;
        while (temp->link!=NULL)
        {
            temp = temp->link;
        }
        temp->link = ptr; 
    }
}

void deleteLast(Node **head){
    Node *ptr = *head,*src;
    while (ptr->link!=nullptr)
    {
        src = ptr; 
        ptr = ptr->link; 
    }
    src->link = nullptr; 
}

void printList(Node **head){
    Node *ptr = *head; 
    while (ptr!=nullptr)
    {
        cout<< ptr->data<<" ";
        ptr = ptr->link;
    }
    cout<< endl; 
}

int main(){
    Node *head;
    head = nullptr; 
    int n;  cin>>n;
    for (int i = 0; i < n; i++)
    {
        int e;  cin>>e;
        createList(&head,e);
    }
    deleteLast(&head); 
    printList(&head); 
    return 0;
}