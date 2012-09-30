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
#include "utils.h"
#include "scene_manager_stub.h"

using namespace Ogre;

extern "C" CAMLprim value ogr_root_create(value plugin, value config, value log) {
  Root* r = new Root(String_val(plugin),String_val(config),String_val(log));
  if(r == NULL) null_pointer_exn();
  return (value) r;
}

extern "C" CAMLprim value ogr_root_delete(value obj) {
  Root* r = (Root *) obj;
  if(r == NULL) null_pointer_exn();
  delete r;
  return Val_unit;
}

extern "C" CAMLprim value ogr_root_get_render_system_by_name(value root, value name) {
  RenderSystem* rs = ((Root*) root)->getRenderSystemByName(String_val(name));
  if(rs == NULL) null_pointer_exn();
  return (value) rs;
}

extern "C" CAMLprim value ogr_root_set_render_system(value root, value rs) {
  ((Root*) root)->setRenderSystem((RenderSystem *) rs);
  return Val_unit;
}

extern "C" CAMLprim value ogr_root_initialise(value root, value window_title) {
  RenderWindow* rw = ((Root*) root)->initialise(true, String_val(window_title));
  return (value) rw;
}

extern "C" CAMLprim value ogr_root_create_scene_manager(value root, value scene_type, value name) 
{
  SceneManager* sm = ((Root *) root)->createSceneManager(sceneTypeMask(scene_type), String_val(name));
  return (value) sm;
}

extern "C" CAMLprim value ogr_root_add_resource_location(value root, value name, value kind, value group)
{
  ((Root *) root)->addResourceLocation(String_val(name), String_val(kind), String_val(group));
  return Val_unit;
}
