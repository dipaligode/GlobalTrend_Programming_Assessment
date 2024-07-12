#include <iostream>

struct node {
    int data;
    node* next;
    node(int x) : data(x), next(nullptr) {}
};

node* head = nullptr;

node* reverseList(node* head) 
{
    node* prev = nullptr;
    node* current = head;
    node* next = nullptr;

    while (current != nullptr) 
    {
        next = current->next; 
        current->next = prev; 
        prev = current;       
        current = next;
    }

    return prev;
}

void DisplayList(node* head)
{
    node* temp = head;
    while (temp != nullptr) 
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

void CreateList(int x) 
{
    node* newNode = new node(x);

    if (head == nullptr) 
        head = newNode;
    else
    {
        node* temp = head;
        while (temp->next != nullptr) 
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int main() {

    int num, x;

    std::cout << "Enter how many nodes: ";
    std::cin >> num;

    std::cout << "Enter " << num << " numbers: ";

    for (int i = 0; i < num; ++i) {
        std::cin >> x;
        CreateList(x);
    }

    std::cout << "Original List: ";
    DisplayList(head);

    node* reversedHead = reverseList(head);

    std::cout << "Reversed List: ";
    DisplayList(reversedHead);

    return 0;
}
