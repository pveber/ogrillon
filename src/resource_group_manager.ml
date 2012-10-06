type obj = Base.obj

external get_singleton : unit -> obj = "ogr_resource_group_manager_get_singleton"
external initialise_all_resource_groups : obj -> unit = "ogr_resource_group_manager_initialise_all_resource_groups"

class t obj = 
object
  method initialise_all_resource_groups = initialise_all_resource_groups obj
  method obj : obj = obj
end

let get () = new t (get_singleton ())
