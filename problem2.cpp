/*
2. Write a C++ program to create a singly linked list of n nodes and display it in reverse order. 
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

void ReverseList(Node **head){
    Node *current = *head, *next = nullptr, *prev = nullptr;
    while (current!=nullptr)
    {
        next = current->link;
        current->link = prev; 
        prev=current;
        current = next; 
    }
    *head = prev; 
}

void printList(Node **head){
    Node *temp = *head;
    while (temp!=nullptr)
    {
        cout<< temp->data<<" ";
        temp=temp->link; 
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
    ReverseList(&head); 
    printList(&head);
}