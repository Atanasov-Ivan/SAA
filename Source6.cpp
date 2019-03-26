#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class CBirthDate
{
private:
	unsigned m_uday , m_umonth , m_uyear;

public:
	CBirthDate()
	{
		m_uday = 01;
		m_umonth = 01;
		m_uyear = 1900;
	}

	CBirthDate(unsigned d ,unsigned m ,unsigned y)
	{
		
		m_uday = d;
		m_umonth = m;
		m_uyear = y;
	}

	CBirthDate(const CBirthDate & copy)
	{
		
		m_uday = copy.m_uday;
		m_umonth = copy.m_umonth;
		m_uyear = copy.m_uyear;
	}

	const int GetDay()
			{
				return m_uday;
			}

	const int GetMonth()
			{
				return m_umonth;
			}
	const int GetYear()
			{
				return m_uyear;
			}

	void setDay(unsigned d)
			{
				m_uday = d;
			}

	void setMonth(unsigned m)
			{
				m_uday = m;
			}

	void setYear(unsigned y)
			{
				m_uday = y;
			}

	bool operator== (const CBirthDate & toCompare)
			{
				if(this->m_uyear == toCompare.m_uyear)
					if(this->m_umonth == toCompare.m_umonth)
						if(this->m_uday == toCompare.m_uday)
							return 1;
						else
							return 0;
					else 
						return 0;
				else
					return 0;
			}

	bool operator> (const CBirthDate & toCompare)
			{
				if(this->m_uyear > toCompare.m_uyear)
					if(this->m_umonth > toCompare.m_umonth)
						if(this->m_uday > toCompare.m_uday)
							return 1;
						else
							return 0;
					else 
						return 0;
				else
					return 0;
			}

	bool operator< (const CBirthDate & toCompare)
			{
				if(this->m_uyear < toCompare.m_uyear)
					if(this->m_umonth < toCompare.m_umonth)
						if(this->m_uday < toCompare.m_uday)
							return 1;
						else
							return 0;
					else 
						return 0;
				else
					return 0;
			}

	friend ostream& operator<<(ostream& stream , const CBirthDate& date)
			{
				stream<<date.m_uday<<endl;
				stream<<date.m_umonth<<endl;
				stream<<date.m_uyear<<endl;
				return stream;
			}

	friend istream& operator>>(istream& stream , CBirthDate& date)
			{
				stream>>date.m_uday;
				stream>>date.m_umonth;
				stream>>date.m_uyear;
				return stream;
			}
};

class CStudent
{
	private:
		string m_sname;
		CBirthDate rd;

	public:
		CStudent()
		{
			m_sname = "";
			rd.setDay(01);
			rd.setMonth(01);
			rd.setYear(1900);
		}

		CStudent(string & n , CBirthDate & r)
		{
			m_sname = n;
			rd = r;
		}

		CStudent(const CStudent& copy)
		{
			m_sname = copy.m_sname;
			rd = copy.rd;
		}
		
		void setData(unsigned day, unsigned  mesec, unsigned year)
			{
				rd.setDay(day);
				rd.setMonth(mesec);
				rd.setYear(year);
			}

		void setName(string name){
			m_sname = name ;
		}

	const	bool operator< (const CStudent & toCompare)
			{
				return this->rd < toCompare.rd;				
			}

	const	bool operator> (const CStudent & toCompare) 
			{
				return this->rd > toCompare.rd;				
			}

		friend bool operator== (CStudent &ob1, CStudent &ob2) 
			{
				if((ob1.m_sname == ob2.m_sname) && (ob1.rd == ob2.rd))
					return 1;
				else
					return 0;				
			}

		friend ostream& operator<<(ostream& stream , const CStudent& date)
			{
				stream<<date.m_sname<<endl;
				stream<<date.rd<<endl;
				return stream;
			}

		friend istream& operator>>(istream& stream , CStudent& date)
			{
				stream>>date.m_sname;
				stream>>date.rd;
				return stream;
			}
};

int  main()
{
	fstream oFileIn("Tema8.txt" , ios::in);

	fstream oFileOut("Tema8out.txt" , ios::out| ios::app);

	CStudent Stud[2];
	string name;
	int day,mounth,year,br(0);

	while(oFileIn << name  << day << mounth << year){
	
		cout << Stud[br];
	
	}





	oFileIn.close();
	oFileOut.close();
system ("pause");
return 0 ;
}