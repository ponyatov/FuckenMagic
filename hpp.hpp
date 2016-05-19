#ifndef _H_FM
#define _H_FM

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <map>
using namespace std;

struct Sym {
	string tag,val; Sym(string,string); Sym(string);
	vector<Sym*> nest; void push(Sym*);
	virtual string dump(int=0); virtual string tagval(); string pad(int);
	virtual Sym* eval();
	virtual Sym* eq(Sym*);
};

extern map<string,Sym*> env;
extern void env_init();

struct Num: Sym { Num(string); };

struct List: Sym { List(); };

struct Op: Sym { Op(string); Sym*eval(); };

struct Term: Sym { Term(Sym*,Sym*); string tagval(); };

extern int yylex();
extern int yylineno;
extern char* yytext;
#define TOC(C,X) { yylval.o = new C(yytext); return X; }
extern int yyparse();
extern void yyerror(string);
#include "ypp.tab.hpp"

#endif // _H_FM
