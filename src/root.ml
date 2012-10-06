type obj = Base.obj

external add_resource_location : obj -> string -> string -> string -> unit = "ogr_root_add_resource_location"
external create_obj : string -> string -> string -> obj = "ogr_root_create"
external create_scene_manager : obj -> Scene_manager.scene_type -> string -> obj = "ogr_root_create_scene_manager"
external delete_obj : obj -> unit = "ogr_root_delete"
external get_render_system_by_name : obj -> string -> obj = "ogr_root_get_render_system_by_name"
external initialize : obj -> string -> obj = "ogr_root_initialise"
external render_one_frame : obj -> unit = "ogr_root_render_one_frame"
external set_render_system : obj -> obj -> unit = "ogr_root_set_render_system"

let string_of_kind = function
  | `FileSystem -> "FileSystem"
  | `Zip -> "Zip"

class t obj = object
  method add_resource_location ~path ~(kind:[`FileSystem|`Zip]) ~group = 
    add_resource_location obj path (string_of_kind kind) group
  method create_scene_manager st name = 
    new Scene_manager.t (create_scene_manager obj st name)
  method delete = delete_obj obj
  method get_render_system_by_name name = 
    new Render_system.t (get_render_system_by_name obj name)
  method initialise ?(window_title = "Ogrillon Render Window") () = 
    new Render_window.t (initialize obj window_title)
  method obj : obj = obj
  method render_one_frame = render_one_frame obj
  method set_render_system (rs : Render_system.t) = set_render_system obj rs#obj
end

let create ?(plugin = "") ?(config = "") ?(log = "ogrillon.log") () =
  new t (create_obj plugin config log)
