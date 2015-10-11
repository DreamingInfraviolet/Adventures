ARROWRIGHT ->
ARROWLEFT <-
IDENTIFIER [a-zA-Z_]+ ([0-9] | [a-zA-Z_])*

WHITESPACE [ \t\n\r]

%option noyywrap
%option yylineno
%option warn nodefault
 
    #include "tokens.h"

%%
 
        // Warning: Use double quotes for literals!

"->"    return TARROW_RIGHT;
"<-"    return TARROW_LEFT;
"{"       return TBRACKET_CURLY_OPEN; 
"}"       return TBRACKET_CURLY_CLOSE;
"["       return TBRACKET_SQUARE_OPEN;
"]"       return TBRACKET_SQUARE_CLOSE;
"scene"       return TSCENE;
"choice"        return TCHOICE;
[a-zA-Z_]+([a-zA-Z0-9_])*       return TIDENTIFIER;
(\"([^\"\\]|(\\[a-zA-Z\"]))*\")|(\'([^\'\\]|(\\[a-zA-Z\']))*\')       return TSTRING;
<<EOF>>       return TEOF;
[ \t\n\r]       return TIGNORE;
"."     return TFULLSTOP;
.       return TERROR;
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