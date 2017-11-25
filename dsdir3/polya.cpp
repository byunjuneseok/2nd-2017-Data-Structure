#include <iostream>
#include "polya.h"
using namespace std;

istream& operator>> (istream& is, Polynomial& p) {
	int noofterms; float coef; int exp;
	is >> noofterms;
	for (int i = 0; i < noofterms; i++) {
		is >> coef >> exp;
		p.NewTerm(coef, exp);
	}
	return is;
}
ostream& operator<< (ostream& os, Polynomial& p) {
	/* Term Print */
	for (int i = 0; i < p.terms; i++) {
		if (p.termArray[i].exp == 0) {
		cout << p.termArray[i].coef;
		}
		
		else if (p.termArray[i].exp == 1){
			if (p.termArray[i].coef == -1) cout << "-x";
			else if (p.termArray[i].coef == 1) cout << "x";
			else cout << p.termArray[i].coef << "x";
		}

		else{
			if (p.termArray[i].coef == -1) cout << "-x^" << p.termArray[i].exp;
			else if (p.termArray[i].coef == 1) cout << "x^" << p.termArray[i].exp;
			else cout << p.termArray[i].coef << "x^" << p.termArray[i].exp;
		}

		/* Operator print */
		if (i < p.terms - 1){
			if (p.termArray[i + 1].coef > 0) cout << "+";
		}
	}
	cout << endl;
	return os;
}

Polynomial::Polynomial() :capacity(1), terms(0) {
	termArray = new Term[capacity];
}

void Polynomial::NewTerm(const float theCoeff, const int theExp) {
	//enlarge the capacity
	int tcapacity = capacity;
	terms = terms + 1;
	if (terms == capacity) {
		capacity *= 2;
	}

	// make temp TermArray
	Term *temp = new Term[capacity];

	//immigrate to tempArray
	for (int i = 0; i<tcapacity; i++) {
		temp[i].coef = termArray[i].coef;
		temp[i].exp = termArray[i].exp;
	}

	delete[] termArray;
	termArray = temp;

	//Adding New Term
	termArray[terms - 1].coef = theCoeff;
	termArray[terms - 1].exp = theExp;
}

Polynomial Polynomial::operator+(Polynomial& b)
{
	Polynomial c; // this is the result.
	int ax = 0, bx = 0; // aPos, bPos on our textbook.
	while ((ax < terms) && (bx < b.terms)) {
		if (termArray[ax].exp == b.termArray[bx].exp) {
			float t = termArray[ax].coef + b.termArray[bx].coef;
			if (t) c.NewTerm(t, termArray[ax].exp);
			ax++;
			bx++;
		}

		else if (termArray[ax].exp < b.termArray[bx].exp) {
			c.NewTerm(b.termArray[bx].coef, b.termArray[bx].exp);
			bx++;
		}

		else {
			c.NewTerm(termArray[ax].coef, termArray[ax].exp);
			ax++;
		}
	}
	for (; ax<terms; ax++) {
		c.NewTerm(termArray[ax].coef, termArray[ax].exp);
		}

	for (; bx<b.terms; bx++) {
		c.NewTerm(b.termArray[bx].coef, b.termArray[bx].exp);
		}
	return c;
}