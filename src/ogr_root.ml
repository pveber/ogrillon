type obj = Ogr_base.obj

class t obj = object
  method delete = delete_obj obj
end


external create_obj : string -> string -> string -> obj = "ogr_root_create"
external delete_obj : obj -> unit = "ogr_root_delete"

let create ?(plugin = "") ?(config = "") ?(log = "ogrillon.log") () =
  let obj = create_obj plugin config log in
  object
    inherit t obj
    initializer
      Gc.finalise delete_obj obj
  end
