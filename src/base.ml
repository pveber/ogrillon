type obj

exception Null_pointer_exn

external demo : unit -> unit = "ogrillon_demo"

let () = Callback.register_exception "Null_pointer_exn" Null_pointer_exn
