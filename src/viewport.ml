type obj = Base.obj

external set_background_color : obj -> float -> float -> float -> unit = "ogr_viewport_set_background_color"
external get_actual_width : obj -> float = "ogr_viewport_get_actual_width"
external get_actual_height : obj -> float = "ogr_viewport_get_actual_height"

class t obj = 
object
  method get_actual_width = get_actual_width obj
  method get_actual_height = get_actual_height obj
  method obj : obj = obj
  method set_background_color ~r ~g ~b = set_background_color obj r g b
end
