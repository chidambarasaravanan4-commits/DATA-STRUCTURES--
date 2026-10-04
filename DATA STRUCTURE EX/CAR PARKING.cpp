#include<iostream>
using namespace std;

int top=-1;

class parking
{
public:
    int car[100];
    void enterCar(int);
    int leaveCar();
    void display();
};

void parking::enterCar(int number)
{
    if(top==99)
    {
        cout<<"Parking is full";
        exit(1);
    }
    else
    {
        top=top+1;
        car[top]=number;
    }
}

int parking::leaveCar()
{
    if(top==-1)
    {
        cout<<"Parking is empty";
        exit(1);
    }
    else
    {
        return(car[top--]);
    }
}

void parking::display()
{
    int i;
    cout<<"Cars in the parking:";
    for(i=top; i>=0; i--)
    {
        cout<<"Car"<<car[i]<<" ";
    }
}

int main()
{
    parking p;
    int ch,num1,num2;
    do
    {
        cout<<"1.Enter car\n2.Leave car\n3.Display\n4.Exit\n";
        cout<<"Enter your choice:";
        cin>>ch;

        switch(ch)
        {
        case 1:
            cout<<"Enter the car number:";
            cin>>num1;
            p.enterCar(num1);
            break;

        case 2:
            num2=p.leaveCar();
            cout<<"The car leaving the parking is:Car"<<num2;
            break;

        case 3:
            p.display();
            break;

        case 4:
            exit(0);
        }
    }
    while(ch!=4);

    return 0;
}
