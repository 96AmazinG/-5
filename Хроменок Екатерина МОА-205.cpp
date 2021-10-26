#include <iostream>
#include <math.h>

using namespace std;

const double Pi = 3.14, Fi = ( 1+sqrt(5) ) / 2;

class Figure
{
    public:

        virtual double Calc_Square() = 0;

        virtual Figure* GetType() = 0;

        virtual ~Figure() {cout<<"\n- Дест. Figure() -";}

};

class Circle: public Figure
{
    private:

        double r;

    public:

        Circle();
        Circle(double);

        ~Circle();


        virtual double Calc_Square();
        virtual Figure* GetType()
        {
            return new Circle(r);
        }

};

class Triangle: public Figure
{
    private:

        double a,b,c;

        bool Check(double ,double , double);

    public:

        Triangle();
        Triangle(double ,double ,double );
        
        ~Triangle();
        
        virtual double Calc_Square();
        virtual Figure* GetType()
        {
            return new Triangle(a, b, c);
        }

};

class Star: public Figure
{
    private:

        double d; // Длинна луча

    public:

        Star();
        Star(double);

        ~Star();

        virtual double Calc_Square();
        virtual Figure* GetType()
        {
            return new Star(d);
        }

};

class Cylinder
{
    private:

        Figure* f;
        double h;

    public:

        Cylinder(double, Figure*);

        double CalcValume();
    
};



Circle::Circle()
{
     
    cout<<"\n- Конструктор Circle -";
    r = 4;
        
}

Circle::Circle(double new_r)
{
    if( new_r > 0)
    {
        cout<<"\n- Конструктор Circle() -";
        r = new_r;
    }
    else
    {
        cout<<"\n Неверное значение! ";
        return;
    }
}

Circle::~Circle()
{
    cout<<"\n- Дест. Circle() -";
}

double Circle::Calc_Square()
{
    return r*r * Pi;
}



bool Triangle::Check(double a, double b, double c)
{
    if ( c<a+b && a<b+c && b<c+a)
    {
        return true;
    }
    else
    {
        cout<<"\n\n * Неверные значения! ";
        return false;
    }
}

Triangle::Triangle()
{
     cout<<"\n- Конструктор Tringle -";
     a=3;
     b=4;
     c=5;
}

Triangle::Triangle(double new_a, double new_b, double new_c)
{
    if( Check(new_a,new_b,new_c) )
    {
        cout<<"\n- Конструктор Tringle() -";
        a=new_a;
        b=new_b;
        c=new_c;
    }

    else
        return;
    
}

Triangle::~Triangle()
{
    cout<<"\n- Дест. Triangle() -";
}

double Triangle::Calc_Square()
{   
    double p = (a+b+c) / 2;

    return sqrt( p* (p-a)*(p-b)*(p-c) );  
}



Cylinder::Cylinder(double new_h, Figure* new_f)
{
    h = new_h;
    f = new_f->GetType();
}

double Cylinder::CalcValume()
{
    return h *(f->Calc_Square());
}


Star::Star()
{
    cout<<"\n- Конструктор Star -";
    d = 5;
    
}

Star::Star(double new_d)
{
    if( new_d > 0)
    {
        cout<<"\n- Конструктор Star() -";
        d = new_d;
    }
    else
    {
        cout<<"\n Неверное значение! ";
        return;
    }
}

Star::~Star()
{
    cout<<"\n- Деструктор Star() -";
}

double Star::Calc_Square()
{

    double AreaPentagon = (5 * d * d) / (4 * tan(Pi / 5) ); 


    double c = Fi * d;          

    double p = (d+c+c) / 2;  

    double AreaTriangle = sqrt( p * (p-c)*(p-c)*(p-d) );  

    
    return AreaPentagon + AreaTriangle * 5;
    
}

short int MENU();

int main()
{
    system("chcp 1251"); system("cls");

    double S;
    Figure* f;
    Cylinder* c;

    int v; 

    v = MENU();

    if( v == 1)
    {
        double a,b,c;
        cout<<"\n\n Введите стороны треугольника\n";
        cin>> a >> b >> c;

        f = new Triangle(a,b,c);
       
    }
    if( v == 2)
    {
        double r;
        cout<<"\n\n Введите радиус \n";
        cin>> r;

        f = new Circle(r);
        
    
    }
    if( v == 3 )
    {
        double d;
        cout<<"\n\n Введите длинну луча\n";
        cin>> d;

        f = new Star(d);
    }

    cout<<"\n Введите высоту: ";
    cin>>v;

    c = new Cylinder(v, f);


    delete f;
    //f = new Circle(1); 


    S = c->CalcValume(); 
    cout<<endl<<"\n Обьем фигуры = "<<S<<endl;
    

    return 0;
}


short int MENU()
{
    short int v;

    cout<<"\n    __ Выбирете фигуру __"
        <<"\n\n 1.) Треугольник"
        <<"\n 2.) Круг"
        <<"\n 3.) Правильная звезда"
        <<"\n\n #>";

    cin>> v;
    return v;
}
