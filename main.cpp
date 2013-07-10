#include<iomanip>
#include<iostream>
#include<string>
#include<fstream>
#include"list.h"
using namespace std;

int main()
{
List a,b,c;
cout<<a<<"\n";
a.insert(5);
a.insert(2);
a.insert(9);
cout<<a<<"\n";
a.insert(10);
b=a;
c=List(b);
cout<<b<< c<<"\n";
a.replace(3);
cout<<a<<"\n";
c.getCurrent();
cout<<c<<"\n";
b.goToFirst();
b.getCurrent();
cout<<a<<"\n";
a.clear();
cout<<a<<"\n";
b.clear();
cout<<b<<"\n";
c.clear();
cout<<c<<"\n";




}
