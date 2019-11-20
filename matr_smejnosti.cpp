//Граф задан числом вершин N и ребрами их связывающими. Каждое ребро задано парой чисел (номерами вершин, которые оно связывает).
//Рёбра вводятся либо с клавиатуры, либо задаются в виде массива размера 2*K, где K - число рёбер.
//Необходимо построить матрицу смежности в виде квадратного массива.


#include <iostream>

using namespace std;

struct Rebro 
{
	int A;
	int B;
};

int main()
{
		const int N=4;	//число вершин
		const int K=4;	//число ребер
		int size=K*2;
		
		Rebro *rebra = new Rebro[size];
		
		rebra[0].A=1;
		rebra[0].B=2;
		rebra[1].A=2;
		rebra[1].B=1;

		rebra[2].A=4;
		rebra[2].B=2;
		rebra[3].A=2;
		rebra[3].B=4;

		rebra[4].A=1;
		rebra[4].B=3;

		rebra[5].A=4;
		rebra[5].B=3;


		int Matr[N+1][N+1];
		
		for(int i=0;i<=N;i++)	//занулили матрицу
		{
			for(int j=0;j<=N;j++)
			{
				 Matr[i][j]=0;
			}
		}

		for(int i=0;i<=N;i++)	//оболочка для вида в матрице ,это вершиныграфа (заданы номерами вершин)
		{
			Matr[0][i]=i;
		}
		for(int j=0;j<=N;j++)
		{
			Matr[j][0]=j;
		}

		for(int i=0;i<=5;i++)
		{
				Matr[rebra[i].A][rebra[i].B]=1;
		}

		for(int i=0;i<=N;i++)	//вывод матрицы
		{
			for(int j=0;j<=N;j++)
			{
				  cout<<Matr[i][j]<<"	";
			}
			cout<<endl;
		}

	system("pause");
	return 0;
}

