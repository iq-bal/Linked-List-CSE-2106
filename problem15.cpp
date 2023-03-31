/*
15. Write a C++ program to create and display a doubly linked list. 
*/

#include<iostream>

using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node *prev; 
    Node(int e){
        data = e; 
        next = nullptr;
        prev = nullptr; 
    }
};

void createList(Node **head, int x){
    Node * ptr = new Node(x);
    if(*head==nullptr)  *head = ptr; 
    else{
        Node *temp = *head;
        while (temp->next!=nullptr)
        {
            temp = temp->next; 
        }
        temp->next = ptr;
        ptr->prev = temp; 
    }
}

void printList(Node **head){
    Node *ptr = *head;
    while (ptr!=nullptr)
    {
        cout<< ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<< endl; 
}

int main(){
    int n;  cin>>n;
    Node *head = nullptr; 
    while (n--)
    {
        int e;  cin>>e;
        createList(&head,e); 
    }
    printList(&head); 
    return 0;
}