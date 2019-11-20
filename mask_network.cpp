#include <locale.h>
#include <ctime>
#include <iostream>
#include <math.h>


int convert(struct Mask *test);

using namespace std;

struct Mask
{
    int id[4];
	char byte[7];
	int size;
};

int main(void) 
{
	Mask * test = new Mask[3];
	int flag=0;

	cout<<"Enter nambers:"<<endl;
	cin>>test[0].size;
	if(test[0].size>=0 && test[0].size<=32)//проверка коректности введенных данных
	{
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<8;j++)
			{
				if(flag<test[0].size)
				{
					test[i].byte[j]='1';
					flag++;
				}
				else if(flag<32)
				{
					test[i].byte[j]='0';
					flag++;
				}
				cout<<test[i].byte[j];
			}
				cout<<".";
		}
		 convert(test);
	}

	system("pause");
	return 0;
}


int convert(struct Mask *test)
{
    const int n=7; // n - количество бит, sum это наше десятичное число которое получится из двоичного
	int sum=0,pow2=1; 
	int rezult[3];//маска
	for(int k=3;k>-1;k--)
	{
		for (int i=n;i>-1;i--)
		{
			if(test[k].byte[i]=='1')
			{
				sum+=pow2;
				pow2*=2;
			}
			else
				pow2*=2;
		}
		rezult[k]=sum;
		sum=0;
		pow2=1;
	}
	cout<<endl<<"It is mask: ";
	for(int k=0;k<4;k++)
		cout<<rezult[k]<<".";

    return 0;
}
