#include <iostream>
using namespace std;
/*
//Hanoiska kula
int br=0;
void hanoi(char a, char c, char b, int n)
{ br++;
	if(n==1)
		cout<<"\n Disk "<< n << " from "<< a <<" to "<<c;
	else {
			hanoi(a,b,c,n-1);
			cout<<"\n Disk "<< n << " from "<< a <<" to "<<c;
			hanoi (b,c,a,n-1);
		}
}
int main()
{
	char a='A',b='B', c='C';
	int n;
	do
	{
		cout<<"\nn= ";
		cin>>n;
	}while(n<=0&&n<2);
	hanoi(a,b,c,n);
	cout<<"\n\n Br operacii "<<br<<endl;
	system("pause");
	return 0;
}
*/
//zad 2 Hodove na konq na dyskata
/*
const n=8, maxn=n*n;
int h[n][n]={0};
int dx[]={2,1,-1,-2,-2,-1,1,2};
int dy[]={1,2,2,1,-1,-2,-2,-1};
void print()
{
	for(int i = 0; i < n; i++)
	{
		for(int j=0, j<n; j++)
			cout<<h[i][j]<<"\t";
			cout<<endl;
	}
}
void NextMove (int x, int y,int i)
{
	h[x][y]=i; int newx,newy;
	if(i==naxn)
	{
		print(); return;
	}
	for(int k=0;k<n;k++)
	{
		newx = x+dx[k];
		newy = y+dy[k];
		if(newx >= 0 && newx<n)
	}
}
*/

int a[]
int i=0
delenie(int chislo,int n);

int main()
{
	int Y;
	cout<<"\n Vavedi chislo =";
	cin>>Y;
	delenie (y);

	for(int j=0;j<n;j++)
	{
		cout<<"a["<<j>>"]="<<a[j];
	}
	system("pause");
	return 0;
}

void delenie(int chislo,int n)
{
	if((chislo/10)==0)
	{
		i++;
		a[i]=chislo;
	}
	int z = chislo/10;
	delenie (z, n-1);
}