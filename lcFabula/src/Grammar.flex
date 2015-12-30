%{
 #include "Grammar.tab.h"   
%}

IDENTIFIER [a-zA-Z_]+ ([0-9] | [a-zA-Z_])*

WHITESPACE [ \t\n\r]

%option noyywrap
%option yylineno
%option warn nodefault

%%
 
        // Warning: Use double quotes for literals!

"/"       { *((std::string*)&yyval) = yytext; return tdiv; }
"{"       { *((std::string*)&yyval) = yytext;  return tbracket_curly_open;  }
"}"       { *((std::string*)&yyval) = yytext;  return tbracket_curly_close; }
"["       { *((std::string*)&yyval) = yytext;  return tbracket_square_open; }
"]"       { *((std::string*)&yyval) = yytext;  return tbracket_square_close; }
"scene"       { *((std::string*)&yyval) = yytext;  return tscene; }
"choice"        { *((std::string*)&yyval) = yytext;  return tchoice; }
[A-Za-z_]+([a-za-z0-9_])*       { *((std::string*)&yyval) = yytext;  return tidentifier; }
(\"([^\"\\]|(\\[a-za-z\"]))*\")|(\'([^\'\\]|(\\[a-za-z\']))*\')       { *((std::string*)&yyval) = yytext;  return tstring; }
<<EOF>>       { *((std::string*)&yyval) = yytext;  return teof; }
[ \t\n\r]       { *((std::string*)&yyval) = yytext;  return tignore; }
"."     { *((std::string*)&yyval) = yytext;  return tfullstop; }
.       { *((std::string*)&yyval) = yytext;  return terror; }
%%
  
// By default functions are extern. So you can create a header file with
// these as extern then included that header file in your code (See Lexer.h)
// Source:  http://stackoverflow.com/a/8015026
void* lexSetUpBuffer(char const* text)
{
    YY_BUFFER_STATE buffer  = yy_scan_string(text);
    yy_switch_to_buffer(buffer);

    return buffer;
}

void lexTearDownBuffer(void* buffer)
{
    yy_delete_buffer((YY_BUFFER_STATE)buffer);
}