type obj = Base.obj

external setConfigOption : obj -> string -> string -> unit = "ogr_render_system_set_config_option"

class t obj = 
object
  method obj : obj = obj
  method set_config_option key value = 
    setConfigOption obj key value
end
