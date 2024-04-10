#include<bits/stdc++.h>
#include<omp.h>
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

    int *a,n;
    clock_t start, end;clock_t start, end;
    cout<<"\n enter total no of elements=>";
    cin>>n;
    a=new int[n];
    cout<<"\n enter elements=>";
    for(int i=0;i<n;i++)
    {
   	 cin>>a[i];
    }
    start = clock();
    bubble(a,n);
    end = clock();
    
    
    cout<<"\n sorted array is=>";
    for(int i=0;i<n;i++)
    {
   	 cout<<a[i]<<endl;
    }

    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	    cout << "Time taken by program is : " << fixed << time_taken << setprecision(5);
	    cout << " sec " << endl;
return 0;
}


