
%{
    //Custom code goes here    
    #include "parseNode.h"
    typedef std::vector<Choice> ChoiceVector;
%}

//Terminal symbols
%token <std::string> teof
%token <std::string> terror
%token <std::string> tdiv
%token <std::string> tbracket_curly_open
%token <std::string> tbracket_curly_close
%token <std::string> tbracket_square_open
%token <std::string> tbracket_square_close
%token <std::string> tscene
%token <std::string> tidentifier
%token <std::string> tstring
%token <std::string> tignore
%token <std::string> tchoice
%token <std::string> tgoto
%token <std::string> tfullstop



%type <Section> S
%type <Section> SECTION
%type <Section> SECTION_DECLARATION
%type <String>  HEADER
%type <Scene>   SCENE
%type <Scene>   SCENE_DECLARATION
%type <Scene>   SCENE_POSTHEADER
%type <ChoiceVector>   CHOICE_LIST
%type <Choice>  CHOICE
%type <Destination> GOTO
%type <Destination> LOCATION            
%type <Destination> LOCATION_PREFIX     
%type <int>         LOCATION_PREFIX_LEFT
%type <Destination> LOCATION_BODY

%%

S                   : SECTION teof { $$ = $1; };


SECTION             : { $$ = Section(); }
                     | SECTION_DECLARATION SECTION { $$ = $2; $$.add($1); }
                     | SCENE_DECLARATION SECTION {  }

SECTION_DECLARATION : tidentifier tbracket_square_open SECTION tbracket_square_close { $$ = $3; $$.name($1); };

SCENE_DECLARATION   :tscene tidentifier tbracket_curly_open SCENE tbracket_curly_close { $$ = $4; $$.name($2); };

SCENE               : HEADER SCENE_POSTHEADER { $$ = $2; $$.header($1); };

SCENE_POSTHEADER    : { $$ = Scene(); }
                      | CHOICE_LIST { $$ = Scene($1); }
                      | GOTO { $$ = Scene($1); };

HEADER              : tstring { $$ = Header($1); }
                    | tstring tstring { $$ = Header($1, $2); };

CHOICE_LIST         : { $$={}; }
                    | CHOICE_LIST CHOICE { $$ = {$2}; $$.insert($$.end(), $1.begin(), $1.end()); };

CHOICE              : tchoice tbracket_curly_open HEADER GOTO tbracket_curly_close { $$ = Choice($3, $4); };

GOTO                : tgoto LOCATION { $$ = $2; };

LOCATION            : LOCATION_PREFIX LOCATION_BODY { $$ = $2; $$.backsteps($1.backsteps()); $$.relative($1.relative()); };

LOCATION_PREFIX      : { $$ = Destination(0, true); }
                     | tdiv                      { $$ = Destination(0 , false); }
                     | LOCATION_PREFIX_LEFT      { $$ = Destination($1, true); }
                     | LOCATION_PREFIX_LEFT tdiv { $$ = Destination($1, true); };

LOCATION_PREFIX_LEFT : { $$=0; }
                     | LOCATION_PREFIX_LEFT tfullstop { $$ = $1+1; }; //Not sure if the EMPTY is needed here

LOCATION_BODY        : LOCATION_BODY tdiv tidentifier { $$ = Destination($1, $3); }
                     | tidentifier { $$ = Destination($1); };
