/*
6. Write a C++ program to find the middle element of a given Linked List. Go to the editor
*/
#include<iostream>

using namespace std;

class Node{
public:
    int data;
    Node *link;
    Node(int e){
        data = e;
        link=nullptr; 
    }
};

void createList(Node **head,int e){
    Node *ptr = new Node(e);
    if(*head==nullptr)  *head = ptr;
    else{
        Node *temp = *head;
        while (temp->link!=nullptr)
        {
            temp=temp->link;
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

void printMidElement(Node **head){
    int n = nodeCount(head); 
    n = (n+2-1)/2;
    Node *pt = *head; 
    int i=1; 
    while (i!=n)
    {
        pt = pt->link; 
        i++;
    }
    cout<< pt->data << endl; 
}

int main(){
    Node *head = nullptr; 
    int n;  cin>>n;
    while (n--)
    {
        int e;  cin>>e;
        createList(&head,e); 
    }
    printMidElement(&head); 
}