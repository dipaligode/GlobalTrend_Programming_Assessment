#include<iostream>

int sumOfDigits(int num)
 {
    int sum = 0;
    while (num != 0) 
    {
        sum += num % 10;  
        num /= 10;        
    }
    return sum;
}

int main()
{
    int num;

    std::cout<<"Enter number:";
    std::cin>>num;

    //negative to positive
    if (num < 0) 
    {
        num = -num;
    }

    std::cout<<" Sum of Digits of "<<num<<" is "<<sumOfDigits(num);

    return 0;
}