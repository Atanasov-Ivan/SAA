#include <iostream>
#include <iomanip> 
using namespace std;
int main()
{
        int n,i,j,br=1,br2=0;
        do{
            cout<<"Vavedete matrica ot 1 do 20 \nn=";
            cin>>n;
         }while((n<1)||(n>20));
        if(n==1) {cout<<1; system("pause"); return(1);}
        int a[n][n], br1=n-1, kontrol=n-1;
        do{
                for (i=br2;i<br1+1;i++)
                {
                    a[i][br2]=br;
                    br++;
                }
                //Слизаме по i-я стълб
                for(j=br2+1;j<br1;j++) 
                {
                    a[br1][j]=br;
                    br++;
                }
                //Вървим по j-я ред
                for(i=br1; i>br2; i--)
                {
                    a[i][br1]=br;
                    br++;
                }
                //Изкачваме се по j-я stylb
                for(j=br1;j>br2;j--)
                {
                   a[i][j]=br;
                   br++;                               
                }
                //Връщаме се по i-q ред
                br1--;
                br2++;
           kontrol--;
        }while(kontrol);
        for (i=0;i<n;i++)
        {
                for (j=0;j<n;j++)
                {
                        cout<<setw(3)<<a[i][j]<<" ";
                }
                cout<<endl;
        }
        system("Pause");
        return 0;
}
