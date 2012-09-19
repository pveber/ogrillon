/* Caml headers */
extern "C" {
#include<caml/mlvalues.h>
#include<caml/memory.h>
#include<caml/callback.h>
#include<caml/fail.h>
#include<caml/alloc.h>
#include<caml/misc.h>
}

#include <OgreRoot.h>

using namespace Ogre;

extern "C" CAMLprim value ogr_create_root(value plugin, value config, value log) {
  Root* r = new Root("","","");
  return (value) r;
}
