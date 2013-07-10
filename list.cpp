#include "List.h"
#include<iomanip>
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

List::List()
{
list =NULL;
cursor = NULL;
size = 0;
}

List::~List()
{
clear();
}
List::List(const List& other){
list = NULL;
cursor = NULL;
*this = other;
}


const List& List::operator =(const List& other) 
{
if (this == &other)
return *this;

if(other.list ==NULL)
{
list = other.list;
size = other.size;
cursor = other.cursor;
}

else{
node*temp =other.list;
while(temp != NULL){
insert(temp ->data);
temp = temp->next;
}
size = other.size;
cursor = other.cursor;  
}
return *this;
}

ostream& operator<<(ostream& out_str,const List& other)
{
List::node *temp = other.list; 
while(temp != NULL)
{
out_str<<temp->data<<endl;
temp = temp->next;
}
return out_str;
}

void List::insert(const int& newData)
{
if(list==NULL){
node*temp = new node(newData);
temp->next = NULL;
cursor =temp;
list = temp;
size++;

}

else if(size ==1){
node*temp = new node(newData);
temp ->next = NULL;
temp ->prev = cursor;
cursor ->next = temp;//this sets the thing that cursor is pointing to to temp
cursor = temp;//this makes cursor point to temp but the previous line made the thing that cursor was previously pointing to point to temp	
cursor->next->prev = temp;
size++;

}


else{
node*temp = new node(newData);
temp ->next = cursor -> next;//the thing that cursor was originally pointing to temp points to
temp->prev = cursor;

cursor->next = temp;//the thing that cursor points to now points to temp
cursor = temp;//this changes the thing that the cursor previusly pointed to but it still points to temp
cursor->next->prev = temp;
size++;
}
}

List::node::node(const int&_data,node*_next,node*_prev )
{
prev = _prev;
data = _data;
next = _next;

}

bool List::isEmpty()
{
if(size ==0){
cout<<"the list is empty"<<"\n";
return true;
}

else{
return false;
}
}
void List::remove()
{
/*
if(isEmpty() == false)
{
node*p;
p = list;
while(p->next != cursor)
{
p = p->next;	
}

cursor = cursor->next;
p = p->next;
delete p;
size--;	
}

*/

if(isEmpty() ==false)
{
if(size==1)
{
delete list;
list=NULL;
cursor = NULL;

}
else if(cursor == list)
{
list=list->next;
delete cursor;
cursor = list;

}

else
{
node*temp = cursor;
goToPrevious();
cursor->next = temp->next;
delete temp;

}



}





return;
}

void List::replace(const int& item )
{
if(isEmpty()== false)
{
cursor->data= item;
}
return;
}

void List::goToFirst()
{
if(isEmpty() == false)cursor = list;
return;
}


void List::goToLast(){
if(isEmpty() ==false)
{
while(cursor->next != NULL)
{
cursor = cursor->next;
}	
}

return;
}
void List::goToNext(){

if(isEmpty() ==false)
   {
if(cursor->next =NULL)
{
cout<<"at end of list"<<"\n";
}
else
{
cursor = cursor->next;
}
}
return;

}

void List::goToPrevious()
{
if(isEmpty() ==false)
{
node*temp =list;
while(temp->next->next!= cursor)
{
temp=temp->next;
}
cursor = temp->next;
}
}
int List::getCurrent()
{
if(isEmpty() ==false)
{
return cursor->data; 
}
else
{
return 0;
}
}

void List::clear()
{
if(isEmpty() ==false)
{
goToFirst();
node*temp =cursor;
while(temp->next != NULL)
{
cursor = cursor->next;
    delete temp;
temp = cursor;
}
size = 0;
return;
}
}



