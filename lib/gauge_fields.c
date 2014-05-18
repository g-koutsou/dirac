#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <defs.h>
#include <precision.h>

PR(gauge_field) *
PR(new_gauge_field)(lattice *lat)
{
  int *dims = lat->dims;
  int vol = 1;
  for(int i=0; i<ND; i++)
    vol *= dims[i];
  PR(gauge_field) *ptr;
  assert((ptr = malloc(sizeof(PR(gauge_field))))!=NULL);
  assert((ptr->u = malloc(NC*NC*ND*sizeof(qComplex)*vol))!=NULL);
  ptr->L = lat;
  return ptr;
}

void
PR(del_gauge_field)(PR(gauge_field) *ptr)
{
  free(ptr->u);
  free(ptr);
  return;
}
