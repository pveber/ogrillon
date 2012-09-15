(* OASIS_START *)
(* OASIS_STOP *)

open Ocamlbuild_plugin

let ( & ) f x = f x

let env = BaseEnvLight.load ()

let cpp_compiler_var = "g++ -fPIC"

let cpp_compiler = S [Sh cpp_compiler_var; A "-I"; Sh "`ocamlc -where`"]

let ccopt = S [A "-I"; P "/usr/include/OGRE"]

let rule_o_of_cpp () =
  let deps = "%.cpp" :: [] and prod = "%.o" in
  let action env _ = Cmd (S [cpp_compiler; ccopt; A "-c"; P (env "%.cpp"); A "-o"; P (env "%.o")]) in
  rule "o_of_cpp" ~deps ~prod action

let () = dispatch & fun h ->
  dispatch_default h;
  match h with
  | Before_rules ->
      rule_o_of_cpp ();
      flag ["doc"; "extension:mli"] (A "-hide-warnings")
  | _ -> ()
