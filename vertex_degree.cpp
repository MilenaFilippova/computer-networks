#Для каждой вершины необходимо вывести её степень.

#include <iostream>
#include <locale.h>
#include <cctype>
#include <string>
#include <fstream>

using namespace std;

struct Pair 
{
	long int A;
	long int B;
};

int main()
{
	ifstream in("D:\\ИГУ\\3курс\\Компьютерные сети\\vertex.txt");

	long int N;	//число вершин
	in>>N;
	long int E;
	in>>E;		//число ребер

	if (!in.is_open())
	{ 
		cout<< "Unable to open text file . "<<endl; 
		return 1; 
	}  
	cout<<"File open"<<endl;
	
	Pair *V=new Pair[E];	//кол-во ребер
	long int k=1;
	while (!in.eof()) 
	{
		in >> V[k].A;
		//cout<< V[i].A<<" ";
		in >> V[k].B;
		//cout<< V[i].B<<" "<<endl;
		k++;
	}

	//зануляем массив,чтобы там не было мусора
	long int *result =new long int[N];
	for(long int i=1;i<=E;i++)
	{
		result[i]=0;
	}
	//вершина графа-индекс массива.Значение массива- степень вершины
	for(long int i=1;i<=E;i++)
	{
		result[V[i].A]+=1;
		result[V[i].B]+=1;
	}
	for(long int i=1;i<=E;i++)
	{
		cout<<"vertex:"<<i<<"  power="<<result[i]<<endl;
	}
	

	in.close();
	system("pause");
	return 0;
}
