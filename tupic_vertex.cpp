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

	
	Pair *V=new Pair[E+1];	//кол-во ребер
	V[0].A=0;
	V[0].B=0;

	long int k=1;
	while (!in.eof() && k<=E) 
	{
		in >> V[k].A;
		//cout<< V[i].A<<" ";
		in >> V[k].B;
		//cout<< V[i].B<<" "<<endl;
		cout<<V[k].A<<"  "<<V[k].B<<endl;
		k++;
	}

	//зануляем массив,чтобы там не было мусора
	long int *result =new long int[N];
	for(long int i=1;i<=N;i++)
	{
		result[i]=0;
	}
	//вершина графа-индекс массива.Значение массива- степень вершины
	for(long int i=1;i<=E;i++)
	{
		result[V[i].A]+=1;
		result[V[i].B]+=1;
	}
	//счетчик тупиков
	int count=0;
	for(long int i=1;i<=N;i++)
	{
		cout<<"vertex:"<<i<<"  power="<<result[i]<<" ";
		if(result[i]==1)
		{
			cout<<"It is a dead end."<<endl;
			count++;
		}
		else 
			cout<<endl;
	}
	if (count==0)
		cout<<"There ara no dead ends in the graph!"<<endl;
	else
		cout<<"Number of dead end:"<<count<<endl;


	in.close();
	system("pause");
	return 0;
}
