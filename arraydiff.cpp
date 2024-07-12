#include<iostream>

#define ASIZE 20

int difference(int arr[],int n)
{
    int min=99999,max=0;

    for(int i=0;i<n;i++)
    {
        if(arr[i] < min)
            min = arr[i];
    }

    for(int i=0;i<n;i++)
    {
        if(arr[i] > max)
            max = arr[i];
    }

    std::cout<<"\n Maximum number of array is: "<<max;
    std::cout<<"\n Minimum number of array is: "<<min;
    return (max-min);

}

int main()
{
    int num, array[ASIZE];

    std::cout<<"Enter how many numbers:";
    std::cin>>num;

    if (num > ASIZE)
     {
        std::cerr << "Number of elements exceeds the defined array size." << std::endl;
        return -1;
    }

    std::cout<<"Enter "<<num<<" numbers:";
    for(int i=0;i<num;i++)
    {
        std::cin>>array[i];
    }
    int x = difference(array,num);
    std::cout<<"\n Difference is: "<<x;

    return 0;
}
