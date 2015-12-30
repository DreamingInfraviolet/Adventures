%{
 #define YY_NO_UNISTD_H
 #include <string>
 #include <vector>
 #include "section.h"
 #include "fstring.h"
 #include "scene.h"
 #include "choice.h"
 #include "header.h"
 #include "destination.h"
 using namespace fabula;
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

"/"       { yylval.charstrval = yytext; return tdiv; }
"{"       { yylval.charstrval = yytext;  return tbracket_curly_open;  }
"}"       { yylval.charstrval = yytext;  return tbracket_curly_close; }
"["       { yylval.charstrval = yytext;  return tbracket_square_open; }
"]"       { yylval.charstrval = yytext;  return tbracket_square_close; }
"scene"       { yylval.charstrval = yytext;  return tscene; }
"choice"        { yylval.charstrval = yytext;  return tchoice; }
[A-Za-z_]+([a-za-z0-9_])*       { yylval.charstrval = yytext;  return tidentifier; }
(\"([^\"\\]|(\\[a-za-z\"]))*\")|(\'([^\'\\]|(\\[a-za-z\']))*\')       { yylval.charstrval = yytext;  return tstring; }
<<EOF>>       {  return 0; }
"\r\n"      { ++flexLineNo; }
"\r"      { ++flexLineNo; }
"\n"      { ++flexLineNo; }
[ \t]          /* Ignore */
"."     { yylval.charstrval = yytext;  return tfullstop; }
.       { printf("Lexing error on line %d: \"%s\"\n", yylineno, yytext); }
%%