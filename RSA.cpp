#include <iostream>
#include <math.h>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iomanip>




using namespace std;

bool TestIsPrime (int n);
int evkl(int a, int b);
int mycod(int M, int E, int N);
int mydecod(int C, int D, int N);

int main()
{
	setlocale(LC_ALL,"Russian");
	//два различных случайных простых числа p и q заданного размера
	int p=0, q=0, n=0, f=0;
	int firs_value = 50 , last_value = 1000 ;
	
	//пока они не станут различными и простыми подбераем числа
	while( p == q || TestIsPrime(p) != true || TestIsPrime(q) != true)
	{
		p = firs_value + rand() % last_value;
		q = firs_value + rand() % last_value;
	}
	cout<<"p: "<<p<<endl;
	cout<<"q: "<<q<<endl;
	//Вычисляется их произведение n=p*q, которое называется модулем
	n = p*q;

	//Вычисляется значение функции Эйлера от числа n:
	f = (p - 1)*(q - 1);

	
	//Генерация числа d и проверка его на взаимопростоту
	//с числом f
	int d, d_simple = 0;
	while (d_simple !=1)
	{
		d = rand()%100;
		d_simple = evkl(d, f);
	}
	//Определение числа e, для которого является истинным
	//соотношение (e*d)%f=1.
	unsigned int e = 0, e_simple = 0;
	while (e_simple !=1)
	{
		e += 1;
		e_simple = ((e*d)%f);
	}

	cout<<"n= " <<n<<" f="<<f<< " e= "<<e <<" d= " <<d<<endl;;
    //Сгенерированные ключи.
	cout << "Open key(e,n): "<< e <<" , "<< n <<";"<<endl<<"Close key(d,n): " << d <<" , "<<n<<endl;

	const int size_text=5;
	char* text=new char[size_text];
	cod_text=0;

	cout << "Enter your text:"<<endl;
	cin.get(text, size_text);
	
	//кодирование
	unsigned int *cod_text = new unsigned int [size_text];
	int b=301;
	for(int i=0;i<size_text;i++)
	{
		int ASCIIcode = (int)text[i]+b;
		cod_text[i]=mycod(ASCIIcode, e, n);
		cout<<"Cod text: "<<(char)cod_text[i]<<"  cod_text[i]="<<cod_text[i]<<endl;
		b++;
	}

	
	
	unsigned int* decod_text=new unsigned  int[size_text];

	//декодирование
	b = 301;
	for(int i=0;i<size_text;i++)
	{
		int M=mydecod(cod_text[i], d, n);
		M=M-b;
		decod_text[i]=M;
		b++;
		cout<<"Decod text: "<<(char)decod_text[i]<<"  decod_text[i]= "<<decod_text[i]<<endl;
		
	}


	delete [] text;
	delete [] cod_text;
	delete [] decod_text;
	system("pause");
    return 0;
}

//Алгоритм Евклида. Алгоритм для нахождения наибольшего
//общего делителя двух целых чисел. Используется для проверки
//чисел на взаимопростоту.


int evkl(int a, int b)
{
	int c;
	while (b)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return abs(a);
}


bool TestIsPrime (int n)
{
	bool isPrime=true;

	for (int i=2; i<=sqrt((float)abs(n)); i++)
	{
        if (n%i==0)
		{
			isPrime = false;
			break;
        }
    }
	return isPrime;
}


//Взять открытый ключ (e,n)
//Создать случайный сеансовый ключ m
int mycod(int M, int E, int N)
{
	
	int C=1;
	for(int i=0;i<=E;i++)
	{
		//Зашифровать сеансовый ключ с использованием открытого ключа  m  в степени e
		C = C*M;
		C = C%N;
	}

    return C;
}





int mydecod(int C, int D, int N)
{
	int M=1;
	for(int i=0;i<=D;i++)
	{
		M = M*C;
		M = M%N;
	}
    return M;
}
