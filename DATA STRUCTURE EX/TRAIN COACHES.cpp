#include<iostream>
using namespace std;

struct node
{
    int coach;
    struct node*next;
};

struct node*first=NULL;
struct node*last=NULL;

class train
{
public:
    void addBeginning(int);
    void addEnd(int);
    void removeCoach(int);
    void display(void);
};

void train::addBeginning(int value)
{
    struct node*newnode;
    newnode=new node;
    newnode->coach=value;
    newnode->next=first;
    first=newnode;
    if(last==NULL)
        last=newnode;
}

void train::addEnd(int value)
{
    struct node*newnode;
    newnode=new node;
    newnode->coach=value;
    newnode->next=NULL;
    if(first==NULL)
    {
        first=newnode;
        last=newnode;
    }
    else
    {
        last->next=newnode;
        last=newnode;
    }
}

void train::removeCoach(int value)
{
    struct node*ptr,*temp;
    if(first==NULL)
    {
        cout<<"Train is empty";
        return;
    }
    if(first->coach==value)
    {
        ptr=first;
        first=first->next;
        if(first==NULL)
            last=NULL;
        delete ptr;
        return;
    }
    temp=first;
    while(temp->next!=NULL&&temp->next->coach!=value)
    {
        temp=temp->next;
    }
    if(temp->next==NULL)
    {
        cout<<"Coach is not present";
        return;
    }
    ptr=temp->next;
    temp->next=ptr->next;
    if(ptr==last)
        last=temp;
    delete ptr;
}

void train::display()
{
    struct node*ptr;
    if(first==NULL)
    {
        cout<<"Train is empty";
        return;
    }
    for(ptr=first; ptr!=NULL; ptr=ptr->next)
    {
        cout<<"Coach"<<ptr->coach<<" -> ";
    }
    cout<<"NULL";
}

int main()
{
    train t;
    int ch,num;

    t.addEnd(1);
    t.addEnd(2);
    t.addEnd(3);
    t.addEnd(4);

    do
    {
        cout<<"\n1.Add a coach at beginning\n";
        cout<<"2.Add a coach at end\n";
        cout<<"3.Remove a coach\n";
        cout<<"4.Display all coaches\n";
        cout<<"5.Exit\n";
        cout<<"Enter your choice:";
        cin>>ch;

        switch(ch)
        {
        case 1:
            cout<<"Enter coach number:";
            cin>>num;
            t.addBeginning(num);
            break;

        case 2:
            cout<<"Enter coach number:";
            cin>>num;
            t.addEnd(num);
            break;

        case 3:
            cout<<"Enter coach number to remove:";
            cin>>num;
            t.removeCoach(num);
            break;

        case 4:
            t.display();
            break;

        case 5:
            exit(0);
        }
    }
    while(ch!=5);

    return 0;
}
