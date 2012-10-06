open Ogrillon

let () = 
  let root = Root.create ~plugin:"/usr/share/OGRE-1.7.4/plugins.cfg" () in
  root#add_resource_location ~path:"media/models" ~group:"General" ~kind:`FileSystem ;
  root#add_resource_location ~path:"media/materials/scripts" ~group:"General" ~kind:`FileSystem ;
  root#add_resource_location ~path:"media/materials/textures" ~group:"General" ~kind:`FileSystem ;
  let rs = root#get_render_system_by_name "OpenGL Rendering Subsystem" in
  rs#set_config_option "Full Screen" "No" ;
  rs#set_config_option "VSync" "No" ;
  rs#set_config_option "Video Mode" "800 x 600 @ 32-bit" ;
  root#set_render_system rs ;
  let rw = root#initialise ~window_title:"Ogrillon test" () in
  let sm = root#create_scene_manager Scene_manager.Exterior_close "Default Scene Manager" in
  let cam = sm#create_camera "PlayerCam" in
  cam#look_at ~x:0. ~y:0. ~z:(-300.) ;
  cam#set_position ~x:0. ~y:0. ~z:80. ;
  cam#set_near_clip_distance 5. ;
  let vp = rw#add_viewport cam in
  vp#set_background_color ~r:0. ~g:0. ~b:0. ;
  cam#set_aspect_ratio (vp#get_actual_width /. vp#get_actual_height) ;
  let ogre_head = sm#create_entity_from_file ~id:"Head" ~path:"ogrehead.mesh" in
  let head_node = sm#get_root_scene_node#create_child_scene_node ~translate:(1.,0.,0.) () in
  head_node#attach_object ogre_head ;
  root#delete

