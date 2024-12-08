#include <iostream>

// 定义链表节点结构体
struct Node {
    int data;
    Node* next;
};

struct Make
{
    int left;
    int center;
    int right;
    int sum;
}make[1000];
int top = 0;


int MaxCoint = -1;

Node* initializeLinkedList(int values[], int size);
void printLinkedList(Node* head);
void showMake();
void dfs(Node *b,int coins);

int main() 
{
    int nums[] = {3,1,5,8};
    // int nums[] = {1,5};
    int size = sizeof(nums) / sizeof(nums[0]);

    Node* head = initializeLinkedList(nums, size);
    printLinkedList(head);

    dfs(head,0);
    std::cout<<MaxCoint<<std::endl;

    return 0;
}
Node* initializeLinkedList(int values[], int size)
{
    if (size == 0) return nullptr;

    Node* head = new Node();
    head->data = values[0];
    head->next = nullptr;

    Node* current = head;
    for (int i = 1; i < size; ++i) 
    {
        Node* newNode = new Node();
        newNode->data = values[i];
        newNode->next = nullptr;
        current->next = newNode;
        current = newNode;
    }

    return head;
}

// 打印链表
void printLinkedList(Node* head)
{
    Node* current = head;
    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void showMake()
{
    for(int i = 0;i<top;i++)
    {
        std::cout<<"left: "<<make[i].left
                <<" center: "<<make[i].center
                <<" right: "<<make[i].right
                <<" sum: "<<make[i].sum<<std::endl;
    }

}


void dfs(Node *b,int coins)
{
    if(b == nullptr)
    {
        if(coins > MaxCoint)
            MaxCoint = coins;

        // showMake();
        // std::cout<<"sum: "<<coins<<"\n\n\n";

        return;
    }

    Node *p1 = b,*p2=b;
    b = p2->next;
    int left = 0,right = 0;
    while(p2!=nullptr)
    {
        if(p1 != p2)
            left = p1->data;
        else
            left = 1;
        
        if(p2->next != nullptr)
            right = p2->next->data;
        else
            right = 1;
        
        p1->next = p2->next;
        int sum = left * p2->data * right; 
        coins += sum;
        // make[top].left = left;
        // make[top].center = p2->data;
        // make[top].right = right;
        // make[top].sum = coins;
        // top++;
        dfs(b,coins);
        coins -= sum;
        // top--;
        if(p2->next == b)
            b = p2;

        if(p1 != p2)
            p1->next = p2;
        p1 = p2;        
        p2 = p2->next;



    }
}