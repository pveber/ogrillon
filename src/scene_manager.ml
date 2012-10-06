type scene_type = 
  | Generic
  | Exterior_close
  | Exterior_far
  | Exterior_real_far
  | Interior

type obj = Base.obj

external create_camera : obj -> string -> obj = "ogr_scene_manager_create_camera"
external create_entity_from_file : obj -> string -> string -> obj = "ogr_scene_manager_create_entity_from_file"
external get_root_scene_node : obj -> obj = "ogr_scene_manager_get_root_scene_node"
external set_ambient_light : obj -> float -> float -> float -> unit = "ogr_scene_manager_set_ambient_light"

class t obj = object
  method create_camera name = 
    new Camera.t (create_camera obj name)
  method create_entity_from_file ~id ~path =
    new Entity.t (create_entity_from_file obj id path)
  method get_root_scene_node =
    new Scene_node.t (get_root_scene_node obj)
  method obj : obj = obj
  method set_ambient_light ~r ~g ~b =
    set_ambient_light obj r g b
end
