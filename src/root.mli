type obj = Base.obj

class t : obj -> object
  method add_resource_location : path:string -> kind:[`FileSystem|`Zip] -> group:string -> unit
  method create_scene_manager : Scene_manager.scene_type -> string -> Scene_manager.t
  method delete : unit
  method get_render_system_by_name : string -> Render_system.t
  method initialise : ?window_title:string -> unit -> Render_window.t
  method obj : obj
  method render_one_frame : unit
  method set_render_system : Render_system.t -> unit
end

val create : ?plugin:string -> ?config:string -> ?log:string -> unit -> t
