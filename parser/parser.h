#ifndef _PARSER_H
#define _PARSER_H 1
void parser_init(char fname[]);
void parser_finalize();
char *parser_parse(char *);
#endif /* _PARSER_H */
