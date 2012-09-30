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

#include<OgreCamera.h>
#include "utils.h"

using namespace Ogre;

extern "C" CAMLprim value ogr_camera_look_at(value cam, value x, value y, value z)
{
  ((Camera*) cam)->lookAt(Vector3(Double_val(x),Double_val(y),Double_val(z)));
  return Val_unit;
}

extern "C" CAMLprim value ogr_camera_set_near_clip_distance(value cam, value d)
{
  ((Camera*) cam)->setNearClipDistance(Double_val(d));
  return Val_unit;
}

extern "C" CAMLprim value ogr_camera_set_position(value cam, value x, value y, value z)
{
  ((Camera*) cam)->setPosition(Vector3(Double_val(x),Double_val(y),Double_val(z)));
  return Val_unit;
}

extern "C" CAMLprim value ogr_camera_set_aspect_ratio(value cam, value r)
{
  ((Camera*) cam)->setAspectRatio(Double_val(r));
  return Val_unit;
}
