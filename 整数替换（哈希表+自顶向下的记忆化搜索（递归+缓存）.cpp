#include <iostream>
#include <vector>
#include <unordered_map>

int get_hash_data(std::unordered_map<int,int> &book,int &&key)
{
    auto it= book.find(key);
    if(it != book.end())
    {
        return it->second;
    }
    else
    {
        return 0;
    }
}

int search(std::unordered_map<int,int> &book,int num,int step)
{
    if(num == 1) return step;

    if(num % 2 == 0)
    {
        if(get_hash_data(book,num/2) > 0)
        {
            return get_hash_data(book,num/2)+step;
        }

        int res = search(book,num/2,step+1);
        int stp = res - step;
        book[num/2] = stp;
        return step+stp;
    }

    int add_num_book = get_hash_data(book,num+1);
    int sub_num_book = get_hash_data(book,num-1);

    int add_stp = 0;
    int sub_stp = 0;

    if(add_num_book == 0)
    {
        int res = search(book,num+1,step+1);
        add_stp = res - step;
        book[num+1] = add_stp;
    }
    else
    {
        add_stp = add_num_book;
    }


    if(sub_num_book == 0)
    {
        int res = search(book,num-1,step+1);
        sub_stp = res - step;
        book[num-1] = sub_stp;
    }
    else
    {
        sub_stp = sub_num_book;
    }

    if(sub_stp < add_stp)
        return sub_stp+step;

    return add_stp+step;
}

int integerReplacement(int n)
{
    std::unordered_map<int,int> book;
    return search(book,n,0);
}

int main()
{
    // int n = 7;
    // int n = 8;
    int n = 4;
    // int n = 5;
    // int n = 100090000;
    std::cout<<integerReplacement(n)<<std::endl;
    return 0;
}