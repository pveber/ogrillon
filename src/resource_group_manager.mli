type obj = Base.obj

class t : obj -> 
object
  method initialise_all_resource_groups : unit
  method obj : obj
end

val get : unit -> t
