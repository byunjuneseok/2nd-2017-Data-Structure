#ifndef POSTFIX_H
#define POSTFIX_H
// 1-char token types : ASCII Value
// token types for non one-char tokens
#define ID		257
#define NUM		258
#define EQ		259				//EQUAL
#define NE		260				//NOT EQUAL
#define GE		261				//GREATER THAN OR EQUAL
#define LE		262				//LESS THAN OR EQUAL
#define AND		263				//AND
#define OR		264				//OR
#define UMINUS	265				//UNARY MINUS

#define MAXLEN	80

struct Expression {
   Expression(char* s): str(s), pos(0)
      { for (len = 0; str[len] != '\0'; len++); }
   char * str;					//char string
   int pos;						//Expression 내의 현재위치로 [0,..,len-1]사이의 수
   int len;						//length
};

struct Token {
  bool operator==(char);
  bool operator!=(char);
  Token();
  Token(char);						// 1-char token: type equals the token itself
  Token(char, char, int);			// 2-char token(e.g. <=) & its type(e.g. LE)
  Token(char*, int, int);			// operand with its length & type(defaulted to ID)
  bool IsOperand();					// true if the token type is ID or NUM
  int type;							// ascii code for 1-char op; predefined for other tokens
  char *str;						// token value
  int len;							// length of str
  int ival;							// used to store an integer for type NUM; init to 0 for ID
};
using namespace std;
ostream& operator<<(ostream&, Token);
ostream& operator<<(ostream&, Expression);
Token NextToken(Expression&, bool); // 2nd arg=true for infix expression
#endif