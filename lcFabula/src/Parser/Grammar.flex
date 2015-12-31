%{
 #define YY_NO_UNISTD_H
 #include <string>
 #include <vector>
 #include "ParseNodes/section.h"
 #include "ParseNodes/fstring.h"
 #include "ParseNodes/scene.h"
 #include "ParseNodes/choice.h"
 #include "ParseNodes/header.h"
 #include "ParseNodes/destination.h"
 using namespace fabula::parsing::node;
 #include "Grammar.tab.hpp"

 int flexLineNo=1;
%}

IDENTIFIER [a-zA-Z_]+ ([0-9] | [a-zA-Z_])*

WHITESPACE [ \t\n\r]

%option noyywrap
%option yylineno
%option warn nodefault
%option c++

%%
 
        // Warning: Use double quotes for literals!

"/"       { yylval.charstrval = "/"; return tdiv; }
"{"       { yylval.charstrval = "{";  return tbracket_curly_open;  }
"}"       { yylval.charstrval = "}";  return tbracket_curly_close; }
"["       { yylval.charstrval = "[";  return tbracket_square_open; }
"]"       { yylval.charstrval = "]";  return tbracket_square_close; }
"scene"       { yylval.charstrval = "scene";  return tscene; }
"choice"        { yylval.charstrval = "choice";  return tchoice; }
"goto"        { yylval.charstrval = "goto";  return tgoto; }
[A-Za-z_]+([a-za-z0-9_])*       { yylval.stringval = new std::string(yytext);  return tidentifier; }
(\"([^\"\\]|(\\[a-za-z\"]))*\")|(\'([^\'\\]|(\\[a-za-z\']))*\')  { yylval.stringval = new std::string(yytext);  return tstring; }
<<EOF>>       {  return 0; }
"\r\n"      { ++flexLineNo; }
"\r"      { ++flexLineNo; }
"\n"      { ++flexLineNo; }
[ \t]          /* Ignore */
"."     { yylval.charstrval = ".";  return tfullstop; }
.       { printf("Lexing error on line %d: \"%s\"\n", yylineno, yytext); }
%%