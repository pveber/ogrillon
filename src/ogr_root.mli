type obj = Ogr_base.obj

class t : obj -> object
  method create_scene_manager : Ogr_scene_manager.scene_type -> string -> Ogr_scene_manager.t
  method delete : unit
  method getRenderSystemByName : string -> Ogr_render_system.t
  method initialise : ?window_title:string -> unit -> Ogr_render_window.t
  method obj : obj
  method setRenderSystem : Ogr_render_system.t -> unit
end

val create : ?plugin:string -> ?config:string -> ?log:string -> unit -> t
