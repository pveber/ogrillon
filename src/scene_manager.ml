type scene_type = 
  | Generic
  | Exterior_close
  | Exterior_far
  | Exterior_real_far
  | Interior

type obj = Base.obj

external create_camera : obj -> string -> obj = "ogr_scene_manager_create_camera"

class t obj = object
  method create_camera name = 
    new Camera.t (create_camera obj name)
  method obj : obj = obj
end
