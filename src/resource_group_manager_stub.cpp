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

#include<OgreResourceGroupManager.h> 
#include "utils.h"

using namespace Ogre;

extern "C" CAMLprim value ogr_resource_group_manager_get_singleton(value unit)
{
  return (value) &(ResourceGroupManager::getSingleton());
}

extern "C" CAMLprim value ogr_resource_group_manager_initialise_all_resource_groups(value rgm)
{
  ((ResourceGroupManager*) rgm)->initialiseAllResourceGroups();
  return Val_unit;
}
