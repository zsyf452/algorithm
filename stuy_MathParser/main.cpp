#include <iostream>
#include "Parser.h"



int main()
{

    // std::vector<Token>tokens =  Parser::lexer("1+2");
    // std::vector<Token>tokens =  Parser::lexer("1+2*3");
    // std::vector<Token>tokens =  Parser::lexer("1+2*3-2");
    // std::vector<Token>tokens =  Parser::lexer("1+2*(3-2)");
    // std::vector<Token>tokens =  Parser::lexer("1+sqrt(9)*2");
    // std::vector<Token>tokens =  Parser::lexer("1+sqrt(8+1)*2");
    // std::vector<Token>tokens =  Parser::lexer("-(1+2)+(-1)");
    // std::vector<Token>tokens =  Parser::lexer("sqrt(pow(2,3))");
    // std::vector<Token>tokens =  Parser::lexer("-sqrt(9)-pow(2,3)");
    // std::vector<Token>tokens =  Parser::lexer("3.14+0.1");
    // std::vector<Token>tokens =  Parser::lexer("sin(60*3.14/180.0)");
    std::vector<Token>tokens =  Parser::lexer("A(4,2)+C(4,2)");

    Parser p(tokens);
    ASTNode *root = p.parser();
    try
    {
        
        std::cout<<"res: "<<root->evaluate()<<std::endl;
        // std::cout<<sin(60*3.14/180.0);
        // int res = 1;
        // for (int i = 4; i > 4-1; i--)
        // {
        //     res *= i; 
        // }
        // std::cout<<res;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    // while(true)
    // {
    //     std::string in = "";
    //     std::cin>>in;
    //     std::vector<Token>tokens =  Parser::lexer(in);
    //     Parser p(tokens);
    //     ASTNode *root = p.parser();
    //     try
    //     {
            
    //         std::cout<<"res: "<<root->evaluate()<<std::endl;
    //     }
    //     catch(const std::exception& e)
    //     {
    //         std::cerr << e.what() << '\n';
    //     }
    
    // }
   
    return 0;
}