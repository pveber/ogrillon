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

extern "C" CAMLprim value ogr_root_create(value plugin, value config, value log) {
  Root* r = new Root(String_val(plugin),String_val(config),String_val(log));
  return (value) r;
}

extern "C" CAMLprim value ogr_root_delete(value obj) {
  delete (Root *) obj;
  return Val_unit;
}

extern "C" CAMLprim value ogr_root_getRenderSystemByName(value root, value name) {
  RenderSystem* r = ((Root*) root)->getRenderSystemByName(String_val(name));
  if(r == NULL) printf("biq\n");
  return (value) r;
}

extern "C" CAMLprim value ogr_root_setRenderSystem(value root, value rs) {
  ((Root*) root)->setRenderSystem((RenderSystem *) rs);
  return Val_unit;
}
