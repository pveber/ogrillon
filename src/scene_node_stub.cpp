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

#include<OgreSceneNode.h> 
#include "utils.h"

using namespace Ogre;

extern "C" CAMLprim value ogr_scene_node_create_child_scene_node(value sn_val, value translate_val, value quaternion_val)
{
  SceneNode* sn = (SceneNode*) sn_val;
  const Vector3& translate = translate_val == Val_int(0) ? Vector3::ZERO : Vector3(Double_field(Field(translate_val,0),0), 
										   Double_field(Field(translate_val,0),1),
										   Double_field(Field(translate_val,0),2)) ;
  const Quaternion& quaternion = quaternion_val == Val_int(0) ? Quaternion::IDENTITY : Quaternion(Double_field(Field(quaternion_val,0),0),
												  Double_field(Field(quaternion_val,0),1),
												  Double_field(Field(quaternion_val,0),2),
												  Double_field(Field(quaternion_val,0),3));
  SceneNode* e = sn->createChildSceneNode(translate,quaternion);
  return (value) e;
}

extern "C" CAMLprim value ogr_scene_node_attach_object(value sn, value mo)
{
  ((SceneNode*) sn)->attachObject((MovableObject*) mo);
  return Val_unit;
}
