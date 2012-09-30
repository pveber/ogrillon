type scene_type = 
  | Generic
  | Exterior_close
  | Exterior_far
  | Exterior_real_far
  | Interior

type obj = Ogr_base.obj

class t obj = object
  method obj : obj = obj
end
