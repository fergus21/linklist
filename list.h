#pragma once
#include<iomanip>
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class List
{
public:
List();
~List();
List(const List&);
const List& operator = (const List&);
friend ostream& operator<<(ostream&, const List&);
void insert(const int&);
void remove();
void replace(const int& item);
void clear();
void goToFirst();
void goToLast();
void goToNext();
void goToPrevious();
int getCurrent();
bool isEmpty();
private:
class node{
public:
node (const int& data = 0,node*next = NULL,node*prev = NULL);
int data;
node *next;
node*prev;
};

node *list;
int size;
node *cursor;


};
