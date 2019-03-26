#include <iostream>

using namespace std;

// 1
struct elem
{

	int key;
	elem *next;

} *start = NULL;

// 2
void list()
{
	if(start)
	{
		cout << "\nThe list: ";
		elem *p = start;
		while(p)
		{
			cout << p->key << " ";
			p = p->next;
		}
	}
	else cout << "\nEmpty list!";
}

// добавяне в началото
// 3
void add_b(int n)
{
	elem *p = start;
	start = new elem;
	start -> key = n;
	start -> next = p;
}

// добавяне в края
// 4
void add_e(int n)
{
	elem *p = start;
	elem *q = new elem;
	q -> key = n;
	q -> next = NULL;
	if(start == NULL)
		start = q;
	else 
		{
			while(p -> next)
				p = p -> next;
				p -> next = q;
		}
}

// 5
void add_ak(int n, int k)
{

	elem *p = start;
	while(p -> key != k && p -> next)
		p = p -> next;
	
	if(p -> key == k)
	{
		elem *q = new elem;
		q -> next = p -> next;
		p -> next = q;
		p -> key = n;
		q -> key = n;
		q -> key = k;
	}
	else
		cout << "\nNo k ";
}

// 6
void add_bk(int n, int k)
{
	elem *p = start;
	while(p -> key != k && p -> next)
		p = p -> next;
	if(p -> key == k)
	{
		elem *q = new elem;
		q -> next = p -> next;
		p -> next = q;
		p -> key = n;
		q -> key = n;
	}
	else
		cout << "\nNo k ";
}

// 7
int del_b(int &n)
{
	if(start)
	{
		n = start -> key;
		elem *p = start;
		start = p -> next;
		delete p;
		return 1;
	}
	else
		return 0;
}

// 8
int del_e(int &n)
{
	if(start)
	{
		elem *p = start;
		elem *q = p;
		if(start -> next)
		{
			while(p -> next)
			{

				q = p;
				p = p -> next;
			}
			q -> next = NULL;
		}
		else
			start = NULL;
		n = p -> key;
		delete p;
		return 1;
	}
	else return 0;
}

// 9
int del_k(int k)
{
	if(start)
	{
		elem *p = start;
		elem *q = p;
		while(p -> key != k && p -> next)
		{
			q = p;
			p = p -> next;
		}

		if(p -> key == k)
		{
			if(start == p)
				start = p -> next;
			else
				q -> next = p -> next;
			delete p;
			return 1;
		}
		else
		{
			cout << "\nNo k ";
			return 0;
		}
	}
	else
		return 0;
}

// 10
int search_elem(int k)
{
	int flag = 0;
	elem *p = start;
	while(p -> key != k && p -> next)
		p = p -> next;
	if(p -> key == k)
		flag = 1;
	return flag;
}
// Ф-я за пренасочване към въвеждане отпред и отзад :Д
void add(int a)
{
	cout << "Do 0 se vyvejda \n";
	int n=1;
	if(a == 1)
	{
		do
		{
			cout << "N= ";
			cin >> n;
			if(n != 0) add_b(n);
		}while(n != 0);
	}
	else
	{
		do
		{
			cout << "N= ";
			cin >> n;
			if(n != 0) add_e(n);
		}while(n != 0);
	}
}

void add_k(int a)
{
	int n,k;

	if(a == 1)
	{
		cout << "N= ";
		cin >> n;
		cout << "K= ";
		cin >> k;
		add_ak(n, k);
	}
	else
	{
		cout << "N= ";
		cin >> n;
		cout << "K= ";
		cin >> k;
		add_bk(n, k);
	}
}

void del(int a)
{

}

int main()
{
	
	char choice;
	int n = 0;
	do
	{
		cout <<"\n";
			cout << "\t\t MAIN MENU\n";
			cout << "\n 1. Add first";
			cout << "\n 2. Add last";
			cout << "\n 3. Add before l ";
			cout << "\n 4. Add after k";
			cout << "\n 5. Del first ";
			cout << "\n 6. Del last";
			cout << "\n 7. Del k";
			cout << "\n 8. List";
			cout << "\n 9. Search k";
			cout << "\n Enter your choice: ";
			cin >> choice;

		switch(choice)
		{

			case '1': add(1); list(); system("pause>null");
				break;
			case '2': add(2); list(); system("pause>null");
				break;
			case '3': add_k(3); list(); system("pause>null");
				break;
			case '4': add_k(4); list(); system("pause>null");
				break;
			case '5': del_b(n); cout << "Del first :" << n << endl; list(); system("pause>null");
				break;
			case '6': del_e(n); cout << "Del last :" << n << endl; list(); system("pause>null");
				break;
			case '7': cout << "Del k :"; cin >> n; del_k(n); list(); system("pause>null");
				break;
			case '8': list(); system("pause>null");
				break;
			case '9': cout << "Search k :"; cin >> n; search_elem(n); list(); system("pause>null");
				break;

		}

	}while(true);


	system("pause");
	return 0;

}
