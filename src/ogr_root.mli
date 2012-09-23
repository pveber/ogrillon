type obj = Ogr_base.obj

class t : obj -> object
  method getRenderSystemByName : string -> Ogr_render_system.t
  method delete : unit
end

val create : ?plugin:string -> ?config:string -> ?log:string -> unit -> t
