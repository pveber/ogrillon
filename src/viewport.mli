type obj = Base.obj

class t : obj -> 
object
  method get_actual_width : float
  method get_actual_height : float
  method obj : obj
  method set_background_color : r:float -> g:float -> b:float -> unit
end
