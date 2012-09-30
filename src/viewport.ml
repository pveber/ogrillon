type obj = Base.obj

external set_background_color : obj -> float -> float -> float -> unit = "ogr_viewport_set_background_color"

class t obj = 
object
  method obj : obj = obj
  method set_background_color ~r ~g ~b = set_background_color obj r g b
end
