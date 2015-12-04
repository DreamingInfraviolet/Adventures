%{
 #include "Grammar.tab.h"   
%}

ARROWRIGHT ->
ARROWLEFT <-
IDENTIFIER [a-zA-Z_]+ ([0-9] | [a-zA-Z_])*

WHITESPACE [ \t\n\r]

%option noyywrap
%option yylineno
%option warn nodefault

%%
 
        // Warning: Use double quotes for literals!

"->"    return tarrow_right;
"<-"    return tarrow_left;
"{"       return tbracket_curly_open; 
"}"       return tbracket_curly_close;
"["       return tbracket_square_open;
"]"       return tbracket_square_close;
"scene"       return tscene;
"choice"        return tchoice;
[A-Za-z_]+([a-za-z0-9_])*       return tidentifier;
(\"([^\"\\]|(\\[a-za-z\"]))*\")|(\'([^\'\\]|(\\[a-za-z\']))*\')       return tstring;
<<EOF>>       return teof;
[ \t\n\r]       return tignore;
"."     return tfullstop;
.       return terror;
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