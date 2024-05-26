%option noyywrap
%option noinput
%option nounput

%{
#include "parser.tab.h"
%}

/* Regular Definitions */


/* Identifiers: starts with an alphabetic letter followed by any number of alphabetic letters and digits */
tID  [a-zA-Z]([a-zA-Z]|[0-9])* 

/* Comments */ 
tSINGLELINECOMMENT (\/\/.*)                    
tMULTILINECOMMENT "/*"([^*]*|\*+[^/*])*"*/"    

/*KEYWORD*/
tIF if
tELSE else
tWHILE while
tPRINT print
tRETURN return
tINT int
tVOID void
tMAIN main
tCONST const

/*SYMBOLS*/
tADD "+"
tSUB "-"
tMUL "*"
tDIV "/"
tLT "<"
tGT ">"
tNE "!="
tEQ "=="
tGE ">="
tLE "<="
tASSIGN "="
tAND "&&"
tOR "||"
tNOT "!"
tLBRACE "{"
tRBRACE "}"
tLPAR "("
tRPAR ")"
tSEMI ";"
tCOMMA ","

%%

([0-9][0-9]*)      	                        {printf( "tNB: '%s[0x%x]'\n", yytext,atoi(yytext)); yylval.nb = atoi(yytext); return tNB;}
(0x([0-9]|[a-f]|[A-F])([0-9]|[a-f])*)    	{printf( "tNB: '%ld[%s]'\n", strtol(yytext, NULL, 16) ,yytext); yylval.nb = strtol(yytext, NULL, 16) ; return tNB;}

{tSINGLELINECOMMENT}  
{tMULTILINECOMMENT} 

{tVOID}   		{printf("tVOID\n");return tVOID;}
{tIF}           {printf("tIF\n");return tIF;}
{tELSE}      	{printf("tELSE\n");return tELSE;}
{tWHILE}      	{printf("tWHILE\n");return tWHILE;}
{tPRINT}      	{printf("tPRINT\n");return tPRINT;}
{tRETURN}      	{printf("tRETURN\n");return tRETURN;}
{tINT}      	{printf("tINT\n");return tINT;}
{tMAIN}   	    {printf("tMAIN\n");return tMAIN;}
{tCONST}   	    {printf("tCONST\n");return tCONST;}


{tADD}      	{printf("tADD\n");return tADD;}
{tSUB}      	{printf("tSUB\n");return tSUB;}
{tMUL}      	{printf("tMUL\n");return tMUL;}
{tDIV}      	{printf("tDIV\n");return tDIV;}
{tLT}      	    {printf("tLT\n");return tLT;}
{tGT}      	    {printf("tGT\n");return tGT;}
{tNE}      	    {printf("tNE\n");return tNE;}
{tEQ}      	    {printf("tEQ\n");return tEQ;}
{tGE}      	    {printf("tGE\n");return tGE;}
{tLE}      	    {printf("tLE\n");return tLE;}
{tASSIGN}      	{printf("tASSIGN\n");return tASSIGN;}
{tAND}      	{printf("tAND\n");return tAND;}
{tOR}      	    {printf("tOR\n");return tOR;}
{tNOT}      	{printf("tNOT\n");return tNOT;}
{tLBRACE}      	{printf("tLBRACE\n");return tLBRACE;}
{tRBRACE}      	{printf("tRBRACE\n");return tRBRACE;}
{tLPAR}      	{printf("tLPAR\n");return tLPAR;}
{tRPAR}      	{printf("tRPAR\n");return tRPAR;}
{tSEMI}      	{printf("tSEMI\n");return tSEMI;}
{tCOMMA}      	{printf("tCOMMA\n");return tCOMMA;}

{tID}   	    {printf( ": '%s'\n", yytext); yylval.var = strdup(yytext); return tID;}

[ \r\t\n]+    	{/* Ignores whitespaces */}

.  	        	{printf("tERROR\n");};

