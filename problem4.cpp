/*
4. Write a C++ program to insert a new node at the beginning of a Singly Linked List. 
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

void createList(Node **head, int e){
    Node *ptr = new Node(e);
    if(*head==nullptr)  *head = ptr;
    else{
        Node*temp= *head;
        while (temp->link!=nullptr)
        {
            temp=temp->link; 
        }
        temp->link = ptr; 
    }
}

void insertBegin(Node **head, int e){
    Node *ptr = new Node(e);
    ptr->link = *head;
    *head = ptr; 
}

void printList(Node **head){
    Node *ptr = *head;
    while (ptr!=nullptr)
    {
        cout<< ptr->data<< " ";
        ptr= ptr->link; 
    }
    cout<< endl; 
}

int main(){
    Node *head = nullptr; 
    int n;  cin>>n;
    while (n--)
    {
        int e;  cin>>e;
        createList(&head,e); 
    }
    insertBegin(&head,6);
    printList(&head); 
    return 0;
}