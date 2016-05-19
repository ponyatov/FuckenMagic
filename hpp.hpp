#ifndef _H_FM
#define _H_FM

#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
using namespace std;

struct Sym {
	string val; Sym(string);
	vector<Sym*> nest; void push(Sym*);
	virtual string dump(int=0); string pad(int);
};

extern map<string,Sym*> env;
extern void env_init();

struct List: Sym { List(); };

struct Op: Sym { Op(string); };

extern int yylex();
extern int yylineno;
extern char* yytext;
#define TOC(C,X) { yylval.o = new C(yytext); return X; }
extern int yyparse();
extern void yyerror(string);
#include "ypp.tab.hpp"

#endif // _H_FM
