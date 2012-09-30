type obj = Ogr_base.obj

class t : obj -> object
  method obj : obj
  method set_config_option : string -> string -> unit
end
