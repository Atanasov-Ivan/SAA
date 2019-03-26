/* Zad.1 Dvoino sv1rzan spisak: */
#include <iostream>

using namespace std;

struct elem
{
	int key;
	elem *next;
	elem *prev;
}  *start = NULL;

void list ()
{
	if(start)
	{
		cout<<"\n List: ";
		elem *p = start;
		while (p)
		{ cout<<p -> key <<"\t";
		p=p -> next;
		}
	}
	else cout<<"\n Empty List";
}

void add_b (int n)
{
	elem *p = start;
	start = new elem;
	start -> key = n;
	start -> prev = NULL;
	start -> next = p;
	if(p)
		p -> prev = start;
}

void add_e(int n)
{
	elem *p = start , *q;
	q = new elem;
	q -> key = n;
	q -> next = NULL;
	if (start == NULL)
		start = q;
	else
	{
		while (p -> next)
			 p -> next;
		p -> next = q ;
	}
	q -> prev = p;
}

void add_bk ( int n, int k )
{
	elem *p = start, *q;
	while ( p -> key != k && p -> next)
		p = p -> next;
	if ( p -> key == k)
	{
		q = new elem;
		q -> next = p -> next;
		q -> prev = p;
		if(p -> next)
		 p -> next -> prev = q;
		p-> next = q;
		q -> key = k;
		p -> key = n;
	}
	else 
		cout<<"\n No k";
}

void add_ak ( int n, int k )
{
	elem *p = start, *q;
	while ( p -> key != k && p -> next)
		p = p -> next;
	if ( p -> key == k)
	{
		q = new elem;
		q -> next = p -> next;
		q -> prev = p;
		if(p -> next)
		 p -> next -> prev = q;
		p-> next = q;
		q -> key = n;
	}
	else 
		cout<<"\n No k";
}

int del_b ( int &n)
{
	if(start)
	{
		elem *p = start;
		n= start -> key;
		start = start -> next;
		if (start)
			start -> prev = NULL;
		delete p;
		return 1;
	}
	else return 0;
}

int del_e (int &n)
{
	if (start)
	{
		if ( start -> next )
		{ 
			elem *p = start;
			while (p -> next)
				n = p -> key ;
			p -> prev -> next = NULL;

			delete p;
		}
		else 
		{
			n = start -> key;
			delete start;
			start = NULL;
		}
		return 1;
	}
	else return 0;
}

int del_k ( int k)
{
	if (start)
	{
		elem *p = start;
		while ( p -> key = k && p -> next )
			p = p -> next ;
		if ( p -> key == k)
		{
			if ( p -> next )
				p -> next -> prev = p -> prev ;
			if (p -> prev)
				p -> prev -> next = p -> next;
			if (p == start )
			{
				start = start -> next;
				start -> prev = NULL;
			}
			delete p;
			return 1;
		}
		else
		{ cout <<"\n No k ";
		return 0;
		}
	}
	else return 0;
}

void invert ()
{
	elem *p = start, *q;
	while (p)
	{ q = p -> next ;
	p -> next = p -> prev ;
	p -> prev = q;
	if ( q == NULL )
		start = p;
	p = q ;
	}
}

int main()
{
int a,k,num ;   
    
cout<<"   MENU       "<<endl;
cout<<"1.Add first"<<endl;
cout<<"2.Add last"<<endl;
cout<<"3.Add before k"<<endl;
cout<<"4.Add after k"<<endl;
cout<<"5.Delete first"<<endl;
cout<<"6.Delete last"<<endl;
cout<<"7.Delete k"<<endl;
cout<<"8.Invert"<<endl;
cout<<"9.List"<<endl;

cout<<"Input your answer: ";
cin>>a;

if ((a>0)&&(a<5)||(a==9))
{
cout<<"Input num: ";
cin>>num;
}

if((a==4)||(a==3)||(a==7))
{
cout<<"Input k: ";
cin>>k;
}

switch(a)
{
case(1): { add_b(num); list(); break; }
case(2): { add_e(num); list();	}
case(3): { add_bk(num,k); list(); break; }
case(4): { add_ak(num,k); list(); break; }
case(5): { del_b(num); list(); break; }
case(6): { del_e(num); list(); break; }
case(7): { del_k(k); list(); break; }
case(8): { invert(); list(); break; } 
case(9): list(); break; 
}

system("pause>null");
system("cls");
return main();
}