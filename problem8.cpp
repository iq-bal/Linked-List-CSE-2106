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

void nthNode(Node **head,int n){
    Node *ptr = *head;
    int i=1;
    while (i!=n)
    {
        ptr= ptr->link; 
        i++; 
    }
    cout<< ptr->data<<endl; 
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
    nthNode(&head,3);    
}