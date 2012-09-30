type obj = Base.obj

class t : obj -> object
  method create_scene_manager : Scene_manager.scene_type -> string -> Scene_manager.t
  method delete : unit
  method get_render_system_by_name : string -> Render_system.t
  method initialise : ?window_title:string -> unit -> Render_window.t
  method obj : obj
  method set_render_system : Render_system.t -> unit
end

val create : ?plugin:string -> ?config:string -> ?log:string -> unit -> t
