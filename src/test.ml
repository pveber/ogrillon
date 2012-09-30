open Ogrillon

let () = 
  let root = Root.create ~plugin:"plugins.cfg" () in
  let rs = root#getRenderSystemByName "OpenGL Rendering Subsystem" in
  rs#set_config_option "Full Screen" "No" ;
  rs#set_config_option "VSync" "No" ;
  rs#set_config_option "Video Mode" "800 x 600 @ 32-bit" ;
  root#setRenderSystem rs ;
  let rw = root#initialise ~window_title:"Ogrillon test" () in
  root#delete

