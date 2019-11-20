//Граф задан матрицей смежности и числом вершин N.
//Необходимо реализовать обход графа, начиная с вершины K. 
//В результате вывести длину пути до каждой вершины (два числа для каждой вершины: номер вершины, длина пути от вершины K).

#include <iostream>
#include <queue> // очередь


using namespace std;

struct Vertex
{
	char lit;
	int id;
	int len;

};

int main()
{
  queue<int> Queue;

  const int size=6;//кол-во вершин
  int k=1;//счетчик
  int mas[size][size] = 
  { 
	  { 0, 1, 1, 0, 0, 0}, // матрица смежности
	  { 1, 0, 1, 1, 0, 0},
	  { 1, 1, 0, 0, 1, 0},
	  { 0, 1, 0, 0, 1, 1},
	  { 0, 0, 1, 1, 0, 0},
	  { 0, 0, 0, 1, 0, 0}, 
  };
  char liter[]={'A','B','C','D','E','F','G','H','J','K'};
  

  Vertex ver[size];
  int first=0;	//вершина с которой начинаем обход графа
  ver[0].id=first;
  ver[0].len=0;
  ver[0].lit=liter[first];

  
  int nodes[size]; // вершины графа
  for (int i = 0; i < size; i++)
  {
    nodes[i] = 0; // исходно все вершины равны 0
  }
  
  Queue.push(first); // помещаем в очередь первую вершину
  while (!Queue.empty())	// пока очередь не пуста
  { 
	int node = Queue.front(); // извлекаем вершину
	ver[k].lit=liter[node];
    Queue.pop();
    nodes[node] = 2; // отмечаем ее как посещенную
    for (int j = 0; j < size; j++)	// проверяем для нее все смежные вершины
    { 
		if (mas[node][j] == 1 && nodes[j] == 0) // если вершина смежная и не обнаружена
		{ 
			ver[k].id=j;	//присваиваем номер вершине
			ver[k].lit=liter[j];
			for(int j = 0; j < size; j++)	
    		{ 
    			 if(ver[j].id==node)
    			 {
    				 ver[k].len=ver[j].len+1;	//к длине той вершины ,из которой пришли, добавляем 1
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
  for (int j = 0; j < size; j++)	// проверяем для нее все смежные вершины
  { 
	 cout<<"lit= "<<ver[j].lit<<" id="<<ver[j].id<<" len="<<ver[j].len<<endl;
  }

  cin.get();
  return 0;
}
