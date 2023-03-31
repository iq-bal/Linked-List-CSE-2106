/*
3. Write a C++ program to create a singly linked list of n nodes and count the number of nodes. 
*/

#include<iostream>

using namespace std;

class Node{
public:
    int data;
    Node *link;
    Node(int data){
        data = data;
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

void nodeCount(Node **head){
    Node *ptr = *head;
    int cnt =0; 
    while (ptr!=nullptr)
    {
        ptr = ptr->link;
        cnt++; 
    }
    cout<< "No of Nodes: "<< cnt<< endl;
}

int main(){
    int n;  cin>>n;
    Node *head = nullptr; 
    while (n--)
    {
        int e;  cin>>e;
        createList(&head,e); 
    }
    nodeCount(&head); 
}