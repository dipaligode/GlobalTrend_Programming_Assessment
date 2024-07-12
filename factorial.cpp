#include<iostream>

int factorial(int num) 
{
    if (num == 0) 
        return 1;
    else 
        return num * factorial(num - 1);
}

int main()
{
    int num;

    std::cout<<"Enter number:";
    std::cin>>num;

    std::cout<<"\n Factorial of "<<num<<" is "<<factorial(num);
}