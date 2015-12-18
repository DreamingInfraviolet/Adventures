
%{
//Custom code goes here    

%}

//Define Bison union
%union
{
    int ival;
}

//Terminal symbols
%token <ival> teof
%token <ival> terror
%token <ival> tarrow_left
%token <ival> tarrow_right
%token <ival> tbracket_curly_open
%token <ival> tbracket_curly_close
%token <ival> tbracket_square_open
%token <ival> tbracket_square_close
%token <ival> tscene
%token <ival> tidentifier
%token <ival> tstring
%token <ival> tignore
%token <ival> tchoice
%token <ival> tgoto
%token <ival> tfullstop

%%

S                   : SECTION;

SECTION_DECLARATION : tidentifier [ SECTION ];

SECTION             :
                     | SECTION_DECLARATION SECTION
                     | SCENE_DECLARATION SECTION


SCENE_DECLARATION   :tscene tidentifier tbracket_curly_open SCENE tbracket_curly_close;

SCENE               : HEADER CHOICES;

//The header is a title with an optional description.
HEADER              : TITLE DESCRIPTION;

TITLE               : tstring
OPT_DESCRIPTION     : | DESCRIPTION;
DESCRIPTION         : tstring

CHOICES             : GOTO
                    | CHOICE_LIST;

CHOICE_LIST         : CHOICE CHOICE_LIST
                    | GOTO;

CHOICE              : tchoice tbracket_curly_open tstring HEADER tbracket_curly_close;

GOTO                : tgoto LOCATION;

LOCATION_PREFIX      : tarrow_right |
                      LOCATION_PREFIX2;

LOCATION_PREFIX2     : |tarrow_left LOCATION_PREFIX2;

LOCATION_BODY        : tidentifier LOCATION_BODY
                     | tidentifier tarrow_left
                     | tidentifier tarrow_right;

LOCATION            : LOCATION_PREFIX LOCATION_BODY;