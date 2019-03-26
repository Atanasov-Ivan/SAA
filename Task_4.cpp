#include <iostream>
using namespace std;

struct elem
{
	int key;
	elem *next;} *first=NULL, *last=NULL;

void push(int n)
{
	elem *p;
	p=last;
	last=new elem;
	last->key=n;
	last->next=NULL; 
	if (p!=NULL)
		p->next=last;
	if (first==NULL) first=last;
}

int pop(int &n)
{
	elem *p;
	if (first)
	{
		
		n=first->key;
		p=first;
		first=first->next;
		if (first==NULL) last=first;
		
		delete p;
		return 1;
	}
	else return 0;
}

void deleteN(int n, int &br)
{
	int num;
	for (int i=br; i > 0 ; i--)
	{
		pop(num);
		if(i != n) push(num);
		else cout<<" Изтритият елемент е: "<<num<<endl;
	}
}

void main()
{system("chcp 1251");//Кирилизатор
	int br = 0, n;
	int Nmbr = 1;

    while(Nmbr != 0)
    {
		cout<<" Число ["<<br+1<<"]= ";
		cin>>Nmbr;
		if(Nmbr != 0){ push(Nmbr); br++;}
    }

	do {
	cout<<"Кой елемет да се изтрие от зад на пред:  "; 
	cin>>n;

	if (n>br) cout<<"Няма такъв елеметн!!";
	} while (n>=br);

	deleteN(n,br);

	for (int i=0;i<br-1;i++)
	{
		pop(Nmbr);
		cout << Nmbr << "\n";
	}
	system("pause");
}