//"1"是49
//"9"是57


#include <iostream>
#include <string>


int myAtoi(const std::string &s);


int main()
{
	std::cout<<myAtoi("-8844")<<std::endl;
	
//	char t = '9';
//	std::cout<<t<<std::endl;
//	int ti = (int)t;
//	std::cout<<ti-48<<std::endl;
	
	return 0;
}



int myAtoi(const std::string &s)
{
	int res = 0;
	int begin = 0;
	short is_positiveNumber = 1;
	int len = s.size();
	
	if(s[0] == '-' )
	{
		begin = 1;
		is_positiveNumber = -1;
	}
	else if(s[0] == '+')
	{
		begin = 1;
	}
	
	
	for(int i = begin;i<len;i++)
	{
		res =res*10 + (s[i] - 48);
	}
//	std::cout<<std::endl;
	return res*is_positiveNumber;
}
