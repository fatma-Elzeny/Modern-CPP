#include <iostream.h>

#include <conio.h>

class complex
{

private:
    float real;

    float imag;

public:
    complex();

    complex(float r);

    complex(float r, float i);

    ~complex();

    void setReal(float r);

    void setImag(float i);

    float getReal();

    float getImag();

    complex add(complex c1);

    complex sub(complex c1);

    void setAll();

    void setAll(float f);

    void setAll(float r, float i);

    void print();

    complex operator+(complex &c)
    {

        complex temp(real + c.real, imag + c.imag);

        return temp;
    }

    complex operator+(float f)
    {

        complex temp(real + f, imag);

        return temp;
    }

    complex &operator++()
    {

        real++;

        imag++;

        return *this;
    }

    complex operator++(int dumy)
    {

        complex temp(*this);

        real++;

        imag++;

        return temp;
    }

    complex &operator=(complex &c)
    {

        real = c.real;

        imag = c.imag;

        return *this;
    }

    complex &operator+=(complex &c)
    {

        real += c.real;

        imag += c.imag;

        return *this;
    }

    int operator==(complex &c)
    {

        if ((real == c.real) && (imag == c.imag))

            return 1;

        return 0;
    }

    operator float()
    {

        return real;
    }

    friend complex operator+(float f, complex &c);

    friend istream &operator>>(istream &in, complex &c);

    friend ostream &operator<<(ostream &out, complex &c);
};

complex add(complex c1, complex c2);

complex substract(complex c1, complex c2);

void main(void)
{

    clrscr();

    Complex myComp1, myComp2(3, 4), resultComp(5);
    myComp1.setReal(7);
    myComp1.setImag(2);
    resultComp = add(myComp1, myComp2);
    resultComp.print();
    resultComp = myComp1.sub(myComp2);
    resultComp.print();

    complex com1, com3;

    complex com2(5, 4);

    com1.setAll(7, 2);

    com3.setAll();

    com3 = com1.add(com2);

    com3.print();

    com3 = com1.sub(com2);

    com3.print();

    com3 = com1 + com2;

    com3.print();

    com3 = com1 + 13.5;

    com3.print();

    com3 = 6.5 + com2;

    com3.print();

    com3 = com1++;

    com3.print();

    com3 = ++com2;

    com3.print();

    com3 = com1;

    com3.print();

    com2 = com3 = com1;

    com3.print();

    com2.print();

    com2 += com1;

    com2.print();

    cout << "c1 equals to c3 ?" << (com1 == com3) << endl;

    if (!(com1 == com2))

        cout << "com1 is not equal to com2" << endl;

    cout << "The float of com1 " << float(com1) << endl;

    float f = (float)com2;

    cout << "The casting of com2 is :" << f << endl;

    cin >> com2;

    cout << com1 << com2 << com3;

    int i;

    complex arr[3] = {complex(2), complex(), complex(5, 7)};

    for (i = 0; i < 3; i++)

        arr[i].print();

    int n;

    complex *cptr;

    cin >> n;

    cptr = new complex[n];

    for (i = 0; i < n; i++)

        cin >> cptr[i];

    for (i = 0; i < n; i++)

        cptr[i].print();

    getch();
}

complex ::complex()
{

    real = imag = 0;

    cout << "\n Default constructor is calling";
}

complex ::complex(float r, float i)
{

    real = r;

    imag = i;

    cout << "\n Constructor with two parameters is calling";
}

complex ::complex(float r)
{

    real = r;

    imag = 0;

    cout << "\n Constructor with one parameter is calling ";
}

complex ::~complex()
{

    cout << "\n Destructor is calling\n ";
}

void complex ::setReal(float r)
{

    real = r;
}
void complex ::setImag(float i)
{

    imag = i;
}

float complex ::getReal()
{

    return real;
}

float complex ::getImag()
{

    return imag;
}

void complex ::print()
{

    if (imag < 0)
    {

        cout << real << " - " << -imag << "i" << endl;
    }
    else
    {

        cout << real << " + " << imag << "i" << endl;
    }
}

complex add(complex c1, complex c2)
{

    complex temp;

    temp.setReal(c1.getReal() + c2.getReal());

    temp.setImag(c1.getImag() + c2.getImag());

    return temp;
}

complex substract(complex c1, complex c2)
{

    complex temp;

    temp.setReal(c1.getReal() - c2.getReal());

    temp.setImag(c1.getImag() - c2.getImag());

    return temp;
}
complex complex ::add(complex c1)
{

    complex temp;

    temp.real = this->real + c1.real;

    temp.imag = this->imag + c1.imag;

    return temp;
}

complex complex ::sub(complex c1)
{

    complex temp;

    temp.real = this->real - c1.real;

    temp.imag = this->imag - c1.imag;

    return temp;
}

void complex ::setAll()
{

    real = imag = 0;
}
void complex ::setAll(float f)
{

    real = f;

    imag = f;
}

void complex ::setAll(float r, float i)
{

    real = r;

    imag = i;
}
istream &operator>>(istream &in, complex &c)
{

    cout << "\n Enter real part :";

    in >> c.real;

    cout << "\n Enter imag part : ";

    in >> c.imag;

    return in;
}

ostream &operator<<(ostream &out, complex &c)
{

    if (c.imag < 0)
    {

        out << c.real << " - " << -c.imag << "i" << endl;
    }
    else
    {

        out << c.real << " + " << c.imag << "i" << endl;
    }
    return out;
}
