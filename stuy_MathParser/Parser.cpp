#include "Parser.h"



OpNode::~OpNode()
{
    delete this->left;
    delete this->right;
}


double OpNode::calculate(const double &l_val ,const double &r_val)
{
    double res = 0;
    switch (this->op_type)
    {
    case TokenType::ADD:
        res = l_val+r_val;
        break;
    case TokenType::SUB:
        res = l_val- r_val;
        break;
    case TokenType::MUL:
        res =  l_val*r_val;
        break;
    case TokenType::DIV:
        res = l_val/r_val;
        break;
    default:
        break;
    }

    return res;
}

double OpNode::evaluate()
{
    double l_val = this->left->evaluate();
    double r_val = this->right->evaluate();

    return this->calculate(l_val,r_val);
}


double UnaryOpNode::evaluate() 
{
    auto it = this->unaryOpNode_to_token.find(this->uop_type);
    if(it != this->unaryOpNode_to_token.end())
    {
        return it->second();
    }
    throw std::runtime_error("Unknown unary operator");
}


unsigned int FunctionNode::C(unsigned int n, unsigned int r)
{
    return A(n,r) / A(r,r);
}

unsigned int FunctionNode::A(unsigned int n, unsigned int r)
{
    if(r > n)
        throw std::invalid_argument("Parameter error: R cannot be greater than N.");
    unsigned int res = 1;
    for (unsigned int i = n; i > n-r; i--)
    {
        res *= i; 
    }
    return res;
}



double FunctionNode::evaluate()
{
    size_t size = this->arguments.size();
    if(size < 0 ) throw std::runtime_error("sqrt of negative number");
    
    auto it = this->function_handlers.find(this->func_name);
    if(it != this->function_handlers.end())
    {
        return it->second();
    }  
    else
    {
        throw std::runtime_error("Unknown function: " + this->func_name);
    }
}

std::vector<Token> Parser::lexer(const std::string &s)
{

    std::unordered_map<char, TokenType> operator_to_token = {
        {'+', TokenType::ADD},
        {'-', TokenType::SUB},
        {'*', TokenType::MUL},
        {'/', TokenType::DIV},
        {'(', TokenType::LPAREN},
        {')', TokenType::RPAREN},
        {',', TokenType::COMMA},
        {'.', TokenType::DECIMAL_POINT}
    };

    std::vector<Token> tokens;
    int _pos = 0;
    int size = s.size();
    while(_pos<size)
    {
        if(isdigit(s[_pos]))
        {
            double t = 0;
            while (_pos < size && isdigit(s[_pos]))
            {
                t = t*10 + (s[_pos]-'0');
                _pos++;
            }
            if(_pos < size && s[_pos] == '.')
            {
                double decimal = 0;
                double rate = 1;
                _pos++;
                while (_pos < size && isdigit(s[_pos]))
                {
                    decimal = decimal*10 + (s[_pos]-'0');
                    _pos++;
                    rate*=0.1;
                }
                t+=decimal*rate;
            }
            tokens.push_back({TokenType::NUMBER,t,""});
        }
        else if(isalpha(s[_pos]))
        {
            std::string t = "";
            while(_pos<size && isalpha(s[_pos]) )
            {
                t+=s[_pos];
                _pos++;
            }
            tokens.push_back({TokenType::FUNC,0,t});
        }
        else
        {
            auto it = operator_to_token.find(s[_pos]);
            if(it != operator_to_token.end())
            {
                tokens.push_back({it->second,0,""});
                _pos++;
            }
        }
        
    }
    return tokens;            
}


ASTNode* Parser::parse_expression(int min_precedence)
{
    ASTNode *left = parse_factor();
    while (true)
    {
        Token curren_token = this->peek_token();
        auto precedence_it = this->op_precedence.find(curren_token.type);
        int current_precedence = (precedence_it != op_precedence.end()) ? precedence_it->second : -1;

        if(current_precedence < min_precedence)
            break;
        
        Token curr_op = this->consume_token();
        ASTNode *right = parse_expression(current_precedence+1);
        left = new OpNode(curr_op.type,left,right);
    }
    

    return left;
}


ASTNode* Parser::parse_factor()
{
    Token curr = this->peek_token();
    if(curr.type == TokenType::NUMBER)
        return new NumberNode(this->consume_token().value);
    else if(curr.type == TokenType::LPAREN)
    {
        //消耗(
        this->consume_token();
        ASTNode *expr = this->parse_expression();

        if(this->peek_token().type != TokenType::RPAREN)
        {
            throw std::runtime_error("Expected ')'");
        }
        //消耗)
        this->consume_token();
        return expr;     
    }
    else if(curr.type == TokenType::FUNC)
    {
        Token func = this->consume_token();
        std::vector<double> arguments;
        //消耗(
        consume_token();
        while (true)
        {
            ASTNode* arg = parse_expression();
            arguments.push_back(arg->evaluate());

            Token next = peek_token();
            if(next.type == TokenType::COMMA)
            {
                this->consume_token();
                continue;
            }
            else if(next.type == TokenType::RPAREN)
                break;
            else
                throw std::invalid_argument("Invalid expression: Expression does not meet the required format.");
            this->consume_token();
        }
        this->consume_token();//消耗右括号

        return new FunctionNode(func.func_name,arguments);
    }
    else if(curr.type == TokenType::SUB
            && (pos+1 < tokens.size() && (tokens[pos+1].type == TokenType::LPAREN || tokens[pos+1].type == TokenType::NUMBER || tokens[pos+1].type == TokenType::FUNC))
            &&(pos-1 >= 0 && tokens[pos-1].type != TokenType::NUMBER))
    {
        //消耗 -
        this->consume_token();
        ASTNode *expr = this->parse_factor();
        return new UnaryOpNode(curr.type,expr);

    }

    throw std::runtime_error("Unexpected token");
}


Token Parser::consume_token()
{
    if(this->pos >= this->tokens.size() )
        throw std::runtime_error("Unexpected end of input");
    return tokens[this->pos++];
}


Token Parser::peek_token()
{
    if(this->pos >= this->tokens.size())
        return {TokenType::NONE,0};
    
    return tokens[this->pos];
}


bool Parser::is_op(const TokenType &tokenType)
{
    auto it = this->op_precedence.find(tokenType);
    if(it != op_precedence.end())
        return true;
    return false;
}