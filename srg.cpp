// Smart Meter Random Generator.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <fstream>

using namespace std;


int main(int argc, char* argv[])
{

	int n=0;
	int cln=atoi(argv[1]);
	
	int seed=atoi(argv[2]);
		
	n=cln;

	const int R=100;
	
	int max_dis=10;
	int min_dis=3;

	srand(seed);
	ofstream matlab_file;
	ofstream xs_file;
	ofstream ys_file;
	ofstream n_file;
	xs_file.open ("xs.txt");
	ys_file.open ("ys.txt");
	n_file.open ("N.txt");
	float x[n+1];
	float y[n+1];
	int flag[n+1];
	int fflag=0;
	int flag1=0;
	flag[0]=0;
	x[0]=rand()%R;
	y[0]=rand()%R;
	double dist;
	for(int i=1;i<=n;i++)
	{
		x[i]=0;
		y[i]=0;
		flag[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		//cout<<i<<endl;
		while(fflag==0)
		{
			x[i]=rand()%R;
			y[i]=rand()%R;
			
			for(int j=0;j<i;j++)
			{
				dist=sqrt(pow((x[i]-x[j]),2)+pow((y[i]-y[j]),2));
				if(dist <= max_dis)
				{
					flag1=1;
					fflag=1;
					break;//finding just one node that satisfies the above condition is enough 
				}
			}
			if(!flag1)
				continue;
			for(int j=0;j<i;j++)
			{
				dist=sqrt(pow((x[i]-x[j]),2)+pow((y[i]-y[j]),2));
				if(dist >= min_dis)
				{
					flag[j]=1;// but having a distance farther than the minumum with each previous nodes is inevitable
				}
			}
			for (int m=0;m<i;++m)
			{
				fflag=flag[m] && fflag;
			}
			fflag=flag1 && fflag;
			for (int m=0;m<i;++m)
			{
				flag[m]=0;
			}
			flag1=0;
		}
		fflag=0;
	}
	for(int i=1;i<=n;i++)
		xs_file<<x[i]<<endl;
	for(int i=1;i<=n;i++)
		ys_file<<y[i]<<endl;
	n_file<<n;
	xs_file.close();
	ys_file.close();
	n_file.close();
	return 0;
}

