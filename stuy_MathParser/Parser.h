#pragma _PARSER_H_
#include <vector>
#include <string>
#include <unordered_map>
#include <stdexcept>
#include <functional>
#include <math.h>

enum TokenType
{
    NONE,
    NUMBER,//数字
    LPAREN,//括号左
    RPAREN,//括号右
    SUB,//减法
    ADD,//加法
    MUL,//乘法
    DIV,//除法
    COMMA,//逗号
    DECIMAL_POINT,// 小数点
    FUNC//函数
};

struct Token
{
    TokenType type;
    double value;
    std::string func_name = "";
};

class ASTNode
{
public:
    virtual ~ASTNode(){};
    virtual double evaluate() = 0;
};

class NumberNode : public ASTNode
{
private:
    double value;
public:

    NumberNode(const double &value):value(value){}
    double evaluate() override {return this->value;}
};

class OpNode : public ASTNode
{
private:
    TokenType op_type;
    ASTNode *left;
    ASTNode *right;

private:
    double calculate(const double &l_val ,const double &r_val);

public:
    ~OpNode();
    OpNode(const TokenType &_op_type,ASTNode *_left,ASTNode *_right):
        op_type(_op_type),left(_left),right(_right){}

    double evaluate() override;
};

class UnaryOpNode : public ASTNode
{
private:
    TokenType uop_type;
    ASTNode *operand;

    std::unordered_map<TokenType,std::function<double()> > unaryOpNode_to_token = 
    {
        {TokenType::SUB,[this](){return -operand->evaluate();}}
    };

public:
    UnaryOpNode(const TokenType &_type ,ASTNode *_operand):uop_type(_type),operand(_operand){}
    double evaluate() override;
};

class FunctionNode : public ASTNode
{
private:
    std::string func_name;
    std::vector<double> arguments;

    std::unordered_map<std::string, std::function<double()> > function_handlers = 
    {
        {"sqrt",[this](){
            if(this->arguments.size() > 1) throw std::invalid_argument("Too many or too few arguments provided.");
            return sqrt(arguments[0]);
        }},
        {"pow",[this](){
            if(this->arguments.size()>2 || this->arguments.size()<=1) throw std::invalid_argument("Too many or too few arguments provided.");
            return pow(this->arguments[0],this->arguments[1]);
        }},
        {"cos",[this](){
            if(this->arguments.size() > 1) throw std::invalid_argument("Too many or too few arguments provided.");
            return cos(this->arguments[0]);
        }},
        {"sin",[this](){
            if(this->arguments.size() > 1) throw std::invalid_argument("Too many or too few arguments provided.");
            return sin(this->arguments[0]);
        }},
        {"tan",[this](){
            if(this->arguments.size() > 1) throw std::invalid_argument("Too many or too few arguments provided.");
            return tan(this->arguments[0]);
        }},
        {"C",[this](){
            if(this->arguments.size()>2 || this->arguments.size()<=1) throw std::invalid_argument("Too many or too few arguments provided.");
            return C(this->arguments[0],this->arguments[1]);
        }},
        {"A",[this](){
            if(this->arguments.size()>2 || this->arguments.size()<=1) throw std::invalid_argument("Too many or too few arguments provided.");
            return A(this->arguments[0],this->arguments[1]);
        }}
    };

private:
    unsigned int C(unsigned int n,unsigned int r);
    unsigned int A(unsigned int n,unsigned int r);
public:
    FunctionNode(const std::string &_func_name,const std::vector<double> &_arguments)
                :func_name(_func_name),arguments(_arguments){}

    double evaluate() override;
};



class Parser
{
private:
    const std::vector<Token>& tokens;
    size_t pos;
    std::unordered_map<TokenType, int> op_precedence = {
        {TokenType::ADD,10},
        {TokenType::SUB,10},
        {TokenType::MUL,20},
        {TokenType::DIV,20}
    };



private:
    ASTNode *parse_expression(int min_precedence = 0);
    ASTNode* parse_factor();
    Token consume_token(); 
    Token peek_token();
public:
    Parser(const std::vector<Token>& _tokens):tokens(_tokens),pos(0){}
    static std::vector<Token> lexer(const std::string &s);
    ASTNode *parser(){return this->parse_expression();}      
    bool is_op(const TokenType &tokenType);
};


