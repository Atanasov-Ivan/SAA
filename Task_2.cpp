//Да се състави рекурсивна функция, която създава масив ор цели цтйности, отговарящи на цифрите на дадено число.
//Пример:32167 a[0]=3, a[1]=2, a[2]=1, a[3]=6, a[4]=7
#include <iostream>

using namespace std;

int i = 0,p(0);

int * a;

void A(int number)
{
	if((number / 10) != 0)
	{ 
		i++;
		A(number / 10);
	}
	if((number / 10) == 0) 
	{
		i++;
		a = new int[i];
		p=i;
	}

	a[i - p] = number % 10;
	p--;
}

int main()
{

	int n;
	cout<<"Enter number = ";
	cin>>n;

	A(n);
	for(int j=0; j< i ; j++)
	{
		cout<<"a["<<j<<"]= "<<a[j];
		if(j<i-1) cout<<", ";
	}

	cout<<endl;

	system("pause");
	return 0;
}