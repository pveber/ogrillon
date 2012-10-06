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

#include "utils.h"
#include "scene_manager_stub.h"

using namespace Ogre;

SceneTypeMask sceneTypeMask(value scene_type) 
{
  switch(Int_val(scene_type)) {
  case 0: return ST_GENERIC;
  case 1: return ST_EXTERIOR_CLOSE;
  case 2: return ST_EXTERIOR_FAR;
  case 3: return ST_EXTERIOR_REAL_FAR;
  case 4: return ST_INTERIOR;
  default: 
    printf("sceneTypeMask: unknown variant tag %d\n", Int_val(scene_type));
    assert(false);
  }
}

extern "C" CAMLprim value ogr_scene_manager_create_camera(value sm, value name)
{
  Camera* c = ((SceneManager*) sm)->createCamera(String_val(name));
  return (value) c;
}

extern "C" CAMLprim value ogr_scene_manager_create_entity_from_file(value sm, value name, value filename)
{
  Entity* e = ((SceneManager*) sm)->createEntity(String_val(name), String_val(filename));
  return (value) e;
}

extern "C" CAMLprim value ogr_scene_manager_get_root_scene_node(value sm)
{
  SceneNode* e = ((SceneManager*) sm)->getRootSceneNode();
  return (value) e;
}

extern "C" CAMLprim value ogr_scene_manager_set_ambient_light(value sm, value r, value g, value b)
{
  ((SceneManager*) sm)->setAmbientLight(ColourValue(Double_val(r), Double_val(g), Double_val(b)));
  return Val_unit;
}
