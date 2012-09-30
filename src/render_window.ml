type obj = Base.obj

external add_viewport : obj -> obj -> obj = "ogr_render_window_add_viewport"

class t obj =
object
  method add_viewport (cam : Camera.t) = 
    new Viewport.t (add_viewport obj cam#obj)
  method obj : obj = obj
end
