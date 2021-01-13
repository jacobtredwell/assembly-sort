#include <iostream>
#include <string.h>
#include <string> 
#include <time.h>
#include <fstream>
#include <array>
using namespace std;

//==========================================================================================
//==========================================================================================

void home_page();						//initializes function
void load_file(int a[]);					//initializes function
void BubbleSort (int a[], int length);				//initializes function
void InsertionSort(int a[], int n);				//initializes function
extern "C" int bubbleSort(int a[], int length);			//initializes external function
extern "C" int insertionSort(int a[], int length);		//initializes external function
void ClearScreen();						//initializes function
  
int n;								//integer n to be used for array index
const int SIZE = 200000;					//SIZE of array
int integers[SIZE];						//initializes integers array		
int fileNum;

clock_t cBubbletime;						//int clock time for bubble c++
clock_t cInsertiontime;						//int clock time for insertion c++
clock_t asmBubbletime;						//int clock time for asm bubble 
clock_t asmInsertiontime;					//int clock time for inseration asm
    


//==========================================================================================
//==========================================================================================

int main()							//starts main menu function
{

    home_page();						//calls home_page menu function
	
	
}

//==========================================================================================
//==========================================================================================

void BubbleSort (int a[], int length)				//define bubblesort c++
{
	
    cout << endl << "Sorting 200,000 integers...." << endl;     //notify user what is happending
	
	
  
    time_t start, end;						//start time
    time(&start);
	
    int i, j, temp;						//variables to use for indices
	
    for (i = 0; i < length; i++)				//outer for loop  i
    {
        for (j = 0; j < length - i - 1; j++)			//inner for loop j
        {
            if (a[j + 1] < a[j])		
            {
                temp = a[j];					//swap if a[j+1] < a[j]
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    
  
    time(&end);							//end time
    cBubbletime = double(end - start);				//calculate end - start
    
    ofstream myfile("cpp_bubbleSort_output.txt");		//output text file
    if (!myfile)
    {
						//deal with error
	return;
	
    }
	
    for (int index = 0; index < 200000; index++)
    {
	myfile << integers[index] << " ";		//add integers to file
    }
   
   char choice;
   cout << "Press 1 to return to main menu: ";
   cin >> choice;
   if (choice == '1')
   {
	home_page();					//return to main home_page function
   }
   else 
	home_page();
    
		
}

//==========================================================================================
//==========================================================================================

void InsertionSort(int a[], int n)
{ 
    cout << endl << "Sorting 200,000 integers...." << endl;
	
    int i, j, temp;			//initializing variables
    
    time_t start, end;			//starting clock time
    time(&start);			//starting clock
    
    for (int i = 1; i < n; i++)		//for loop
    { 	temp = a[i];			//hold the ith element of array in temp
 	j = i-1;			//j = i - 1
 	while (j >= 0 && temp < a[j])	// when j >= 0 and temp < element in front of it
 	{ 	a[j+1] = a[j];		//switch the values
 		j = j-1;		//decrement j
 	}
 	a[j+1] = temp;			//complete the switch
    }
    
    time(&end);					//stops clock
    cInsertiontime = double(end - start);	//stores time in insertiontime
    
    
    ofstream myfile("cpp_insertionSort_output.txt");		//output file
    if (!myfile)
    {
	    //deal with error
	    return;
    }
	
    for (int index = 0; index < 200000; index++)
    {
	    myfile << integers[index] << " ";			//output integers to file
    }
   
    char choiceCinsert;
    cout << "Press 1 to return to main menu: ";
    cin >> choiceCinsert;
    if (choiceCinsert == '1')
    {
	home_page();
    }
    else 
	home_page();
    
}

//==========================================================================================
//==========================================================================================


void home_page() {
	
	ClearScreen();
	
	
	char user_option;
	bool valid_option = false;
	while (valid_option == false) {
        cout << "	RASM5 C++ vs Assembly" << endl;
        cout << "	File Element Count: " << SIZE << endl;
        cout << "*******************************************" << endl;
        cout << "C++		Bubblesort Time: "  << cBubbletime << " secs" << endl;
        cout << "Assembly 	Bubblesort Time: "  << asmBubbletime << " secs" << endl;
	cout << "C++		InsertionSort Time: "  << cInsertiontime << " secs" << endl;
        cout << "Assembly 	InsertionSort Time: "  <<  asmInsertiontime << " secs" << endl;
	cout << "*******************************************" << endl;
        cout << "<1> Load input file (integers)" << endl;
        cout << "<2> Sort using C++ Bubblesort algorithm" << endl;
        cout << "<3> Sort using Assebmly Bubblesort algorithm" << endl;
	cout << "<4> Sort using C++ insertionSort algorithm" << endl;
	cout << "<5> Sort using Assembly insertionSort algorithm" << endl;
        cout << "<6> Quit" << endl << endl << endl;
        cout << "Please select an option: ";
        cin >> user_option; cout << endl << endl;

        if (user_option == '1') {
            load_file(integers);			//calls load_file function
            valid_option = true;			//sets valid option to true
        }
        else if (user_option == '2') {			//if user chooses "2"
	   
            BubbleSort(integers, SIZE);			//calls C++ Bubble Sort algorithm
            valid_option = true;
        }
	
        else if (user_option == '3') {			//if user chooses "3"
            
	    cout << "\n\nSorting using Assembly Bubblesort" << endl;		//tell user what is going on
	    
	    time_t start, end;				//starting clock time
	    time(&start);				//starting clock
	    bubbleSort(integers, SIZE);			//call bubbleSort Assembly fn
	    time(&end);					//stops clock
	    asmBubbletime = double(end - start);	//stores time in asmBubbletime
            
	    ofstream myfile("ASM_BubbleSort_output.txt");
	    for (int index = 0; index < 200000; index++)
	    {
		myfile << integers[index] << " ";
	    }
	    home_page();
	    valid_option = true;
        }
	else if (user_option == '4') {			//if user chooses "4"
	   
            InsertionSort(integers, SIZE);		//call C++ Insertion Sort algorithm
            valid_option = true;
	}
	else if (user_option == '5') {			//if user chooses "5"
            
	    cout << "\n\nSorting using Assembly InsertionSort.." << endl;		//tell user what is going on
	    time_t start, end;				//start clock time
	    time(&start);				//starting clock
	    insertionSort(integers, SIZE);		//call InsertionSort Assembly function
	    time(&end);					//stops clock
	    asmInsertiontime = double(end - start);	//stores time in asmInsertiontime
	    
	    ofstream myfile("ASM_InsertionSort_output.txt");	//assembly file
	    for (int index = 0; index < 200000; index++)	//write to output file
	    {
		myfile << integers[index] << " ";		//loop through outputfile to write
	    }
	    home_page();					//go back to homepage
            valid_option = true;
	}
        else if (user_option == '6') 
        {
            valid_option = true;
            cout << "Logging Out" << endl;
            cout << "Goodbye" << endl;
            exit(EXIT_SUCCESS);
        }
        else
        {
            cout << "Invalid option, please try again" << endl;
        }
    }
}

//==========================================================================================
//==========================================================================================

void load_file(int a[])
{
	
    
    int n = 0;  //number of integers in the file

    fstream in_file;
    in_file.open("input.txt");
    
    if (!in_file)
    {
        cerr << "Problem opening file" << endl;
        //return 1;
        home_page();
    }
    cout << "\nLoading 200,000 random integers from input file into 'integers' array...\n" << endl;

  
   
    while (!in_file.eof())
    {
        in_file >> integers[n];
        n++;
    }
    //n = n - 1;
    //cout << "n = " << n << endl;


    in_file.close();
    
    /*for (int i=0; i < 10; i++)
    {
	cout << integers[i] << endl;
    }
    cout << "...\n" << "...\n" << "...\n" << "integers[200000]" << endl << endl;
    * */
    
	
	    
    char choice;
    cout << "Press 1 to return to main menu: ";
    cin >> choice;
    if (choice == '1')
    {
	home_page();
    }
   else 
	home_page();
}

//==========================================================================================
//==========================================================================================

void ClearScreen()
    {
    cout << string( 100, '\n' );			//clear screen
    }
