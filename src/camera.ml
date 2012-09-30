type obj = Base.obj

external look_at : obj -> float -> float -> float -> unit = "ogr_camera_look_at"
external set_aspect_ratio : obj -> float -> unit = "ogr_camera_set_aspect_ratio"
external set_near_clip_distance : obj -> float -> unit = "ogr_camera_set_near_clip_distance"
external set_position : obj -> float -> float -> float -> unit = "ogr_camera_set_position"

class t obj = 
object
  method look_at ~x ~y ~z = look_at obj x y z
  method obj : obj = obj
  method set_aspect_ratio r = set_aspect_ratio obj r
  method set_near_clip_distance d = set_near_clip_distance obj d
  method set_position ~x ~y ~z = set_position obj x y z
end
