/* Parser for calc++.   -*- C++ -*-

   Copyright (C) 2005-2015, 2018-2021 Free Software Foundation, Inc.

   This file is part of Bison, the GNU Compiler Compiler.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

%skeleton "lalr1.cc" // -*- C++ -*-
%require "3.8.2"
%header

%define api.token.raw

%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
  #include <vector>
  # include <string>
  class ASTNode;
}

// The parsing context.
%param { ASTNode& drv }

%locations

%define parse.trace
%define parse.error detailed
%define parse.lac full

%code {
# include "ASTNode.h"
}

%define api.token.prefix {TOK_}
%token
  COMMA
  L_PAREN
  R_PAREN
  ENDL
  ASSIGN  ":="
  MINUS   "-"
  PLUS    "+"
  STAR    "*"
  SLASH   "/"
  LPAREN  "("
  RPAREN  ")"
;

%token <double> NUM
%token <std::string> ALIAS
%token <std::string> PATH
%token <std::string> FUNCTION
%token <std::string> OPERATOR
%token <std::vector<size_t>> INDICES
%token <std::string> IDENTIFIER "identifier"
%token <int> NUMBER "number"
%nterm <int> exp

%%
%start unit;
unit: assignments exp  { drv.result = $2; };

assignments:
  %empty                 {}
| assignments assignment {};

assignment:
  "identifier" ":=" exp { drv.variables[$1] = $3; };

%left "+" "-";
%left "*" "/";
exp:
  "number"
| "identifier"  { $$ = drv.variables[$1]; }
| exp "+" exp   { $$ = $1 + $3; }
| exp "-" exp   { $$ = $1 - $3; }
| exp "*" exp   { $$ = $1 * $3; }
| exp "/" exp   { $$ = $1 / $3; }
| "(" exp ")"   { $$ = $2; }
%%

void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
