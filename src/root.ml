type obj = Base.obj

external create_obj : string -> string -> string -> obj = "ogr_root_create"
external create_scene_manager : obj -> Scene_manager.scene_type -> string -> obj = "ogr_root_create_scene_manager"
external delete_obj : obj -> unit = "ogr_root_delete"
external get_render_system_by_name : obj -> string -> obj = "ogr_root_get_render_system_by_name"
external initialize : obj -> string -> obj = "ogr_root_initialise"
external set_render_system : obj -> obj -> unit = "ogr_root_set_render_system"

class t obj = object
  method create_scene_manager st name = 
    new Scene_manager.t (create_scene_manager obj st name)
  method delete = delete_obj obj
  method get_render_system_by_name name = 
    new Render_system.t (get_render_system_by_name obj name)
  method initialise ?(window_title = "Ogrillon Render Window") () = 
    new Render_window.t (initialize obj window_title)
  method obj : obj = obj
  method set_render_system (rs : Render_system.t) = set_render_system obj rs#obj
end

let create ?(plugin = "") ?(config = "") ?(log = "ogrillon.log") () =
  new t (create_obj plugin config log)
