
#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
class LinkedList
{
     Node*head;

    public:
    LinkedList()
    {
        head = NULL;
    }

    void insert(int val)
    {
        Node* new_node=new Node;
        new_node->data=val;
        new_node->next=NULL;

        if(head == NULL)
            head = new_node;

        else
        {
            new_node->next=head;
            head=new_node;
        }
   }

bool search(int val)
{
    Node* temp=head;
    while(temp !=NULL)
    {
        if(temp->data==val)
            return true;
        temp=temp->next;
    }
    return false;
}

void remove(int val)
{
    if(head->data == val)
    {
        delete head;
        head = head->next;
        return;
    }

    if (head->next==NULL)
    {
        if(head->data==val)
        {
            delete head;
            head=NULL;
            return;
        }
        cout<<"Value is not found:"<<endl;
        return;
    }

        Node* temp=head;
        while(temp->next!=NULL)
        {
            if(temp->next->data == val)
            {
                Node* temp_ptr = temp->next->next;
                delete temp->next;
                temp->next = temp_ptr;
                return;
            }
            temp = temp->next;
        }
        cout<<"Value is not found:"<<endl;
}

void display()
{
    Node* temp=head;
    while(temp !=NULL)
        {
            cout<<temp->data<<"  ";
            temp=temp->next;
        }
    cout<<endl;
}
};

int main()
{
    LinkedList l;
    l.insert(11);
    l.insert(78);
    l.insert(98);
    l.insert(25);
    l.insert(23);
    l.insert(45);
    cout<<"current linked list:";
    l.display();

    cout<<"Deleting 98: ";
    l.remove(98);
    l.display();

    cout<<"Deleting 25: ";
    l.remove(25);

    cout<<"Searching for 78: ";
    cout<<l.search(78)<<endl;

    cout<<"Searching for 45: ";
    cout<<l.search(45)<<endl;
}
