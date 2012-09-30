open Ogrillon

let () = 
  let root = Root.create ~plugin:"plugins.cfg" () in
  let rs = root#getRenderSystemByName "OpenGL Rendering Subsystem" in
  rs#set_config_option "Full Screen" "No" ;
  rs#set_config_option "VSync" "No" ;
  rs#set_config_option "Video Mode" "800 x 600 @ 32-bit" ;
  root#setRenderSystem rs ;
  let rw = root#initialise ~window_title:"Ogrillon test" () in
  let sm = root#create_scene_manager Ogr_scene_manager.Exterior_close "Default Scene Manager" in
  let cam = sm#create_camera "PlayerCam" in
  cam#look_at ~x:0. ~y:0. ~z:(-300.) ;
  cam#set_position ~x:0. ~y:0. ~z:80. ;
  cam#set_near_clip_distance 5. ;
  let vp = rw#add_viewport cam in
  root#delete

