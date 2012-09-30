open Ogrillon

let () = 
  let root = Root.create ~plugin:"plugins.cfg" () in
  let rs = root#getRenderSystemByName "OpenGL Rendering Subsystem" in
  root#setRenderSystem rs ;
  root#delete

