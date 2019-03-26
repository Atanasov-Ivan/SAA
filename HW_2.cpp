//din masiv s - i  el-ti. da se syzdade nov din. masiv s - stoinosti ot pyrviq;
#include <iostream>
using namespace std;
/*
int main()
{
	int n;
	cout<<"n= ";
	cin>>n;
	int* a = new int[n];

	for(int i = 0; i < n; i++)
	{
		cout<<"a["<<i<<"]= ";
		cin >> *(a+i);
	}

	int br=0;

	for(int i = 0; i < n; i++)
		if(*(a+i) < 0) br++;

	int *b = new int [br];
	int br2=0;
	for(int i = 0; i < n; i++)
		if(*(a+i) < 0)
		{
			*(b + br2) = *(a+i);
			br2++;
		}

	for(int i = 0; i < br2; i++)
		cout<<"b["<<i<<"]= "<<*(b+i)<<endl;
	system("pause");
	return 0;
}
*/
// 2 din. masiva da si smenqt stoinostite: 
/*
void swap_arr(int *c, int* d,int n)
{
	int i=0;
	int buf;
	while(i<n)
	{
		buf =*(c+i);
		*(c+i)=*(d+i);
		*(d+i)=buf;
		i++;
	}
}

int main()
{
	int n;
	cout<<"n= ";
	cin>>n;
	int* a = new int[n];
	int* b = new int[n];
	for(int i = 0; i < n; i++)
	{
		cout<<"a["<<i<<"]= ";
		cin >> *(a+i);
	}

	for(int i = 0; i < n; i++)
	{
		cout<<"b["<<i<<"]= ";
		cin >> *(b+i);
	}
	system ("cls");
	cout<<"Normalen vid: \n";
	for(int i = 0; i < n; i++)
	{
		cout<<"a["<<i<<"]= "<<*(a+i)<<" "<<"b["<<i<<"]= "<<*(b+i)<<endl;
	}

	cout<<endl;
	swap_arr(a,b,n);

	cout<<"Razmeneni: \n";
	for(int i = 0; i < n; i++)
	{
		cout<<"a["<<i<<"]= "<<*(a+i)<<" "<<"b["<<i<<"]= "<<*(b+i)<<endl;
	}
	cout<<endl;


	system("pause");
	return 0;
}
*/
//f-q za namirane na broq na chislata po golemi ot sysedite si w din masiv

int broi(int *b,int s)
{
	int br=0;
	for(int i=1 ; i<s-1 ;i++)
		if(( *(b+i) > *(b+(i-1))) && (*(b+i)>*(b+(i+1)))) br++;
	//1-i posleniq ne se proverqvat ( dobavi proverkata :D )
	return br;
}

int main ()
{
	int n;
	cout<<"n= ";
	cin>>n;
	int* a = new int[n];

	for(int i = 0; i < n; i++)
	{
		cout<<"a["<<i<<"]= ";
		cin >> *(a+i);
	}

	cout << broi(a,n)<<endl;

	system("pause");
	return 0;
}