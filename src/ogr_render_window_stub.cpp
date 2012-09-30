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
#include<OgreRenderWindow.h>
#include "utils.h"

using namespace Ogre;

extern "C" CAMLprim value ogr_render_window_add_viewport(value rw, value cam)
{
  if((RenderWindow*) rw == NULL || (Camera*) cam == NULL) null_pointer_exn();
  Viewport* vp = ((RenderWindow*) rw)->addViewport((Camera*) cam);
  return (value) vp;
}
