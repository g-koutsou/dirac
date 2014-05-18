#ifndef _GAUGE_FIELDS_H
#define _GAUGE_FIELDS_H 1
#include <defs.h>
gauge_field_sp * new_gauge_field_sp(lattice *);
gauge_field_dp * new_gauge_field_dp(lattice *);
void del_gauge_field_sp(gauge_field_sp *);
void del_gauge_field_dp(gauge_field_dp *);
#endif /* _GAUGE_FIELDS_H */
