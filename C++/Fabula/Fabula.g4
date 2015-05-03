grammar Fabula ;

prog: sectionContent EOF ;

sectionContent : (section | scene)* ;
section : IDENTIFIER '[' sectionContent ']' ;

scene : 'scene' IDENTIFIER '{' STRING* choicelist? '}' ;
sceneContent : IDENTIFIER ;

STRING : (('"' (~('"') | '\\"')* '"')
	   | ('\'' (~('\'') | '\\\'')* '\'') )+ ;

choicelist : (choice)+ ;
choice : CHOICE STRING ((choicerhs) | '{' choicerhs '}') ;

CHOICE : 'choice';
choicerhs : STRING? GOTO sceneLocation ;

sceneLocation : IDENTIFIER (ARROW IDENTIFIER)* ;

ARROW : '->';

GOTO : 'goto';

LINECOMMENT : '//' (~('\n'))* -> skip ;
BLOCKCOMMENT : '/*' .*? '*/' -> skip;

IDENTIFIER : [a-zA-Z_]+ ([0-9] | [a-zA-Z_])* ;
WHITESPACE : ('\n' | ' ' | '\t')+ -> skip ;



//Note: LEXER can't use other LEXER tokens to define tokens. One can use "fragment" keyworded tokens though.
//Put ^ when you want to ignore parser-generated tokens.
//Include statements should be handled by a preprocessor.
//This would also allow #define's!

/*
Milestone 1:

Beginning
[
	scene Start
	{
		"Left, or Right? That is the header."
		

		choice "Go right"
		{
			"You have decided to go right, in your infinite wisdom!"
			goto mIDdlE
		}
		choice "Go left"
			"Your wish to turn right!"
			goto Finish->End
	}

	scene Middle
	{
		"You find yourself in the middle. The middle of what?
		You don't know, but you sure know that there's no newline here!<br> One here though."

		choice "Stay here"
		{
			"Too lazy to move... XL"
			goto Middle
		}
	}
]

Finish
[
	scene End
	{
		"Well, you reached the end of your journey :p Such \"fun!\""
	}
]


Milestone 2:

//Variable rules:
//new var = 4 //declares a new var. If it was seen before, it is overwritten.
//static var = 5 //Initialises it once, and acts as a declaration after that.

Beginning
[
	scene Start
	{
		"Left, or Right? That is the header."
		<<test.txt>> //Include. Include should not affect comments.

		choice "Go right"
			"You have decided to go right, in your infinite wisdom!"
			goto mIDdlE
		
		choice "Go left"
			"Your wish to turn right!";
			goto Finish->End;
	}

	scene Middle
	{
		"You find yourself in the middle. The middle of what?
		You don't know, but you sure know that there's no newline here!<br> One here though."

		choice "Stay here"
		{
			"Too lazy to move... XL"
			goto Middle;
		}
	}
]

Finish
[
	scene End
	{
		("Well, you reached the end of your journey :p It took you %% turns! Such \"fun!\"", nturns)
		"Or even more " nturns+1 "fun!"
	}
]
*/