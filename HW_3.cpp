//зад 1 Формирайте стек с + ел-тии да го изведем.
#include<iostream>
using namespace std;
/*
struct a
{
	int number;
	a *next;
}*start = NULL;

void push(int num)
{
	a *p = start;
	start = new a;
	start -> number = num;
	start -> next = p;
}

int pop(int &n)
{
	if(start)
	{
		a *p = start;
		n = start -> number;
		start = start -> next;
		delete p;
		return 1;
	}
	else
		return 0;
}

int main()
{
	int chislo;
	cout << "Vyvejdaneto spira do 0 i propushka otric chisla \n";
	do
	{ cout << "chislo= ";
		cin >> chislo;
		if(chislo > 0)
			push(chislo);
	}while(chislo != 0);

	while(pop(chislo))
		cout<<chislo<<"\t";
	cout<<"\n";
	system("pause");
	return 0;
}
*/


//zad 2 Да се формират 2 стека. 1-ви + ел-ти. 2-ри - ел-ти и да се изведът
/*
struct a
{
	int number;
	a *next;
}*pos = NULL, *neg=NULL;

void push(int num, a *&start)
{
	a *p = start;
	start = new a;
	start -> number = num;
	start -> next = p;
}

int pop(int &n, a *&start)
{
	if(start)
	{
		a *p = start;
		n = start -> number;
		start = start -> next;
		delete p;
		return 1;
	}
	else
		return 0;
}

int main()
{
	int chislo;
	cout << "Vyvejdaneto spira do 0 \n";
	do
	{ cout << "chislo= ";
		cin >> chislo;
		if(chislo > 0)
			push(chislo, pos);
		else
			if(chislo < 0)
			{
				push(chislo, neg);
			}

	}while(chislo != 0);
	cout<<" + el-ti \n\n";
	while(pop(chislo,pos))
		cout<<chislo<<"\t";
	cout<<"\n\n - el-ti \n\n";
	while(pop(chislo,neg))
		cout<<chislo<<"\t";
	cout<<"\n";

	system("pause");
	return 0;
}
*/
//Zad 3 Да се състави ф-я за копиране на стек в др.

struct a
{
	int number;
	a *next;
}*start = NULL, *y = NULL, *help = NULL; 

void push(int num,a *&start)
{
	a *p = start;
	start = new a;
	start -> number = num;
	start -> next = p;
}

int pop(int &n, a *&start)
{
	if(start)
	{
		a *p = start;
		n = start -> number;
		start = start -> next;
		delete p;
		return 1;
	}
	else
		return 0;
}

void copy_stack(a *&start, a *&y)
{ a *help1=NULL;
	int chislo;
	while(pop(chislo,start))
		push(chislo,help1);

	while(pop(chislo,help1))
	{
		push(chislo,y);
		push(chislo,start);
	}
}

int main()
{
	int chislo;
	cout << "Vyvejdaneto spira do 0 i propushka otric chisla \n";
	do
	{ cout << "chislo= ";
		cin >> chislo;
		if(chislo > 0)
			push(chislo, start);
	}while(chislo != 0);

	copy_stack(start , y);

	cout<<"\n\n Stek start \n\n";
	while(pop(chislo,start))
		cout<<chislo<<"\t";

	cout<<"\n\n Stek y \n\n";
	while(pop(chislo,y))
		cout<<chislo<<"\t";

	cout<<"\n";
	system("pause");
	return 0;
}






// 3 bez f-ii
/*
struct a
{
	int number;
	a *next;
}*start = NULL, *y = NULL, *help = NULL; 

void push(int num,a *&start)
{
	a *p = start;
	start = new a;
	start -> number = num;
	start -> next = p;
}

int pop(int &n, a *&start)
{
	if(start)
	{
		a *p = start;
		n = start -> number;
		start = start -> next;
		delete p;
		return 1;
	}
	else
		return 0;
}

int main()
{
	int chislo;
	cout << "Vyvejdaneto spira do 0 i propushka otric chisla \n";
	do{ cout << "chislo= ";
		cin >> chislo;
		if(chislo > 0)
			push(chislo, start);
	}while(chislo != 0);

	//izvlichane
	while(pop(chislo,start))
		push(chislo,help);

	//prezapisvane v glavnite 2 steka
	while(pop(chislo,help))
	{
		push(chislo,y);
		push(chislo,start);
	}

	//izvejdane...
	cout<<"\n\n Stek start \n\n";
	while(pop(chislo,start))
		cout<<chislo<<"\t";

	cout<<"\n\n Stek y \n\n";
	while(pop(chislo,y))
		cout<<chislo<<"\t";

	cout<<"\n";
	system("pause");
	return 0;
}
*/