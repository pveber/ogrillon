type obj = Base.obj

class t : obj -> 
object
  method look_at : x:float -> y:float -> z:float -> unit
  method obj : obj
  method set_aspect_ratio : float -> unit
  method set_near_clip_distance : float -> unit
  method set_position : x:float -> y:float -> z:float -> unit
end
