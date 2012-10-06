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

#include<OgreEntity.h> 
#include "utils.h"

using namespace Ogre;

extern "C" CAMLprim value ogr_entity_set_material_name(value e, value name)
{
  ((Entity*) e)->setMaterialName(String_val(name));
  return Val_unit;
}
