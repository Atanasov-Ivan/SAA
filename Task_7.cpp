#include <iostream>

using namespace std;

const int N = 10;

struct elem
{
	char key;
	elem *next;	
} *g1[N], *g2[N], *g3[N];

void init(elem *g[N])
{
	for (int i = 0; i < N; i++)
		g[i] = NULL;
}

int search_node(char c, elem *g[N])
{
	for (int i = 0; i < N; i++)
		if (g[i])
			if (g[i]->key == c)
			{
				return 1;
			}

	return 0;
}

int search_arc(char from, char to, elem *g[N])
{
	if (search_node(from, g) && search_node(to, g))
	{
		int i = 0;

		while (g[i]->key != from) i++;

		elem *p = g[i]->next;

		while (true)
		{
			if (p == NULL)
			{
				break;
			}

			if (p->key == to)
			{
				return 1;
			}

			p = p->next;
		}
	}

	return 0;
}

void add_node(char c, elem *g[N])
{
	if (search_node(c, g))
		cout << "Node already exists.\n";

	int i = 0;
	while (g[i] && (i < N)) i++;

	if (g[i] == NULL)
	{
		g[i] = new elem;
		g[i]->key = c;
		g[i]->next = NULL;
	}
	else
	{
		cout << "Maximum nodes reached.\n";
	}
}

void add_arc(char from, char to, elem *g[N])
{
	if (search_arc(from, to, g))
		cout << "Arc already exists.\n";
	else
	{
		if (!search_node(from, g))
			add_node(from, g);

		if (!search_node(to, g))
			add_node(to, g);

		int i = 0;
		while (g[i]->key != from) i++;

		elem *p = new elem;
		p->key = to;
		p->next = g[i]->next;

		g[i]->next = p;
	}
}

void print(elem *g[N])
{
	for (int i = 0; i < N; i++)
		if (g[i] != NULL)
		{
			elem *p = g[i];

			while (p)
			{
				cout << p->key << "\t";
				p = p->next;
			}

			cout << endl;
		}
}

void merge_graph(elem **g1, elem **g2, elem **g3)
{
	for (int i = 0; i < N; i++)
		if (g1[i])
		{
			elem *p = g1[i];
			char from;

			if (p != NULL)
			{
				from = p->key;
				p = p->next;
			}

			while (p)
			{
				add_arc(from, p->key, g3);
				p = p->next;
			}

			cout << endl;
		}

	for (int i = 0; i < N; i++)
		if (g2[i])
		{
			elem *p = g2[i];
			char from;

			if (p != NULL)
			{
				from = p->key;
				p = p->next;
			}

			while (p)
			{
				add_arc(from, p->key, g3);
				p = p->next;
			}

			cout << endl;
		}
}

int main()
{
	cout << "Init: " << endl;
	init(g1);
	init(g2);
	
	cout << "Add arc graph 1: " << endl;
	add_arc('a', 'c', g1);
	add_arc('a', 'd', g1);
	add_arc('d', 'b', g1);

	cout << "Graph 1: " << endl;
	print(g1);
	
	cout << "Add arc graph 2: " << endl;
	add_arc('c', 'a', g2);
	add_arc('a', 'd', g2);
	add_arc('a', 'b', g2);
	
	cout << "Graph 2: " << endl;
	print(g2);

	merge_graph(g1, g2, g3);
	
	cout << "Graph 3: " << endl;
	print(g3);

	system("pause");
	return 0;
}
