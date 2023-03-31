/*
16. Write a C++ program to create a doubly linked list of n nodes and display it in reverse order. 
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

void printReverseList(Node **head){
    Node *tail = *head;
    while (tail->next!=nullptr)
    {
        tail = tail->next;
    }
    while (tail!=nullptr)
    {
        cout<< tail->data<< " ";
        tail = tail->prev; 
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
    printReverseList(&head); 
    return 0;
}