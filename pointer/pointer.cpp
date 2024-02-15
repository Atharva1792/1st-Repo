#include<iostream>

using namespace std;

/*int main(){

    int i= 10;

    cout << "The value of variable i = " <<i <<endl;
    cout << "The memory address of i = " <<&i << endl; //hexadecimal format
    cout << "The value of variable i using * oerator = " << *(&i)<<endl; //    The * operator gives the value when provided with a memory address. the datatype is inferred from the variable name. 
    

    return 0;
}*/

/*int main(){

    int i = 10;
    int *x = &i;  // x stores address of i
    int *y;

    y = &i; //can also assign like this


    cout << "The pointer x is stored at the memory address : " << &x << endl;
    cout << "The pointer x stores the memory address of i : " << x << endl;


    cout << "The value of i accessed through pointer x is : "<<*x << endl; 
    
    //manipulate value of i using pointer x

    *x = *x +1;

    cout << "i (through pointer) = " << *x <<" which equals i (direct access) = " << i <<endl;

    cout << "The memory allocated to the pointer x is : " << sizeof(x) << " bytes." ; 
    
    return 0;
}
*/

// -----------ARRAY POINTERS-------------
/*char ch1 = 'a',ch2='b';
char ch3[4] = { 'c','d','e','f' };
char *ptr[3];
int main(){

    ptr[0] = &ch1;
    ptr[1] = &ch2;
    ptr[2] = ch3;


    cout << "Initial characters stored in ptr[0] and ptr[1]: " << *ptr[0]<<" "<<*ptr[1]<<endl;
    //changing the value stored via pointer
    *ptr[0] = 'z'; 
    *ptr[1] = 'y'; 
    cout << "Final characters stored in ptr[0] and ptr[1]: " << *ptr[0] <<" "<<*ptr[1]<<endl;

    return 0;
}*/

//-----------Dynamic memory allocation----
/*
int i=0;
int *ptr1;

int main(){

    ptr1 = new int; // 'new' allocates memory for an unnamed integer.We can freely access the unnamed variable through the pointer
    
    *ptr1 = 10;
    *ptr1 = 2 + *ptr1;

    cout << "Dynamic memory allocation: Value of ptr1 is : " << *ptr1<<endl;

    delete ptr1; //free up allocated memory.

    //can use the same pointer again to another memory address

    ptr1 = new int[3]; // same pointer now allocated to base address of an array

    //array can be accessed easily using the pointer ptr1


    *(ptr1+0) =2;   //can add array members like this also
    *(ptr1+1) =4;
    ptr1[2] =6;    //normal method

    cout << "Printing array of pointers: \n";
    for(int i=0;i<3;i++){
        cout << "*(ptr1+"<<i<<") =" << *(ptr1+i) << endl; //other way to print array when pointer is used
    }

    cout << "Reprinting:\n";
    for(int i=0;i<3;i++){
        cout << "ptr1[" << i << "] = "<<ptr1[i] <<endl; // normal way to print array
    }

    delete[ ] ptr1; //free up memory, array size need not be specified.

    return 0;
}*/

// -----------------Array and Pointer---------------

/*int arr[3] = {5,12,31};

int *ptr = new int[3];

int main(){
    *(ptr+0) = 2; //pointer way
    ptr[1] = 4; // normal way (array)
    *(ptr+2) = 6;
    //same way to access(print) them also 

    cout << "arr[0] using array notation = "<< arr[0]<<endl;
    cout << "arr[1] using pointer notation = "<<arr[1]<<endl;

    //accress base address of array that pointer points to

    cout << "Base address of array ptr points to: " << ptr <<endl;

    // access base address of arr
    cout << "Base address of array arr is : " << arr << endl;

    return 0;
}*/


//------------Multi dimensional Pointer-----

/*int **ptr2;
int *ptr;
int i=10;

int main(){
    ptr = &i;
    cout << *ptr<< endl;

    ptr2 = &ptr; // assigned base address of ptr(pointer itself,not where it points to) to ptr2

    //accessing i in different ways
    cout << "Through i : " << i <<endl;
    cout << "Through ptr : "<< *ptr << endl;
    cout << "Through ptr2: "<< **ptr2 << endl;

    return 0;

}*/

//---------pointers to return value from functions-----------

/*int* sum(int *i,int *j);

int* sum(int *i,int *j){
    int *result = new int;

    *result = *i + *j;

    return result; //it is equivalent to (int *unnamed = result) since new keyword is used we created memory space for it
} 

int main(){
    int p = 10, q =15;
    int *r = sum(&p,&q);    //pointer r stores the base address of the memory allocated with new operator in the function sum.

    cout << "The sum is : " << *r << endl;

    return 0;

    //since memory is not being deleted with delete,a memory leak is created.

}*/

// -------------Dynamic memory allocation(Multidimensional pointer)


/*int **ptr;

int main(){
    ptr = new int *[3]; // ptr stores the base address of an array of three pointers to an int or int array

    for (int i=0;i<3;i++){
        *(ptr+i) = new int[4];
    }
    // this loop can be written as - ptr = new int[3][4]


    //manipulate allocated memory

    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            *(*(ptr+i)+j) = i+j; // this means ptr[i][j] = i+j
        
            cout << "ptr["<<i<<"]["<<j<<"] = "<<ptr[i][j]<<" ";
        }
        cout << endl;
    }
    //free the allocated space, delete must used as much as new is used

    for(int i=0;i<3;i++){
        delete[] *(ptr+i);
    }
    delete[] ptr;

    return 0;
}
*/


//---------------3d array pointer

/*int ***ptr;

int main(){
    ptr = new int **[2]; 

    for (int i=0;i<2;i++){
        *(ptr+i) = new int *[3];
        for(int j=0;j<3;j++){
            *(*(ptr+i)+j) = new int[4];
        }
    }

    //manipulate allocated memory

    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<4;k++){
                *(*(*(ptr+i)+j)+k) = i+j+k; // this means ptr[i][j] = i+j
       
                cout << "ptr["<<i<<"]["<<j<<"]["<<k<<"] ="<<*(*(*(ptr+i)+j)+k)<<" ";
            }
        }
        cout << endl;
    }
    //free the allocated space, delete must used as much as new is used

    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            delete[] *(*(ptr+i)+j);
        }
        delete[] *(ptr+i);
    }
    delete[] ptr;

    return 0;
}*/

// -------------function pointers

/*int sum(int a,int b){
    return a+b;
}

int (*ptr_sum)(int,int) = &sum; // ptr_sum is a pointer which pointing to function "sum" which takes 2 ints as argument and returns an int.

int main(){
    int a = 10,b =2;

    if(ptr_sum != &sum)
        cout << "Error!";
    int res = (*ptr_sum)(a,b);  //function call through pointer
    cout <<"Sum is : "<<res;

    return 0;

}*/



// using typedef


/*int sum(int a,int b){
    return a+b;
}

typedef int (*ptr_sum_type)(int,int); 

int main(){
    int a = 10,b =2;

    ptr_sum_type ptr_sum = &sum;

    int res = (*ptr_sum)(a,b);  //function call through pointer
    cout <<"Sum is : "<<res;

    return 0;

}*/



