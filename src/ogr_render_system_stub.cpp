/* Caml headers */
extern "C" {
#include<caml/mlvalues.h>
#include<caml/memory.h>
#include<caml/callback.h>
#include<caml/fail.h>
#include<caml/alloc.h>
#include<caml/misc.h>
}

#include <OgreRenderSystem.h>
#include "utils.h"

using namespace Ogre;

extern "C" CAMLprim value ogr_render_system_set_config_option(value rs, value key, value val) {
  ((RenderSystem*) rs)->setConfigOption(String_val(key), String_val(val));
  return Val_unit;
}
