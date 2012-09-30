type obj = Ogr_base.obj

external add_viewport : obj -> obj -> obj = "ogr_render_window_add_viewport"

class t obj =
object
  method add_viewport (cam : Ogr_camera.t) = 
    new Ogr_viewport.t (add_viewport obj cam#obj)
  method obj : obj = obj
end
