#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

using namespace std;

class Polynomial; // 전방참조

class Term {
friend class Polynomial;
friend ostream& operator<<(ostream&, Polynomial&);
friend istream& operator>>(istream&, Polynomial&);
float coef;  // coefficient
int exp;	   // exponent
};
class Polynomial {
public:
   Polynomial();  // construct a polynomial p(x) = 0.
   Polynomial operator+(Polynomial&); // 다항식의 합을 반환
   void NewTerm(const float, const int);
friend ostream& operator<<(ostream&, Polynomial&);
friend istream& operator>>(istream&, Polynomial&);
private:
   Term *termArray;
   int capacity; // 1로 초기화
   int terms;    // 저장된 항의 수로 0으로 초기화
};
#endif