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
  printf("%s\n",String_val(plugin));
  Root* r = new Root(String_val(plugin),String_val(config),String_val(log));
  return (value) r;
}
