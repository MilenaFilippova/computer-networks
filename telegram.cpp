#include <locale.h>
#include <cctype>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

string get_all_word(istream &is) ;	

int main(void)
{
	
	
	ifstream in("D:\\blokip.txt");


	string str;	//считываемая строка из файла
	int *Size=new int[2];	//размер сети
	int k=1;
	const int bigip=32;	//максимальный размер
	long int sum=0;	//сумма адресов

	if (!in.is_open())
	{ 
		cout<< "Unable to open text file . "<<endl; 
		return 1; 
	}  
	cout<<"File open"<<endl;



	while (!in.eof()) 
	{
		str = get_all_word(in);
		for(int i = str.length()-1; i>-1; i--)	//ищем размер сети в строке
		{
			if(k<0)
				break;
			Size[k]=((int)str[i])-'0';
			k--;
			cout<<"Size[k]	= "<<Size[k+1]<<endl;
		}
		k=1;//для нового размера возращаем исходное значение
		Size[0]=Size[0]*10+Size[1];	//считаем размер сети
		sum+=pow(2.0,(double)bigip-(double)Size[0]);	//накапливаем сумму ip адресов
    }
    
	cout<<"SUM of blocked ip-addresses = "<<sum<<endl;
	in.close();
	system("pause");
	return 0;
}

string get_all_word(istream &is) 
{
    string w;
    is >> w;
    return w;
}
