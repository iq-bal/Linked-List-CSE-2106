/*
@author: _slytherin7
1. Write a C++ program to delete a node from the middle of Singly Linked List.
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
    int cnt=0;
    Node *ptr = *head; 
    while (ptr!=nullptr)
    {
        ptr=ptr->link;
        cnt++;
    }
    return cnt; 
}

void deleteFromMiddle(Node **head){
    int n = nodeCount(head);
    n = (n+2-1)/2;
    int i=1;
    Node *temp=*head,*src; 
    while (i!=n)
    {
        src = temp; 
        temp=temp->link;
        i++; 
    }
    src->link = temp->link;
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
    
    deleteFromMiddle(&head); 
    printList(&head); 
    return 0;
}