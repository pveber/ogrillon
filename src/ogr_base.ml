type obj

exception Null_pointer_exn

let () = Callback.register_exception "Null_pointer_exn" Null_pointer_exn

external delete : obj -> unit = "ogr_delete"
