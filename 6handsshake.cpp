//Проверка теории 6 рукопожатий
//1) Расчёт минимальных расстояний для каждой пары вершин ("персон" 3980.edges

 
#include <iostream>
#include <locale.h>
#include <cctype>
#include <string>
#include <fstream>
#include <queue> // очередь

using namespace std;

struct Rebro 
{
	long int A;
	long int B;
};


struct Vertex
{
	int lit;
	int id;
	int len;

};

int main()
{
		ifstream in("D:\\ИГУ\\3курс\\Компьютерные сети\\6рукопожатий\\3980.edges");
		const int N=57;//4038-3981;	//число вершин
		const int E=292;	//число ребер
		
		
		if (!in.is_open())
		{ 
			cout<< "Unable to open text file . "<<endl; 
			return 1; 
		}  
		cout<<"File open"<<endl;
		Rebro *reb = new Rebro[E];
		//Pair *V=new Pair[E];
		long int k=1;
		while (!in.eof()) 
		{
			in >> reb[k].A;
			//cout<< V[i].A<<" ";
			in >> reb[k].B;
			//cout<< reb[k].A<<" "<< reb[k].B<<endl;
			k++;
		}



		int Matr[N+1][N+1];
		
		for(int i=0;i<=N;i++)	//занулили матрицу
		{
			for(int j=0;j<=N;j++)
			{
				 Matr[i][j]=0;
			}
		}

		for(int i=0;i<=N;i++)	//оболочка для вида в матрице ,это вершины графа (заданы номерами вершин)
		{
			Matr[0][i]=reb[i].A;
			Matr[i][0]=reb[i].B;
		}
		
		for(int i=0;i<=N;i++)
		{
			for(int j=0;j<=N;j++)
			{
				if(Matr[0][i]==reb[i].A && Matr[j][0]==reb[j].B)
				{
					if(reb[i].A>0 && reb[i].B>0 )
					{
						Matr[i][j]=1;
					}
				}
			}
		}
		/*
		for(int i=0;i<=N;i++)	//вывод матрицы
		{
			for(int j=0;j<=N;j++)
			{
				  cout<<Matr[i][j]<<"	";
			}
			cout<<endl;
		}
		*/


	//применяем обход в ширину для поиска растояний между вершинами в графе
	queue<int> Queue;
	const int size=N;	
	Vertex ver[size+1];
	int first=1;	//вершина с которой начинаем обход графа
	ver[0].id=first;
	ver[0].len=0;
	//ver[0].lit=liter[first];


	
	 int nodes[size+1]; // вершины графа
	 for (int i = 0; i <= size; i++)
	 {
		nodes[i] = 0; // исходно все вершины равны 0
	 }
	 
	 Queue.push(first); // помещаем в очередь первую вершину
	 
	 while (!Queue.empty())	// пока очередь не пуста
	 { 
		int node = Queue.front(); // извлекаем вершину
		cout<<"node"<<node<<endl;
		//ver[k].lit=liter[node];
		Queue.pop();
		nodes[node] = 2; // отмечаем ее как посещенную

	 
		for (int j = 1; j <= size; j++)	// проверяем для нее все смежные вершины
		{ 
			if ( Matr[node][j] == 1 && nodes[j] == 0) // если вершина смежная и не обнаружена
			{ 
				ver[k].id=j;	//присваиваем номер вершине
				ver[k].lit=Matr[0][j];
				for(int l = 0; l<= size; l++)	
    			{ 
    				 if(ver[l].id==node)
    				 {
    					 ver[k].len=ver[l].len+1;	//к длине той вершины ,из которой пришли, добавляем 1
						// cout<<"lit= "<<ver[k].lit<<" id="<<ver[k].id<<"ver[k].len "<<ver[k].len<<endl;
    					 break;
    				 }
    			}
				k++;
				Queue.push(j); // добавляем ее в очередь
				nodes[j] = 1; // отмечаем вершину как обнаруженную
			}
		}
	  }
    cout<<"N="<<size<<" . First vert="<<first<<endl;
    //выводим растояние от этой вершины до каждой
    for (int j = 0; j <= size; j++)	// проверяем для нее все смежные вершины
    { 
      cout<<"lit= "<<ver[j].lit<<" id="<<ver[j].id<<" len="<<ver[j].len<<endl;
    }
    cin.get();
    system("pause");
    return 0;
}

