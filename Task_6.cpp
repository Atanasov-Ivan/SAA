#include <iostream>

using namespace std;

struct elem
{

	int key;
	elem *left;
	elem *right;
	int bal;

} *root = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;

void add(elem *&t, int n)
{

	if(t == NULL)
	{

		t = new elem;
		t->key = n;
		t->bal = 0;
		t->left = t->right = NULL;

	}
	else
	{

		if(t->key < n)
		{

			if(t->bal != 1)
				t->bal++;
			add(t->right, n);

		}
		else
		{

			if(t->key > n)
			{
			
				if(t->bal != -1)
					t->bal--;
				add(t->left, n);
			
			}

		}

	}

}

void r_rot(elem *&p)
{

	elem *q;
	if(p->bal == -1)
	{

		q = p->left;
		if(q->bal == -1)
		{

			p->left = q->right;
			q->right = p;
			p->bal = 0;
			p = q;

		}

	}

}

void l_rot(elem *&p)
{

	elem *q;
	if(p->bal == 1)
	{

		q = p->right;
		p->right = q->left;
		q->left = p;
		p->bal = 0;
		p = q;

	}

}

void l_r_rot(elem *&p)
{

	elem *q, *s;
	if(p->bal == -1)
	{

		q = p->left;
		if(q->bal == 1)
		{

			s = q->right;
			q->right = s->left;
			p->left = s->right;
			s->left = q;
			s->right = p;
			if(s->bal == -1)
				p->bal = 1;
			else
				p->bal = 0;
			if(s->bal == 1)
				q->bal = -1;
			else
				q->bal = 0;
			p = q;

		}

	}

}

void r_l_rot(elem *&p)
{

	elem *q, *s;
	if(p->bal == 1)
	{

		q = p->right;
		if(q->bal == -1)
		{
			s = q->left;
			p->right = s->left;
			q->left = s->right;
			s->left = p;
			s->right = q;

			if(s->bal == 1)
				p->bal = 1;
			else
				p->bal = 0;
			
			if(s->bal == -1)
				q->bal = 1;
			else
				q->bal = 0;
			p = s;
		}

	}

}

void printnode(int n, int h)
{
     
     for (int i = 0; i < h; i++)
              cout << "\t";
	 cout << n << endl;

}

void show (elem *t, int h)
{
     
     if (t)
	 {
            show (t -> right, h+1);
            printnode(t -> key, h);
            show (t -> left, h+1);
     }

}

void swap(elem *n) 
{
  if(n != NULL) 
  {
    elem *tmp = n->left;
    n->left = n->right;
    n->right = tmp;

    swap(n->left);
    swap(n->right);
  }
}


int main()
{

	int a1[]={7,5,9,3,6,1};
	int a2[]={10,8,12,11,30,40};
	int a3[]={25,20,30,10,22,21,24};
	int a4[]={5,3,10,8,12,6,9};


	for(int i = 0; i < 6; i++)
		add(r1, a1[i]);
	show(r1, 0);
	r_rot(r1);
	cout << endl << "________________________________________" << endl;
	show(r1,0);
	system("pause");

	for(int i = 0; i < 6; i++)
		add(r2, a2[i]);
	show(r2, 0);
	l_rot(r2);
	cout << endl << "________________________________________" << endl;
	show(r2,0);
	system("pause");

	for(int i = 0; i < 6; i++)
		add(r3, a3[i]);
	show(r3, 0);
	l_r_rot(r3);
	cout << endl << "________________________________________" << endl;
	show(r3,0);
	system("pause");

	for(int i = 0; i < 7; i++)
		add(r4, a4[i]);
	show(r4, 0);
	r_l_rot(r4);
	cout << endl << "________________________________________" << endl;
	show(r4,0);

	system("pause");
	cout << endl << "////////////////////////////////////////" << endl;
	swap(r4);
	show(r4,0);
	system("pause");

	return 0;
	system("pause");
}