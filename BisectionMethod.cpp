#include<iostream>
#include<conio.h>
#include<iomanip>
#include<cmath>

using namespace std;

void inputfunction(float coef[], int deg)
{
    for(int i=0; i<=deg; i++)
    {
        cout<<"Enter coefficient of x^"<<i<<" ";
        cin>>coef[i];
    }
}

double fvalue(double x, float coef[], int deg)
{
    double sum=0;
    for(int i=0; i<=deg; i++)
    {
        sum = sum + (coef[i]*pow(x, i));
    }
    return sum;
}

int main()
{
    int deg;
    cout<<"Enter degree of function:";
    cin>>deg;
    float coef[deg+1];
    inputfunction(coef, deg);
    int i;  
    for(i=0; (fvalue(i, coef, deg)*fvalue(i+1, coef, deg))>0; i++);
    long double xval[2], xnew, xfinal;
    xval[0]=i;
    xval[1]=i+1;
    cout<<"Initial values are: "<<xval[0]<<", "<<xval[1]<<endl;
    cout<<"f("<<xval[0]<<")= "<<fvalue(xval[0], coef, deg)<<endl;
    cout<<"f("<<xval[1]<<")= "<<fvalue(xval[1], coef, deg)<<endl;
    int acc;
    cout<<"Enter degrees of accuracy: ";
    cin>>acc;
    for(int j=0; (xval[1]-xval[0])>=pow(10, -acc); j++)
    {
        xnew = (xval[0] + xval[1])/2;
        cout<<setprecision(acc+3)<<"xnew= "<<xnew<<endl;
        cout<<"f("<<xnew<<")= "<<fvalue(xnew, coef, deg)<<"\n"<<endl;
        if(fvalue(xnew, coef, deg)>0)
            xval[1] = xnew;
        else if(fvalue(xnew, coef, deg)<0)
            xval[0] = xnew;
        else
            xfinal = xnew;
        cout<<setprecision(acc+3)<<"xval[0]= "<<xval[0]<<", xval[1]= "<<xval[1]<<endl;
    }
    xnew = (xval[0] + xval[1])/2;
    xfinal = xnew;
    cout<<"Final value of x= "<<setprecision(acc+3)<<xfinal<<endl;
    getch();
    return 0;
}