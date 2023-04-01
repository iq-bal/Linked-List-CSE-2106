#include<iostream>

using namespace std;

class node{
public:
    int data;
    node *link; 
};

void creation(node **head,int e){
    node *ptr = new node;
    ptr->data = e;
    ptr->link = nullptr;
    if(*head==nullptr)  *head = ptr;
    else{
        node *temp = *head;
        while (temp->link!=nullptr)
        {
            temp=temp->link;
        }
        temp->link = ptr; 
    }
}

void insertionSort(node **head){
    node *temp; 
    for ( temp = *head; temp->link!=nullptr; temp=temp->link)
    {
        node *ptr;
        for ( ptr = temp->link; ptr!=nullptr; ptr=ptr->link)
        {
            if(ptr->data<temp->data){
                int d = ptr->data;
                ptr->data = temp->data;
                temp->data = d ; 
            }
        }
    }
}

void display(node **head){
    node *temp = *head;
    while (temp!=nullptr)
    {
        cout<< temp->data<< " "; 
        temp=temp->link;
    }
    cout<< endl; 
}

int main(){
    node *head =nullptr;
    creation(&head,4);
    creation(&head,2);
    creation(&head,5);
    creation(&head,1);
    insertionSort(&head); 
    display(&head); 
}