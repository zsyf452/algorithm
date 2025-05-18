#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype>


enum TokenType { 
    TOK_NUMBER,   // 数字字面量（如 123, 4.56）
    TOK_PLUS,     // 加法运算符 +
    TOK_MINUS,    // 减法运算符 -
    TOK_MUL,      // 乘法运算符 *
    TOK_DIV,      // 除法运算符 /
    TOK_LPAREN,   // 左括号 (
    TOK_RPAREN,   // 右括号 )
    TOK_END       // 输入结束标记
};

struct Token {
    TokenType type;
    double value;  // 仅当type为TOK_NUMBER时有效
};

class Parser 
{
private:
    std::string input;
    size_t pos = 0;
    Token current_token;

    // 运算符优先级表（左绑定权值）
    std::unordered_map<TokenType, int> precedence = {
        {TOK_PLUS, 10},
        {TOK_MINUS, 10},
        {TOK_MUL, 20},
        {TOK_DIV, 20}
    };


private:
    Token get_next_token()
    {
        while(pos<input.size() && isspace(input[pos])) {pos++;}
        if(pos+1 >= input.size()){return {TOK_END,0};}
    }

public:
    Parser(std::string &s):input(s)
    {
        current_token = get_next_token();
    }
    
    
};

double evaluateExpression(std::string &out);

int main()
{
    std::string out = "1 + 2 * 3";

    return 0;
}




double evaluateExpression(std::string &out)
{


    
    return 0;
}