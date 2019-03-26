#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CExamRow
{
	private:
		string m_sname;
		int m_ipoints;
		string m_ssud;

	public:
		CExamRow()
		{
			m_sname = "I.";
			m_ipoints = 0;
			m_ssud = "Create an object.";
		}

		CExamRow(const  string& n , int p ,const string& s )
		{
			m_sname = n;
			m_ipoints = p;
			m_ssud = s;
		}

		CExamRow(const CExamRow & copy)
		{
			m_sname = copy.m_sname;
			m_ipoints = copy.m_ipoints;
			m_ssud = copy.m_ssud;
		}

		friend ostream& operator<<(ostream& stream ,const CExamRow& a )
		{
			stream << a.m_sname << " ";
			stream <<a.m_ipoints << " ";
			stream << a.m_ssud << " ";
			return stream;
		}

		bool operator < (const CExamRow& compare)
		{
			if( this->m_sname < compare.m_sname )
				return 1;
			else 
				return 0;
		}

		bool operator == (const CExamRow& compare)
		{
			if(( this->m_sname == compare.m_sname ) && ( this->m_ssud == compare.m_ssud ))
				return 1;
			else 
				return 0;
		}

		int GetPoints() const
		{
			return m_ipoints;
		}

		static int Points(int p ,const CExamRow& pp)
		{
			return (p+pp.m_ipoints);
		}

};

class CStudent
{
	private:
		string m_sstudent;
		vector <CExamRow> oVectSt;
		int m_isum;

	public:
		CStudent( ) :  m_sstudent(" ") , oVectSt(0) {}
		CStudent( const string& s ,const vector <CExamRow>& v) : m_sstudent(s), oVectSt(v) {}
		CStudent( const CStudent& copy ) : m_sstudent(copy.m_sstudent), oVectSt(copy.oVectSt) {}

	ostream& Output(ostream& to) const
    { 
		for(int i = 0 ; i<oVectSt.size() ; i++)
        to<<oVectSt[i]<<" "; 
        return to; 
    } 

	friend ostream& operator<<(ostream& stream ,const CStudent& a )
	{
		stream << a.m_sstudent << " ";
		stream <<a.m_isum << " ";
		return stream;
	}

	string GetStudent () const
	{
		return m_sstudent;
	}

	int GetSum () const
	{
		return m_isum;
	}

	vector <CExamRow> GetoVectSt () const
	{
		return oVectSt;
	}

	bool operator < (const CStudent& compare)
		{
			if( this->m_isum < compare.m_isum)
				return 1;
			else 
				return 0;
		}

	int examination(vector <CExamRow> v)
	{ int iSUM=0;
	// set_intersection(oVectSt,v);
		return m_isum=iSUM;
	}

};

void main()
{
	system ("pause");
}