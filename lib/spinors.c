#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <defs.h>
#include <precision.h>

PR(spinor_field) *
PR(new_spinor_field)(lattice *lat)
{
  int *dims = lat->dims;
  int vol = 1;
  for(int i=0; i<ND; i++)
    vol *= dims[i];
  PR(spinor_field) *ptr;
  assert((ptr = malloc(sizeof(PR(spinor_field))))!=NULL);
  if(ptr == NULL) {
    fprintf(stderr, " malloc() returned NULL in %s\n", __func__);
    exit(-1);
  }
  assert((ptr->s = malloc(NC*NS*sizeof(qComplex)*vol))!=NULL);
  if(ptr->s == NULL) {
    fprintf(stderr, " malloc() returned NULL in %s\n", __func__);
    exit(-1);
  }
  ptr->L = lat;
  return ptr;
}

void
PR(del_spinor_field)(PR(spinor_field) *ptr)
{
  free(ptr->s);
  free(ptr);
  return;
}

PR(half_spinor_field) *
PR(new_half_spinor_field)(lattice *lat)
{
  int *dims = lat->dims;
  int vol = 1;
  for(int i=0; i<ND; i++)
    vol *= dims[i];
  PR(half_spinor_field) *ptr;
  assert((ptr = malloc(sizeof(PR(half_spinor_field))))!=NULL);
  if(ptr == NULL) {
    fprintf(stderr, " malloc() returned NULL in %s\n", __func__);
    exit(-1);
  }
  assert((ptr->s = malloc(NC*NS/2*sizeof(qComplex)*vol))!=NULL);
  if(ptr->s == NULL) {
    fprintf(stderr, " malloc() returned NULL in %s\n", __func__);
    exit(-1);
  }
  ptr->L = lat;
  return ptr;
}

void
PR(del_half_spinor_field)(PR(half_spinor_field) *ptr)
{
  free(ptr->s);
  free(ptr);
  return;
}
