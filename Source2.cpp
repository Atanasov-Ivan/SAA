#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

const int MAX = 30;

class CCellDescrBase 
{
protected:
		 string m_str_val; 
		 int m_row;
		 int m_col; 

	
		CCellDescrBase ()
		{
			m_str_val = "default";
			m_row = -1;
			m_col = -1;
		}

		CCellDescrBase (const string &stoinost, int red, int kolona )
		{
			m_str_val = stoinost;
			m_row = red;
			m_col = kolona;
		}

		CCellDescrBase (const CCellDescrBase & c)
		{
			m_str_val = c.m_str_val;
			m_row = c.m_row;
			m_col = c.m_col;
		}

		int getRow() const
		{
			return m_row;
		}

		int getCol() const
		{
			return m_col;
		}

		void setRow(int red)
		{
			if(red<0)
				throw ("Nevaliden red!");
			else
				m_row = red;
		}
			
		void setCol(int kolona)
		{
			if(kolona<0)
				throw ("Nevalidna kolona!");
			else
				m_col = kolona;
		}
		public:
		virtual ostream& Output(ostream& toStream) = 0;		/*{			toStream<<m_str_val;			toStream<<m_row;			toStream<<m_col;			return toStream;		}*/
};

 class CCellDescrInteger : public CCellDescrBase 
 {

	 public:
		 CCellDescrInteger():CCellDescrBase(){}

		 CCellDescrInteger(const string &stoinost, int red, int kolona ):CCellDescrBase(stoinost,red,kolona ){}

		 CCellDescrInteger(const CCellDescrInteger & c):CCellDescrBase(c){}

		  ostream & Output(ostream& toStream)		{			cout<<"Integer Object: ";			toStream<<getValue();			toStream<<m_row;			toStream<<m_col;			return toStream;		}

		  CCellDescrInteger & operator = (const CCellDescrInteger & c)
		  {
			m_str_val = c.m_str_val;
			m_row = c.m_row;
			m_col = c.m_col;
			return *this;
		  }

		  int getValue() const
		  {
			return stoi(m_str_val);
		  }

		  bool operator == (const CCellDescrInteger & c)
			{
				return getValue()==c.getValue();
				
			}

		 bool operator < (const CCellDescrInteger & c)
			{
				return getValue()<c.getValue();
				
			}

		friend ostream& operator<<(ostream& toStream, const CCellDescrInteger & c)
		{

			c.Output(toStream);
			return toStream;
		}


 };

  class CCellDescrString : public CCellDescrBase 
 {

	 public:
		 CCellDescrString():CCellDescrBase(){}

		 CCellDescrString(const string &stoinost, int red, int kolona ):CCellDescrBase(stoinost,red,kolona ){}

		 CCellDescrString(const CCellDescrInteger & c):CCellDescrBase(c){}

		  ostream & Output(ostream& toStream)		{			cout<<"String Object: ";			toStream<<m_str_val;			toStream<<m_row;			toStream<<m_col;			return toStream;		}

		  CCellDescrString & operator = (const CCellDescrString& c)
		  {
			m_str_val = c.m_str_val;
			m_row = c.m_row;
			m_col = c.m_col;
			return *this;
		  }


		  bool operator == (const CCellDescrString & c)
			{
				return m_str_val==c.m_str_val;
				
			}

		 bool operator < (const CCellDescrString & c)
			{
				return m_str_val<c.m_str_val;
				
			}

		friend ostream& operator<<(ostream& toStream, const CCellDescrString & c)
		{

			c.Output(toStream);
			return toStream;
		}
  };

void main()
{
	 CCellDescrBase *ptr[MAX];
	 for(int i=0;i<MAX;i++)
		 {
		if(i<15)
			ptr[i]=new CCellDescrInteger();
		 else
			 ptr[i]=new CCellDescrString();
	 }


	system ("pause");
}