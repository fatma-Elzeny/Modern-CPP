#include <iostream.h>

#include <conio.h>

class point
{

private:
    int x, y;

public:
    point()
    {

        x = y = 0;

        cout << "point default constructor is calling " << endl;
    };

    point(int m)
    {

        x = y = m;

        cout << "point one parameter constructor is calling " << endl;
    };

    point(int a, int b)
    {

        x = a;

        y = b;

        cout << "point Two parameter constructor is calling " << endl;
    };

    ~point()
    {

        cout << "point destructor is calling " << endl;
    }

    void operator()(int a, int b)
    {

        x = a;

        y = b;
    }

    void print() { cout << "\n point Data: x = " << x << " y=" << y << endl; }

    void setX(int m)
    {

        x = m;
    }
    void setY(int n)
    {

        y = n;
    }

    void setXY(int m, int n)
    {

        x = m;

        y = n;
    }

    int getX()
    {

        return x;
    }

    int getY()
    {

        return y;
    }
};

class Line
{

private:
    point start;

    point end;

public:
    Line() : start(), end()
    {

        cout << "\n Line default constructor is calling" << endl;
    }

    Line(int x1, int y1, int x2, int y2) : start(x1, y1), end(x2, y2)
    {

        cout << "\n Line with 4 parameters constructor is calling" << endl;
    }

    Line(point p1, point p2)
    {

        start = p1;
        end = p2;
    }

    ~Line()
    {
        cout << "\n Line destructor is calling" << endl;
    }

    void print()
    {

        cout << "\nStart :";

        start.print();

        cout << "\nEnd :";

        end.print();
    }
};
class circle
{

private:
    point center;

    int rad;

public:
    circle() : center(0)
    {

        rad = 0;

        cout << "\n circle default constructor is calling" << endl;
    }

    circle(int x1, int y1, int r) : center(x1, y1)
    {

        rad = r;

        cout << "\n circle with 3 parameters constructor is calling" << endl;
    }

    ~circle()
    {

        cout << "\n circle destructor is calling" << endl;
    }

    void print()
    {

        cout << "\ncenter:";

        center.print();

        cout << "\n Radius = " << rad << endl;
    }
};

class Rect
{

private:
    point UL;

    point LR;

public:
    Rect() : UL(), LR()
    {

        cout << "\n Rect default constructor is calling" << endl;
    }

    Rect(int x1, int y1, int x2, int y2) : UL(x1, y1), LR(x2, y2)
    {

        cout << "\n Rect with 4 parameters constructor is calling" << endl;
    }

    Rect(point p1, point p2)
    {

        UL = p1;
        LR = p2;
    }

    ~Rect()
    {

        cout << "\n circle destructor is calling" << endl;
    }

    void print()
    {

        cout << "\nUpper Left:";

        UL.print();

        cout << "\nLower Right:";

        LR.print();
    }
};
class Picture
{

private:
    int cNum;

    int rNum;

    int lNum;

    circle *pCircles;

    Rect *pRects;

    Line *pLines;

public:
    Picture()
    {

        cNum = 0;

        rNum = 0;

        lNum = 0;

        pCircles = NULL;

        pRects = NULL;

        pLines = NULL;
    }

    Picture(int cn, int rn, int ln, circle *pC, Rect *pR, Line *pL)
    {

        cNum = cn;

        rNum = rn;

        lNum = ln;

        pCircles = pC;

        pRects = pR;

        pLines = pL;
    }

    void setCircles(int, circle *);

    void setRects(int, Rect *);

    void setLines(int, Line *);

    void print();
};

int main()
{
    Point p1(12, 20);
    p1.print();
    p1(-5, 132);
    p1.print();

    Circle c1(250, 150, 100);
    Rect r1(10, 100, 90, 350);
    Line l1(30, 100, 350, 400);

    c1.print();
    r1.print();
    l1.print();

    Picture myPic1;

    circle cArr[3] = {circle(50, 50, 50), circle(200, 100, 100), circle(420, 50, 30)};

    Rect rArr[2];

    rArr[0] = Rect(30, 40, 170, 100);

    point myP1(420, 50);

    point myP2(500, 300);

    rArr[1] = Rect(myP1, myP2);

    Line *lArr;

    lArr = new Line[2];

    lArr[0] = Line(point(420, 50), point(300, 300));

    lArr[1] = Line(40, 500, 500, 400);

    myPic1.setCircles(3, cArr);

    myPic1.setRects(2, rArr);

    myPic1.setLines(2, lArr);

    myPic1.print();

    delete[] lArr;

    getch();
    return 0;
}
void Picture ::setCircles(int cn, circle *cptr)
{

    cNum = cn;

    pCircles = cptr;
}

void Picture ::setRects(int rn, Rect *rptr)
{

    rNum = rn;

    pRects = rptr;
}

void Picture ::setLines(int ln, Line *lptr)
{

    lNum = ln;

    pLines = lptr;
}

void Picture ::print()
{

    int i;

    for (i = 0; i < cNum; i++)
    {

        pCircles[i].print();
    }

    for (i = 0; i < rNum; i++)
    {

        pRects[i].print();
    }
    for (i = 0; i < lNum; i++)
    {

        pLines[i].print();
    }
}
