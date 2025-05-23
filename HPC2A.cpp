#include<iostream>
#include<stdlib.h>
#include<omp.h>
#include <ctime>
using namespace std;

void bubble(int *, int);
void swap(int &, int &);


void bubble(int *a, int n)
{
    for(  int i = 0;  i < n;  i++ )
     {  	 
   	 int first = i % 2; 	 

   	 #pragma omp parallel for shared(a,first)
   	 for(  int j = first;  j < n-1;  j += 2  )
   	   {  	 
   		 if(  a[ j ]  >  a[ j+1 ]  )
   		  {  	 
     			 swap(  a[ j ],  a[ j+1 ]  );
   		  }  	 
   		   }  	 
     }
}


void swap(int &a, int &b)
{

    int test;
    test=a;
    a=b;
    b=test;

}

int main()
{
    int *a, *b; //2. n; //1. n=10000
    //2. cout<<"\nEnter total number of elements => ";
    //2. cin>>n;

    a = new int[n];
    b = new int[n];

    //2. cout<<"\nEnter elements => ";
    for(int i = 0; i < n; i++)
    {
        //2. cin >> a[i];
        //1. a[i]=rand() % 10000
        b[i] = a[i]; // copy for sequential
    }

    double start, end;

    // Sequential Bubble Sort
    start = omp_get_wtime();
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n-i-1; j++)
            if(b[j] > b[j+1])
                swap(b[j], b[j+1]);
    end = omp_get_wtime();
    cout << "\nSequential Bubble Sort Time: " << end - start << " seconds";

    // Parallel Bubble Sort
    start = omp_get_wtime();
    bubble(a, n);
    end = omp_get_wtime();
    cout << "\nParallel Bubble Sort Time: " << end - start << " seconds";

    cout << "\n\nSorted array is => ";
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    
    cout << endl;
    return 0;
}

/*
Program 2 A] Parallel Bubble Sort


gescoe@gescoe:~$ g++ -o gfg -fopenmp HPC2A.cpp 

gescoe@gescoe:~$ ./gfg



 enter total no of elements=>7



 enter elements=>51

11

78

45

23

90

77



 sorted array is=>11

23

45

51

77

78

90

*/
