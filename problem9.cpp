/*

Write a C++ program to get Nth node in a given Singly Linked List.

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

void insertFirst(Node **head, int e){
    Node *ptr= new Node(e);
    ptr->link = *head;
    *head = ptr; 
}

void insert_at(Node **head, int pos, int e){
    Node *ptr = new Node(e); 
    Node *temp = *head, *src;
    int i=1;
    if(pos==1)    {insertFirst(head,e); return;}
    while (i!=pos)
    {
        src = temp; 
        temp= temp->link; 
        if(temp->link==nullptr) {createList(head,e); return;}
        i++;
    }
    src->link = ptr; 
    ptr->link = temp; 
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
    insert_at(&head,5,100);
    printList(&head); 
}