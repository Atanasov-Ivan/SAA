#include<iostream> 
#include<string> 
using namespace std; 
#define MAX_NAME_LEN 30 
enum Gender {male,female,unknown}; 

using namespace std;





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
            case male : 
                strRes = "male"; break; 
            case female : 
                strRes = "female"; break; 

            default : 
                strRes = "unknown"; break; 
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
        setName("mihail	"); 
        setGender("male"); 
        setEgn("9506268227");      
    } 

    ostream& Output(ostream& to) const
    { 
        to<<m_stName<<"\n"; 
        to<<genderToString()<<"\n"; 
        to<<egn<<"\n"; 

        return to; 
    } 

	friend ostream& operator<<(ostream& toStream, const CPerson& pr)
	{

		pr.Output(toStream);
		return toStream;
	}

	void getYMD(const string& strEGN,int &iYear,int &iMonth, int &iDay)const
	{


		string egn=strEGN;
		string sYear=strEGN.substr(0,2);
		string sMonth=strEGN.substr(2,4);
		string sDay=strEGN.substr(4,6);
		iYear= stoi(sYear);
		iMonth= stoi(sMonth);
		iDay= stoi(sDay);

		if(iMonth>40)
		{
			iYear+=2000;
			iMonth-=40;
		}
		else if (iMonth>20 && iMonth<40)
			{
				iYear+=1800;
				iMonth-=20;
			}
		else 
			iYear+=1900;

	}



}; 

class CAddress 
{ 
    string street; 
    string postcode; 
    string city; 

public: 
    CAddress( const string& stStreet, const string& stPostcode, const string& stCity) 
    { 
        street = stStreet; 
        postcode = stPostcode; 
        city = stCity; 
    } 

    CAddress():street("Broduway"),postcode("5249"),city("Varna") {} 

    CAddress(const CAddress& from) 
    { 
        street = from.street; 
        postcode = from.postcode; 
        city = from.city; 
    } 

    ostream& Output(ostream& to) const
    { 
        to<<street<<"\n"; 
        to<<postcode<<"\n"; 
        to<<city<<"\n"; 
        return to; 
    } 

	friend ostream& operator<<(ostream& toStream, const CAddress& addr)
	{

		addr.Output(toStream);
   
		return toStream;
	}

	istream& Input(istream& fro)
	{ 
        fro >> street; 
        fro >> postcode; 
        fro >> city; 
        return fro; 
    } 

    friend istream& operator>>(istream& fromStream, CAddress& addr)
	{ 

        addr.Input(fromStream); 
        return fromStream; 
    } 

}; 

class CStudent: public CPerson 
{ 
    string FacNum; 
    CAddress address; 
    CPerson person; 
public: 

	

	//т 4.
friend void ConsoleInputEGN(CStudent& stud){
	string Con_Facnum;

	cin >> Con_Facnum ;

	stud.FacNum = Con_Facnum;


}

    const string getFacNum() const 
    { 
        return FacNum; 
    } 

    const CAddress getAddres() const 
    { 
        return address; 
    } 

    const CPerson getPerson() const 
    { 
        return person; 
    } 

    void setFacNum(const string& stFacNum) 
    { 
        FacNum = stFacNum; 
    } 

    void setAddress(const CAddress& stAddress) 
    { 
        address = stAddress; 
    } 

    void setPerson(const CPerson& stPerson) 
    { 
        person = stPerson; 
    } 

    CStudent( const string& stFacNum, const CAddress& stAddress, const CPerson& stPerson) 
    { 
        FacNum = stFacNum; 
        address = stAddress; 
        person = stPerson; 
    } 

    CStudent():FacNum(""),address(),person() {} 

    CStudent(const CStudent& from) 
    { 
        FacNum = from.FacNum; 
        address = from.address; 
        person = from.person; 
    } 

    ostream& Output(ostream& to) const
    { 
        to<<FacNum; 
        address.Output(to); 
        CPerson::Output(to); 
         
        return to; 
    } 
	
	//
	friend ostream& operator<<(ostream& toStream, const CStudent& st)
	{

		st.Output(toStream);
		return toStream;
	}

	
	
	/*
	//за сравнение на два студента
	friend ostream& operator==(const CStudent& st1, const CStudent& st2){
		st1.getYMD(st1.egn,int Year, int Mounth, int Day);




	}
	*/
}; 


void main() 
{ /*
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
    p->setGender("male"); 
    cout<<p->getName()<<"\n\n"; 
    cout<<p->getGender()<<endl; 
	*/
    CAddress* a = new CAddress; 
   CAddress	b("Dybrovnik","9900","Varna");

   cout << b << endl;

		


	CPerson p1("Ivan","male","9508191919");
	int year,mouth,day;
	cout << p1;

	string EGN=p1.getEgn();

	p1.getYMD(EGN, year, mouth, day) ;
 
		cout << year  << "	"<<mouth<< "	"<< day  << endl;



	CAddress *k = new CAddress;
	k->Input(cin);
	
	CStudent* s = new CStudent("123123421",*k,p1);
	cout<<"aaaa"<<s;

    system("pause"); 
} 
