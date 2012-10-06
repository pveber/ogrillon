type obj = Base.obj

external set_material_name : obj -> string -> unit = "ogr_entity_set_material_name"

class t obj = 
object
  method obj : obj = obj
  method set_material_name name = set_material_name obj name
end
