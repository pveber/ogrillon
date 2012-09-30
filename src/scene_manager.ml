type scene_type = 
  | Generic
  | Exterior_close
  | Exterior_far
  | Exterior_real_far
  | Interior

type obj = Base.obj

external create_camera : obj -> string -> obj = "ogr_scene_manager_create_camera"
external create_entity_from_file : obj -> string -> string -> obj = "ogr_scene_manager_create_entity_from_file"

class t obj = object
  method create_camera name = 
    new Camera.t (create_camera obj name)
  method create_entity_from_file ~id ~path =
    new Entity.t (create_entity_from_file obj id path)
  method obj : obj = obj
end
