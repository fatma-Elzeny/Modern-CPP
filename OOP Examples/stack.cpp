#include <iostream.h>

#include <conio.h>

class stack

{
private:
    int top;

    int size;

    int *ptr;

    static int counter;

public:
    int isFull();

    int isEmpty();

    static int getCounter()
    {

        return counter;
    }
    stack()
    {

        top = 0;

        size = 10;

        ptr = new int[size];

        counter++;

        cout << "\n this is the default constructor" << endl;
    }

    stack(int n)
    {

        top = 0;

        size = n;

        ptr = new int[size];

        counter++;

        cout << "\n this is the one parameter constructor" << endl;
    }

    stack(stack &s)
    {

        top = s.top;

        size = s.size;

        ptr = new int[size];

        counter++;

        for (int i = 0; i < top; i++)

            ptr[i] = s.ptr[i];
    };

    ~stack()
    {

        delete[] ptr;

        size = 0;

        counter--;

        cout << "\n this is the destructor" << endl;
    }

    int push(int n);

    int pop(int &n);

    friend void veiwContent(stack &s);


    stack& operator= ( stack & c){

	 if(this != &c){

	  top=c.top;

	  size = c.size;

	  delete [] ptr;

	  ptr = new int[size];

	  for(int i=0 ; i <top;i++){

		  ptr[i] = c.ptr[i];

	  }

	  }
	return *this;

	 }
};

void main(void)
{

    clrscr();

    cout << "\n The number of objects created = " << stack ::getCounter();
    stack s1(10);

    stack s2(7);

    s1.push(37);

    s1.push(-12);

    s1.push(26);

    veiwContent(s1);
    cout << "\n The number of objects created = " << stack ::getCounter();

    if (s1.pop(num))
    {

        cout << num << endl;
    }

    if (s1.pop(num))
    {

        cout << num << endl;
    }

    if (s1.pop(num))
    {

        cout << num << endl;
    }
    else
        cout << "\n The stack is empty";

    cout << "\n The number of objects created = " << stack ::getCounter();

    stack s2;

    veiwContent(s2);

    cout << "\n The number of objects created = " << stack ::getCounter();

    s1.push(7);

    s1.push(6);

    veiwContent(s1);

    s2 = s1;

    s2.pop(n);

    cout << "\n"
         << n << endl;

    s1.pop(n);

    cout << n << endl;

    stack s3(s1);

    cout << "\n The number of objects created = " << stack ::getCounter();

    veiwContent(s3);

    veiwContent(s2);
    getch();
}

int stack ::isFull()
{

    return (top == size);
}

int stack ::isEmpty()
{

    return (top == 0);
}

int stack ::push(int n)
{

    if (isFull())

        return 0;

    ptr[top] = n;

    top++;

    return 1;
}

int stack ::pop(int &n)
{

    if (isEmpty())

        return 0;

    top--;

    n = ptr[top];

    return 1;
}
void veiwContent(stack &s)
{

    for (int i = 0; i < s.top; i++)
    {

        cout << "\n Element no (" << i + 1 << ") = " << s.ptr[i];
    }
    cout << "\n";
}