/*

Write a C++ program to insert a new node at the middle of a given Singly Linked List.

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

int nodeCount(Node **head){
    Node *ptr = *head;
    int cnt =0; 
    while (ptr!=nullptr)
    {
        ptr = ptr->link;
        cnt++; 
    }
    return cnt; 
}

void insertMiddle(Node **head,int e){
    Node *ptr = new Node(e);
    Node *temp = *head, *src;
    int n = nodeCount(head);
    n = (n+2-1)/2;
    int i=1;
    src = temp->link; 
    while (i!=n)
    {
        temp = temp->link; 
        src = temp->link;
        i++; 
    }
    temp->link = ptr;
    ptr->link = src; 
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
    insertMiddle(&head,100); 
    printList(&head);    
}