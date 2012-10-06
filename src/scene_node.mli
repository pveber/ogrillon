type obj = Base.obj

class t : obj -> 
object
  method attach_object : #Movable_object.t -> unit
  method create_child_scene_node : 
    ?translate:float * float * float -> 
    ?quaternion:float * float * float * float -> 
    unit -> t
  method obj : obj
end
