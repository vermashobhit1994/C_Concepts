/*Program to find and remove the duplicate elements in array.
Here the duplicate elements can be any no of times.
Algorithm Using Pointer:
1. Take two pointers one with 2nd element i.e *curptr and one at last element i.e *endptr.
2. Run loop from 1st element to last element of array and also update
*curptr by array+1 (ith loop)
3. Run loop from ith+1 to end and check from *array value with *cur value.
4. If any duplicate value found replace *curptr value by *endptr value and 
decrease the no of elements by 1.
5. If not found then keep on increasing *curptr.
*/

#include<stdio.h>
#include<stdlib.h>
int Find_Remove_Duplicate_Loop(int *arr,int n)
{
    for(int i = 0;i<n;i++)
    {
        //loop to check for elements from i+1th value to end of elements 
        for(int j = i+1;j<n;j++)
        {
            //if duplicate element found
            if(arr[i] == arr[j])
            {   
                //shift elements by left
                for(int k =j;k<n;k++ )
                    arr[k] = arr[k+1];
                --n;//decrease n if shifts
                /*done to remove three continuous duplicate elements*/
                j--;
            }
        }
    }
    return n;//return the new no of elements
}
void Find_Remove_Duplicate_Ptr(int *arr,int *n)
{
    int *curptr,*endptr = arr+(*n)-1;//end ptr will point to last element of array
    /* cur ptr will point to arr ptr next element and update cur by arr+1 
    after each iteration of loop.*/
    for(curptr = arr+1 ; arr<endptr ; arr++,curptr=arr+1)
    {
        //loop to check and shift elemnts if any duplicate element found 
        while(curptr <= endptr)
        {   
            if(*curptr == *arr)
            {
                *curptr = *endptr--;//put the curptr value by last value
                --*n;//decrease the number of elements by 1
            }   
            else//to prevent curptr from moving forward if shifting is done
                curptr++;//shift the cur ptr forward if no element matches

        }
    }
}
void display_array(int *arr,int n)
{
    for(int  i = 0;i<n;i++)
        printf("%d, ",*(arr+i));
    printf("\n\n    ");
}
int main()
{
    int arr1[] = {4,4,8,4,9,1,1,1,2,9};
    int arr[] = {4,4,4,4,4};
    int ch,len = (sizeof(arr)/sizeof(arr[0]));
    
    while(1)
    {
        printf("MENU\n1. USING TRIPLE LOOP \n2. USING POINTERS\n3. DISPLAY ELEMENTS\n");
        printf("4. EXIT\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        
        {
            case 1:
            //update the len value
                len = Find_Remove_Duplicate_Loop(arr,len);
                break;
            case 2:
                Find_Remove_Duplicate_Ptr(arr,&len );
                break;
            case 3:
                display_array(arr,len );
                break;
            case 4:
                return EXIT_SUCCESS;
            default:
                printf("Enter the correct choice\n");
        }
    }
    
}