#include<iostream>

using namespace std;

class node{
public:
    int data;
    node *next;
    node *prev;
    node(int d){
        this->data = d;
        this->next = nullptr;
        this->prev = nullptr; 
    }
};

void creation(node **head, int e){
    node *ptr = new node(e);
    if(*head==nullptr)   *head = ptr;
    else{
        node *temp= *head;
        while (temp->next!=nullptr)
        {
            temp = temp->next; 
        }
        temp->next = ptr;
        ptr->prev = temp; 
    }
}

void insertionSort(node **head){
    node *ptr;
    for(ptr=(*head)->next; ptr!=nullptr; ptr=ptr->next){
        int data = ptr->data;
        node *temp = ptr->prev; 
        while (temp!=nullptr && (temp->data)>data)
        {
            swap((temp->next)->data,temp->data); 
            temp= temp->prev; 
        }
    }
}


void display(node **head){
    node *temp = *head;
    while (temp!=nullptr)
    {
        cout<< temp->data<< " "; 
        temp=temp->next;
    }
    cout<< endl; 
}

int main(){
    node *head = nullptr; 
    int n;  cin>>n; 
    while (n--)
    {
        int e;  cin>>e;
        creation(&head,e); 
    }
    insertionSort(&head);
    display(&head); 
}