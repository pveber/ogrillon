type obj = Ogr_base.obj

external create_obj : string -> string -> string -> obj = "ogr_root_create"
external delete_obj : obj -> unit = "ogr_root_delete"
external getRenderSystemByName : obj -> string -> obj = "ogr_root_getRenderSystemByName"

class t obj = object
  method delete = delete_obj obj
  method getRenderSystemByName name = 
    new Ogr_render_system.t (getRenderSystemByName obj name)
end

let create ?(plugin = "") ?(config = "") ?(log = "ogrillon.log") () =
  new t (create_obj plugin config log)
