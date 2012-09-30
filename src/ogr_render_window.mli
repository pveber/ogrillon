type obj = Ogr_base.obj

class t : obj -> object
  method add_viewport : Ogr_camera.t -> Ogr_viewport.t
  method obj : obj
end
