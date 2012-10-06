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

#include<OgreWindowEventUtilities.h> 
#include "utils.h"

using namespace Ogre;

extern "C" CAMLprim value ogr_window_event_utilities_message_pump(value unit)
{
  WindowEventUtilities::messagePump();
  return Val_unit;
}
