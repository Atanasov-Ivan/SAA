#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

class CPerson
{
	private:
		string m_sname;
		string m_segn;

	public:
		CPerson( ) :  m_sname("Name") , m_segn("1111111111") {}
		CPerson( const string& n ,const string& e) : m_sname(n), m_segn(e) {}
		CPerson( const CPerson& copy ) : m_sname(copy.m_sname), m_segn(copy.m_segn) {}

	bool operator < (const CPerson& compare)
	{
		if( this->m_segn < compare.m_segn)
			return 1;
		else 
			return 0;
	}

	bool operator == (const CPerson& compare)
	{
		if( this->m_segn == compare.m_segn )
			return 1;
		else 
			return 0;
	}

	
	friend ostream& operator<<(ostream& stream , const CPerson& data)
	{
		stream<<data.m_segn<<"   ";
		stream<<data.m_sname<<endl;
		return stream;
	}

	friend istream& operator>>(istream& stream , CPerson& data)
	{
		stream>>data.m_segn;
		stream>>data.m_sname;
		return stream;
	}

};

class CCity
{
	private:
		string m_scity;
		vector <CPerson> oVectPerson;
	public:
		CCity( ) :  m_scity(" ") , oVectPerson(0) {}
		CCity( const string& c ,const vector <CPerson>& v) : m_scity(c), oVectPerson(v) {}
		CCity( const CCity& copy ) : m_scity(copy.m_scity), oVectPerson(copy.oVectPerson) {}

		CCity( const string& fileN )
		{
			fstream ofile;
			ofile.open(fileN , ios::in);
			if(!ofile)
			{
				throw "error";			
			}
			else
			{
				ofile>>m_scity;
				while(!ofile.eof())
				{
					CPerson oPerson;
					ofile>>oPerson;
					oVectPerson.push_back(oPerson);
				}
				sort(oVectPerson.begin() , oVectPerson.end());
			}
		}

	ostream& Output(ostream& to) const
    { 
		to<<m_scity;
		for(int i = 0 ; i<oVectPerson.size() ; i++)
        to<<oVectPerson[i]<<" "; 
        return to; 
    } 

};

int main()
{
	fstream oFileIn("file.txt" , ios::in);
	CCity City[10];

	

	system("pause");
	return 0;
}