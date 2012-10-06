type obj = Base.obj

external set_position : obj -> float -> float -> float -> unit = "ogr_light_set_position"

class t obj = 
object
  method obj : obj = obj
  method set_position ~x ~y ~z = set_position obj x y z
end
