//перевести мак адреса и найти номер VLAN по номеру необходимого порта у списка ,который выдает команда SNMP

#include <iostream>
#include <cmath>
#include <ctime>
#include <string>
#include <fstream>
#include <cstdlib>


using namespace std;

void  create_number(string str);


int main()
{
	setlocale(LC_ALL,"Russian");
	ifstream in("D:\\ИГУ\\3курс\\Компьютерные сети\\mac.txt");

	//string comand="iso.3.6.1.2.1.17.7.1.2.2.1.2.1.60.30.4.164.178.32 = INTEGER: 19";  //пример входной строки
	string str;				//считываемая строка из файла
	int *Size=new int[2];	//номер порта. 
	int port, Iport=0, VLAN=0;
	char result;
	

	if (!in.is_open())
	{ 
		cout<< "Unable to open text file . "<<endl; 
		return 1; 
	}  
	cout<<"File open"<<endl;

	cout<<"Enter port:"<<endl;
	cin>>Iport;
  
	while (!in.eof()) 
	{
		while (getline(in,str))
		{
			for(int i = str.length()-1; i>-1; i--)	//ищем размер сети в строке
			{
				if(i==str.length()-1)
				{
					port=((int)str[i])-'0';
					
				}
				else if (str[i]==' ')
				{
					if(Iport == port)
					{
						VLAN=str[29];			
						cout<<endl<<"STR: "<<str<<endl;
						cout<<endl<<"	VLAN : "<< VLAN << "  MAC : ";
						create_number(str); /перевод в 16-ую систему 
					}
					port=0;
					break;
				}
				else
				{
					port+=(((int)str[i])-'0')*10; //формируем номер порта
				}
			}
			cout<<endl;
		}
	 }

	in.close();
	system("pause");
	return 0;

}


void create_number(string str)
{
	char string[3] = "";
	char* result = new char[3];
	int number=0;
	int temp=0;
	int size_str=str.length();
	for(int i = 31; i<size_str; i++)	//идем к мак адресу
	{
							
		if(str[i]!=' ')
		{
			if(str[i]!='.')
			{
				number=number*10+((int)str[i])-'0';	//накапливаю многозначное число
			}
			else
			{
				cout<<itoa(number,string,16)<<".";
				number=0;
			}				
		}
		else
		{
			break;
		}
	}
}
