#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <parser_errors.h>
#include <parser_defs.h>

static struct {
  int N;
  char **tokens;
  char **values;
} parser;

char *
trim(char *string, int N)
{
  while(string[0] == ' ') {
    for(int i=0; i<N-1; i++){
      string[i] = string[i+1];
    }
  }
  unsigned int idx = (unsigned int)(index(string,'\0')-string);
  while(string[idx-1] == ' ') {
    string[idx-1] = '\0';
    idx--;
  }  
  return string;
}

void 
parser_init(char fname[])
{
  FILE *fp = fopen(fname, "r");
  if(fp == NULL) {
    fprintf(stderr, "%s: file not found\n", fname);
    exit(PARSER_FILE_ERROR);
  }
  int nline = 1;
  int ntoken = 0;
  int syntax_bit = 0;
  do {
    int c = fgetc(fp);
    if( c == '=' )
      syntax_bit++;

    if( c == '#' ) {
      do {
	c = fgetc(fp);
      } while(c!='\n' && c!=EOF);
    }

    if( c == '\n' ) {
      if( syntax_bit == 1 ) {
	fprintf(stderr," %s: syntax error on line %d\n",fname,nline);
	exit(PARSER_PARSE_ERROR);
      }
      nline++;
    }

    if( c == ';' ) {
      syntax_bit--;
      ntoken++;
    }

    if(syntax_bit>1) {
      fprintf(stderr," %s: syntax error on line %d\n",fname,nline);
      exit(PARSER_PARSE_ERROR);
    }
  }while(!feof(fp));

  if(syntax_bit!=0) {
    fprintf(stderr," %s: syntax error on line %d\n",fname,nline);
    exit(PARSER_PARSE_ERROR);
  }

  parser.N = ntoken;
  parser.tokens = calloc(parser.N,sizeof(char*));
  parser.values = calloc(parser.N,sizeof(char*));
  for(int i=0; i<parser.N; i++) {
      parser.tokens[i] = calloc(PARSER_MAX_STRING,sizeof(char));
      parser.values[i] = calloc(PARSER_MAX_STRING,sizeof(char));
  }
  rewind(fp);
  char line[PARSER_MAX_STRING];
  nline = 1;
  ntoken = 0;
  do{
    fgets(line,PARSER_MAX_STRING,fp);
    if(index(line,'#') != NULL) {
      int idx = (unsigned int)(index(line,'#')-line);
      line[idx] = '\n';
      for(int i=idx+1; i<sizeof(line); i++)
	line[i] = '\0';
    }
    int end = 0;
    while(!end) {
      if(index(line,'=') != NULL) {
	size_t n = 0;
	n = (size_t)(index(line,'=') - line);
	if((int)n <= 0) {
	  fprintf(stderr," %s: syntax error on line %d\n",fname,nline);
	  exit(PARSER_PARSE_ERROR);	
	}
	strncpy(parser.tokens[ntoken],line,n);
	parser.tokens[ntoken] = trim(parser.tokens[ntoken],PARSER_MAX_STRING);
	char *idx = index(line,'=')+1;
	n = (size_t)(index(idx,';') - idx);
	if((int)n <= 0) {
	  fprintf(stderr," %s: syntax error on line %d\n",fname,nline);
	  exit(PARSER_PARSE_ERROR);	
	}
	strncpy(parser.values[ntoken],idx,n);
	parser.values[ntoken] = trim(parser.values[ntoken],PARSER_MAX_STRING);
	ntoken++;
	strcpy(&(line[0]),index(line,';')+1);
      } else {
	/* is this an empty line? */
	int bool = 0;
	for(int i=0; line[i]!='\n'&&line[i]!='\0'; i++) {
	  if(line[i]!=' ')
	    bool = 1;
	}
	if(bool) {
	  fprintf(stderr," %s: syntax error on line %d\n",fname,nline);
	  exit(PARSER_PARSE_ERROR);
	}
	end = 1;
      }
    }
    nline++;
  } while(!feof(fp));
  fclose(fp);
  return;
}

void 
parser_finalize()
{
  for(int i=0; i<parser.N; i++)
    {
      free(parser.tokens[i]);
      free(parser.values[i]);
    }
  free(parser.tokens);
  free(parser.values);
  return;
}

char *
parser_parse(char *token)
{
  int found = 0;
  char *out = NULL;
  for(int i=0; i<parser.N; i++) {
      if(strcmp(parser.tokens[i],token)==0) {
	out = parser.values[i];
	found++;
      }
  }
  
  if(!found)  {
    fprintf(stderr," \"%s\": token not found in input params\n",token);
    exit(PARSER_PARSE_ERROR);
  } else if(found!=1) {
    fprintf(stderr," \"%s\": multiple entries found in input params\n",token);
    exit(PARSER_PARSE_ERROR);
  }
  
  return out;
}
