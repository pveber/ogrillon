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
#include "ogr_scene_manager_stub.h"

using namespace Ogre;

SceneTypeMask sceneTypeMask(value scene_type) {
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

