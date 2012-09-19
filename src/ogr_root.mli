type obj = Ogr_base.obj

class root : obj -> object
end

val create_root : ?plugin:string -> ?config:string -> ?log:string -> unit -> root
