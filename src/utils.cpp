/* Caml headers */
extern "C" {
#include<caml/mlvalues.h>
#include<caml/memory.h>
#include<caml/callback.h>
#include<caml/fail.h>
#include<caml/alloc.h>
#include<caml/misc.h>
}

void null_pointer_exn() {
	static value*  e = NULL;
	if(e == NULL) {
		e = caml_named_value("Null_pointer_exn");
	}
	caml_raise_constant(*e);
}
