type obj = Base.obj

class t : obj -> object
  method add_viewport : Camera.t -> Viewport.t
  method obj : obj
end
