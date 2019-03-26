#include <iostream>
#include <string>

using namespace std;

template <class T> class CCellDescr
{
	private:

		int column , row ;
		T value;

	public:

		CCellDescr(int kolona , int red , const T& stoinost)//ekspliciten
		{
			column=kolona;
			row=red;
			value=stoinost;
		}

		CCellDescr() : column(-1) , row(-1) , value(T()) {}//podrazbirasht

		CCellDescr(const CCellDescr& from) //kopirasht
		{ 
			column = from.column; 
			row = from.row; 
			value = from.value; 
		} 

		const int GetRow()
			{
				return row;
			}

		const int GetCol()
			{
				return column;
			}

		const T GetVal()
			{
				return value;
			}

		void setValue(const T& value2)
			{
				value=value2;
			}

		friend ostream& operator<<(ostream& stream , const CCellDescr<T>& Cell)
			{
				stream<<Cell.column<<endl;
				stream<<Cell.row<<endl;
				stream<<Cell.value<<endl;
			}

		bool operator>= (const CCellDescr & toCompare)
			{
				return this->value>=toCompare.value;
			}

		
		bool operator== (const CCellDescr & toCompare)
			{
				return this->value==toCompare.value;
			}

		
		bool operator!= (const CCellDescr & toCompare)
			{
				return this->value!=toCompare.value;
			}
		
		bool operator< (const CCellDescr & toCompare)
			{
				return this->value<toCompare.value;
			}

		T operator+(const CCellDescr & Sum)
			{
				return(value+Sum.value);
			}
};

void main()
{
	CCellDescr<string> a (1,2,"123");
	CCellDescr<string> b (4,5,"123567");
	cout<<a+b;

	system("pause");
}