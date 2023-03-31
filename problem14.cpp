/*
@author: _slytherin7
14. Write a C++ program to find the kth node of a linked list by starting at the middle and moving towards the head. 
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
    while (ptr->link!=nullptr)
    {
        ptr=ptr->link;
        cnt++;
    }
    return cnt; 
}

void kthNodeValue(Node **head,int k){
    int n = nodeCount(head);
    int m = (n+2-1)/2; 
    int p = m-k;
    int i=1;
    Node *ptr=*head;
    while (i!=p)
    {
        ptr=ptr->link;
        i++; 
    }
    cout<< ptr->data<<endl;
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
    kthNodeValue(&head,2); 
    return 0;
}