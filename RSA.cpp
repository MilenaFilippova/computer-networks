#include <iostream>
#include <math.h>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

bool TestIsPrime (int n);
int evkl(int a, int b);
int main()
{
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

	system("pause");
    return 0;
}

//Алгоритм Евклида. Алгоритм для нахождения наибольшего общего делителя двух целых чисел. 


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
