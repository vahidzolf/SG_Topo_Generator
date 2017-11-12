// DGWP.cpp : Defines the entry point for the console application.
//


#include "stdio.h"
#include "stdlib.h"

#include "time.h"
#include "math.h"
#include "iostream"
#include "fstream"
#include "vector"

using namespace std;

static double Distance(int t, int i, double xs[], double ys[])
{
    return sqrt(pow((xs[t] - xs[i]), 2) + pow((ys[t] - ys[i]), 2));
}


int main(int argc, char* argv[])
{
	ofstream cfile;
	ofstream n;
	ofstream rfile;
	rfile.open("r.txt");
	n.open("n.txt");
	cfile.open("c.txt");


	double N_temp = atoi( argv[1] );
	const int N = N_temp;
	double hop_temp = atoi( argv[2] );
	const int hop = hop_temp;
    	const double r =10;
    	
	
	double xs[N];
	double ys[N];

	ifstream xsfile("xs.txt");
	double a = 0;
	int b=0;
	while(xsfile >> a)
	{	
		xs[b] = a;
		b++;		 
	}
	ifstream ysfile("ys.txt");
	a = 0;
	b=0;
	while(ysfile >> a)
	{	
		ys[b] = a;
		b++;		 
	}


    int neighbor[N][2 * N];
    int flag[N];
    int finalflag[N];
    int count[N];
    int AdjMat[N][N];
    int GlobFlag = 0;
    
    for (int k1 = 0; k1 < N; k1++)
        for (int k2 = 0; k2 < 2 * N; k2++)
        {
            count[k1] = 0;
            finalflag[k1] = 0;
            neighbor[k1][k2] = -1;
            if (k2 < N)
                AdjMat[k1][k2] = 0;
        }
    while(GlobFlag==0)
    {
        for (int k = 0; k < N; k++)
            count[k] = 0;
        GlobFlag = 1;
        for (int k1 = 0; k1 < N; k1++)
            for (int k2 = 0; k2 < 2 * N; k2++)
            if(finalflag[k1]==0)
                neighbor[k1][k2] = -1;

        for (int node = 0; node < N; node++)
        {
            if (finalflag[node] == 0)
            {
                for (int k = 0; k < N; k++)
                {
                    
                    flag[k] = 0;
                }

                neighbor[node][0] = node;
                //flag[node] = 1;

                int s = 0;
                int e = 0;
                int h = 0;
                while (h != hop)
                {
                    e++;
                    while (neighbor[node][s] != -1)
                    {
                        for (int i = 0; i < N; i++)
                            if (Distance(neighbor[node][s], i, xs, ys) <= r && flag[i] != 1 && finalflag[i] == 0)
                            {
                                e++;
                                neighbor[node][e] = i;
                                flag[i] = 1;
                                count[node]++;
                                AdjMat[node][i] = 1;
                            }
                        s++;
                    }
                    h++;
                    s++;
                }
            }
        }
		double maxcount=0;
		for (int k = 0; k < N; k++)
			if(maxcount<count[k])
				maxcount=count[k];


        for (int k = 0; k < N; k++)
            if (count[k] == maxcount)
            {
                //cout<<"\n"; 
                //cout<<k + 1;
                //cout<<" -> ";
                finalflag[k] = 1;
                for (int k2 = 1; k2 < 2 * N; k2++)
                    if (neighbor[k][k2] != -1)
                    {
                        finalflag[neighbor[k][k2]] = 1;
                        //cout<<(neighbor[k][k2] + 1);
                        //cout<<" , ";
                    }
                break;
            }

        for (int k = 0; k < N; k++)
            if (finalflag[k] == 0)
                GlobFlag = 0;
    }


   

    for (int k1 = 0; k1 < N; k1++)
            for (int k2 = 0; k2 < N; k2++)
                cfile<<(k1+1)<<" "<<(k2+1)<<" "<<AdjMat[k1][k2]<<endl;

    
    for (int k1 = 0; k1 < N; k1++)
            n<<(k1 + 1)<<endl;

    
    for (int k1 = 0; k1 < N; k1++)
            rfile<<(k1 + 1)<<endl;
    

    /*using (System.IO.StreamWriter file = new System.IO.StreamWriter(@"C:\Users\mandbigS\Desktop\file.txt", true))
    {
        for (int k1 = 0; k1 < N; k1++)
        {
            for (int k2 = 0; k2 < N; k2++)
            {
                file.Write(AdjMat[k1, k2].ToString() + ",");
                if(k2!=N-1)
                    file.Write(AdjMat[k1, k2].ToString() + ",");
            }
            file.Write("\n");
        }
        
    }*/

	cfile.close();
	rfile.close();
	n.close();

	return 0;
}

