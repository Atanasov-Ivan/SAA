#include<iostream> 
#include<string> 
using namespace std; 

#define MAX_NAME_LEN 30 
enum Gender {male,female,unknown}; 

class CAddress
{
	string m_stStreet;
	string m_stCode;
	string m_stCity;

public:

	ostream& Output(ostream& to)
	{
		to<<m_stStreet;
		to<<m_stCode;
		to<<m_stCity;
		return to;
	}

	CAddress(const string& s , const string& cd,const string& ct) 
    { 
       m_stStreet = s;
       m_stCode = cd; 
       m_stCity = ct; 
    } 

	CAddress()
	{
		m_stStreet = "";
		m_stCode = ""; 
		m_stCity = ""; 
	}

	CAddress(const CAddress& from)
	{
		m_stStreet = from.m_stStreet;
		m_stCode = from.m_stCode;
		m_stCity = from.m_stCity;
	}
};

CAddress Address("Stydentska" , "9000" , "Varna");

class CPerson 
{ 
    string m_stName; 
    Gender gender; 
    string egn; 


    string genderToString() const 
    { 
        string strRes = "Default"; 
        switch(gender) 
        { 
            case male : strRes = "male"; break; 
                case female : strRes = "female"; break; 
                        default : strRes = "unknown"; break; 
        } 
        return strRes; 
    } 
     
    void stringToGender(const string& strGender) 
    { 
        if(strGender == "male") 
            gender = male; 
        else if(strGender == "female") 
            gender = female; 
        else 
            gender = unknown; 

    } 

public: 

    const string getName() const 
    { 
        return m_stName; 
    } 

    const string getGender() const 
    { 
        return genderToString(); 
    } 

    const string getEgn() const 
    { 
        return egn; 
    } 

    void setName(const string& stName) 
    { 
        m_stName = stName; 
    } 

    void setGender (const string& gender) 
    { 
        stringToGender(gender); 
    } 

    void setEgn(const string& stEgn) 
    { 
        egn = stEgn; 
    } 


    CPerson(const string& n , const string& g,const string& e) 
    { 
        setName(n); 
        setGender(g); 
        setEgn(e); 
    } 

    CPerson() 
    { 
        setName(""); 
        setGender(""); 
        setEgn("");     
    } 
}; 

class CStudent:public CPerson
{
	string m_stFNomer;
	CAddress m_stAddress;

public:

	 const string getNomer() const 
    { 
        return m_stFNomer; 
    } 

    void setNomer(const string& stNomer) 
    { 
        m_stFNomer = stNomer; 
    } 

	CStudent(const string& f , const CAddress& a) 
    { 
       m_stFNomer = f;
       m_stAddress = a; 
    } 

	CStudent()
	{
		m_stFNomer = "";
		m_stAddress; 
	}

	CStudent(const CStudent& from)
	{
		m_stFNomer = from.m_stFNomer;
		m_stAddress = from.m_stAddress;

	}

};

CPerson oPersonG("Donika","female","5893"); 
void main() 
{ 
    cout<<oPersonG.getName()<<endl; 
    cout<<oPersonG.getGender()<<endl; 
    cout<<oPersonG.getEgn()<<endl; 

    CPerson oPersonLocal; 
    oPersonLocal.setName("Ivan"); 
    oPersonLocal.setGender("male"); 
    cout<<oPersonLocal.getName()<<"\n\n"; 
    cout<<oPersonLocal.getGender()<<endl; 

    CPerson* p = new CPerson; 
    p->setName("Georgi"); 
    p->setGender("female"); 
    cout<<p->getName()<<"\n\n"; 
    cout<<p->getGender()<<endl; 

    system("pause>null"); 
} 