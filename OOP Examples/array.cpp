#include <iostream.h>

#include <conio.h>

class MyArray{

 private:

   int size;

   int * data;

 public:


	MyArray(int size ){


	  this->size =size;

	   data = new int [size];



	}

	~MyArray(){

	   delete [] data;


	}

  int & operator [] (int index)

  {
	  if(index<size) {

		return data[index];

	  }else{

		  cout<<"Array out of boundaries Exception";



	  }




  }


};



void main(void){

	clrscr();

	int i ;

	MyArray arr(5);

   cout<<"\n ENTER 5 ELEMENTS\n";

	for( i =0 ;i<5;i++)

	   cin>>arr[i];

	   cout<<"\n"<<endl;

	for( i =0 ;i<5;i++){

	   cout<<arr[i];
	   cout<<"\n"<<endl;


	}




	getch();




}