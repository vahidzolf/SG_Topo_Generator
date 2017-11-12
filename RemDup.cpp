#include <iostream>
#include <string>
#include <cstdio>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
	ifstream rat;
	const int NUM=300;
	int radio[NUM];
	string line;
	int m=0,temp;
	bool flag=false;
	rat.open("fx.txt");
	ofstream out("out.txt");
	for (int i=0;i<NUM;++i)
	{
		radio[i]=-1;
	}
	while (getline(rat,line))
	{
		istringstream iss(line);
		iss >> temp;
		if(m==0)
		{
			radio[m]=temp;
			m++;
			continue;
		}
		for(int i=0;i<m;++i)
		{
			if(radio[i]==temp)
			{
				flag=true;
				break;
			}
		}
		if(!flag)
		{
			radio[m]=temp;
			m++;
		}
		flag=false;
	}
	for (int i=0;radio[i]!=-1;++i)
	{
		out << radio[i]<< endl;
	}
	out.close();
	rat.close();
	return 0;
}
