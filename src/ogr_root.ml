type obj = Ogr_base.obj

class root obj = object
end


external create_root : string -> string -> string -> obj = "ogr_create_root"
  
let create_root ?(plugin = "") ?(config = "") ?(log = "ogrillon.log") () =
  let obj = create_root plugin config log in
  object
    inherit root obj
  end
