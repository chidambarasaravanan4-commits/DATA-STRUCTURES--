#include<iostream>
using namespace std;

int top=-1;

class browser
{
public:
string history[100];
void visit(string);
string back();
void display();
};

void browser::visit(string page)
{
if(top==99)
{
cout<<"History is full";
exit(1);
}
else
{
top=top+1;
history[top]=page;
}
}

string browser::back()
{
if(top==-1)
{
cout<<"History is empty";
exit(1);
}
else
{
return(history[top--]);
}
}

void browser::display()
{
int i;
cout<<"Browser history:";
for(i=top;i>=0;i--)
{
cout<<history[i]<<" ";
}
}

int main()
{
browser b;
string page,removed;
int ch;
do
{
cout<<"1.Visit page\n2.Back\n3.Display history\n4.Exit\n";
cout<<"Enter your choice:";
cin>>ch;

switch(ch)
{
case 1:
cout<<"Enter the page:";
cin>>page;
b.visit(page);
break;

case 2:
removed=b.back();
cout<<"Back from:"<<removed;
break;

case 3:
b.display();
break;

case 4:
exit(0);
}
}while(ch!=4);

return 0;
}
