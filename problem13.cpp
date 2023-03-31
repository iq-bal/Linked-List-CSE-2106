/*
@author: _slytherin7
Write a C++ program to delete the nth node of a Singly Linked List from the end.
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

void deleteFirst(Node **head){
    *head = (*head)->link; 
}

void deleteNthNode(Node **head,int pos){
    Node *ptr = *head,*src;
    int i=1; 
    if(pos==1)  {deleteFirst(head);return;}
    else{
        while (i!=pos)
        {
            src = ptr;
            ptr= ptr->link;
            i++; 
        }
        src->link = ptr->link;
    }
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
    printList(&head); 
    deleteNthNode(&head,2);
    printList(&head); 
    return 0;
}