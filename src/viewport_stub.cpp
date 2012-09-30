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

#include<OgreViewport.h>
#include "utils.h"

using namespace Ogre;

extern "C" CAMLprim value ogr_viewport_set_background_color(value vp, value r, value g, value b)
{
  ((Viewport*) vp)->setBackgroundColour(ColourValue(Double_val(r),Double_val(g),Double_val(b)));
  return Val_unit;
}
