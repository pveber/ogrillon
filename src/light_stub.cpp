/* Caml headers */
extern "C" {
#include<caml/mlvalues.h>
#include<caml/memory.h>
#include<caml/callback.h>
#include<caml/fail.h>
#include<caml/alloc.h>
#include<caml/misc.h>
#include<assert.h>
}

#include<OgreLight.h> 
#include "utils.h"

using namespace Ogre;

extern "C" CAMLprim value ogr_light_set_position(value light, value x, value y, value z)
{
  ((Light*) light)->setPosition(Double_val(x),Double_val(y),Double_val(z));
  return Val_unit;
}
