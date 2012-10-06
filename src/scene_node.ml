type obj = Base.obj

external create_child_scene_node : 
  obj ->
  (float * float * float) option -> 
  (float * float * float * float) option -> 
  obj = "ogr_scene_node_create_child_scene_node"
external attach_object : obj -> obj -> unit = "ogr_scene_node_attach_object"

class t obj = 
object
  method attach_object : 'a. (#Movable_object.t as 'a) -> unit = fun mo ->
    attach_object obj mo#obj
  method create_child_scene_node ?translate ?quaternion () =
    new t (create_child_scene_node obj translate quaternion)
  method obj : obj = obj
end
