type scene_type = 
  | Generic
  | Exterior_close
  | Exterior_far
  | Exterior_real_far
  | Interior

type obj = Base.obj

class t : obj -> object
  method create_camera : string -> Camera.t
  method obj : obj
end