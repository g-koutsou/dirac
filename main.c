#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <parser.h>
#include <defs.h>
#include <spinors.h>
#include <gauge_fields.h>
#include <random_gauge_field.h>
#include <lattice.h>
#include <plaquette.h>

#define MAX_STRING 256
enum {
  CONF_READ,
  CONF_RAND
} conf_type;

void
usage(char *argv[])
{
  fprintf(stderr, "Usage: %s PARAM_FILE\n", argv[0]);
  return;
}

int
main(int argc, char *argv[])
{
  /* check and parse command line arguments */
  if(argc != 2) {
      usage(argv);
      exit(1);
  }

  /* parse parameter (input) file */
  parser_init(argv[1]);
  int dim[ND];
  if(sscanf(parser_parse("Dimensions"), "%d %d %d %d", dim, dim+1, dim+2, dim+3)!=ND) {
    fprintf(stderr, "error parsing for %s\n", "Dimensions");
    exit(1);
  }
  char aux_str[MAX_STRING];
  if(sscanf(parser_parse("Configuration"), "%s", aux_str)!=1) {
    fprintf(stderr, "error parsing for %s\n", "Configuration");
    exit(1);
  }
  if(strcmp(aux_str, "read")==0) {
    conf_type = CONF_READ;
  } else if(strcmp(aux_str, "random")==0) {
    conf_type = CONF_RAND;
  } else {
    fprintf(stderr, "\"Configuration\" parameter should be one of: ");
    fprintf(stderr, "%s, ", "read");
    fprintf(stderr, "%s\n", "random");
    exit(1);
  }
  
  char config_name[MAX_STRING];
  switch(conf_type) {
  case CONF_RAND:
    break;
  case CONF_READ:
    if(sscanf(parser_parse("Configuration file name"), "%s", config_name)!=1) {
      fprintf(stderr, "error parsing for %s\n", "Configuration file name");
      exit(1);
    }    
    break;
  }

  parser_finalize();
  lattice *lat = new_lattice(dim);
  gauge_field_sp *U = new_gauge_field_sp(lat);
  spinor_field_sp *psi = new_spinor_field_sp(lat);
  switch(conf_type) {
  case CONF_RAND:
    random_gauge_field_sp(U);
    break;
  case CONF_READ:
    random_gauge_field_sp(U);
    break;
  }
  printf(" Plaquette = %lf\n", plaquette_sp(U));
  del_lattice(lat);
  del_spinor_field_sp(psi);
  del_gauge_field_sp(U);
  return 0;
}
