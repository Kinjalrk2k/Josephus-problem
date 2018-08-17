#include<iostream>

using namespace std;

/* Link list node */
class Node
{
    public:
    int data;
    Node* next;

    Node (int data)
    {
        this->data = data;
        next = NULL;
    }
};

void pointer_swap(Node *a, Node *b)
{
    Node *t;
    t=a;
    a=b;
    b=t;
    //a=a^b;
    //b=a^b;
    //a=a^b;
}

class LinkedList
{
    public:
    Node *head;
    unsigned int llsize;

    LinkedList()
    {
        head = NULL;
        llsize=0;
    }

    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout<<"\b\b  \b\b";
    }

    void print2()
    {
        Node *temp = head;
        for(int i=0; i<llsize; i++)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout<<"\b\b  \b\b";
    }

    void push(int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
        llsize++;
    }

    void lldelete(int pos)
    {
        Node *temp=head;

        // If head needs to be removed
        if (pos == 0)
        {
            head = temp->next;   // Change head
            delete temp;               // free old head
            return;
        }

        if(pos>llsize)
            return;

        for (int i=0; temp!=NULL && i<pos-1; i++)
            temp = temp->next;

        Node *next=temp->next->next;
        delete temp->next;
        temp->next=next;
    }

    /* Function to reverse the linked list with 3 variables*/
    void reverse_3p()
    {
        // Initialize current, previous and
        // next pointers
        Node *current = head;
        Node *prev = NULL, *next = NULL;

        while (current != NULL)
        {
            // Store next
            next = current->next;

            // Reverse current node's pointer
            current->next = prev;

            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
    }

    /*  Function to reverse the linked list with 1 variable*/
    /*  this function doesnt work
    void reverse_1p()
    {
       Node * temp = NULL;

       while (temp->next)
        {
            pointer_swap(head, temp->next);
            pointer_swap(head, temp);
        }

       temp->next = head;
       //head = temp;
       //return temp;
    }
    */

    void circular()
    {
        // declare a node variable start and
        // assign head node into start node.
        Node* start = head;

        // check that while head->next not equal
        // to NULL then head points to next node.
        while (head->next != NULL)
            head = head->next;

        // if head->next points to NULL then
        // start assign to the head->next node.
        head->next = start;
        head=head->next;
    }

    /* Function to print linked list */

};
