#include <iostream>
#include <vector>
#include <algorithm>


void reverse(std::vector<int>& nums, int start, int end) {
    while (start < end) {
        std::swap(nums[start], nums[end]);
        ++start;
        --end;
    }
}

void rotate(std::vector<int>& nums, int k)
{
    int n = nums.size();

    k = k % n; 

    if (k == 0) 
        return; 

    reverse(nums, 0, n - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, n - 1);
}

int main() 
{
    int n, k;
    
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    std::vector<int> nums(n);
    std::cout << "Enter"<<n<<" elements of the array: ";
    for (int i = 0; i < n; ++i) 
    {
        std::cin >> nums[i];
    }

    std::cout << "Enter the number of steps to rotate the array: ";
    std::cin >> k;

    std::cout << "Original array: ";
    for (int num : nums) 
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    rotate(nums, k);

    std::cout << "Array after rotating by " << k << " steps: ";
    for (int num : nums) 
    {
        std::cout << num << " ";
    }

    return 0;
}
