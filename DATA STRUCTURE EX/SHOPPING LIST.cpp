#include<iostream>
#include<string>
using namespace std;
#define MAX 10;
class ShoppingList
{
public:
    string b[20],p,e;
    int n,i,pos;
    void storeItems();
    void addItem();
    void removeItem();
    void searchItem();
    void displayItems();
};
void ShoppingList::storeItems()
{
    cout<<"Enter no of items:";
    cin>>n;
    for(i=0; i<n; i++)
    {
        cout<<"Enter the item"<<i+1<<":";
        cin>>b[i];
    }
}
void ShoppingList::addItem()
{
    cout<<"Enter the position where item needs to be added:";
    cin>>pos;
    if(pos>=n)
    {
        cout<<"Invalid location";
    }
    else
    {
        for(i=n-1; i>=pos-1; i--)
        {
            b[i+1]=b[i];
        }
        cout<<"Enter the item to add:";
        cin>>p;
        b[pos]=p;
        n++;
    }
}
void ShoppingList::removeItem()
{
    cout<<"Enter the position of the item to remove:";
    cin>>pos;
    if(pos>=n)
    {
        cout<<"Invalid location";
    }
    else
    {
        for(i=pos+1; i<n; i++)
        {
            b[i-1]=b[i];
        }
        n--;
    }
}
void ShoppingList::searchItem()
{
    cout<<"Enter the item to be searched:";
    cin>>e;
    for(i=0; i<n; i++)
    {
        if(b[i]==e)
        {
            cout<<"Item is found in the position:"<<i;
        }
        else
        {
            continue;
        }
    }
}
void ShoppingList::displayItems()
{
    cout<<"\nThe items in the shopping list are:";
    for(i=0; i<n; i++)
    {
        cout<<b[i]<<" ";
    }
}
int main()
{
    ShoppingList s;
    int ch;
    do
    {
        cout<<"1.Store items\n";
        cout<<"2.Add an item\n";
        cout<<"3.Remove an item\n";
        cout<<"4.Search for an item\n";
        cout<<"5.Display all items\n";
        cout<<"6.Exit\n";
        cout<<"Enter your choice:";
        cin>>ch;
        switch(ch)
        {
        case 1:
            s.storeItems();
            break;
        case 2:
            s.addItem();
            break;
        case 3:
            s.removeItem();
            break;
        case 4:
            s.searchItem();
            break;
        case 5:
            s.displayItems();
            break;
        case 6:
            exit(0);
        }
    }
    while(ch!=6);
    return 0;
}
